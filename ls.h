bool stringCompare( const string &left, const string &right ){
   for( string::const_iterator lit = left.begin(), rit = right.begin(); lit != left.end() && rit != right.end(); ++lit, ++rit )
      if( tolower( *lit ) < tolower( *rit ) )
         return true;
      else if( tolower( *lit ) > tolower( *rit ) )
         return false;
   if( left.size() < right.size() )
      return true;
   return false;
}

// Color codes to display dir, files and exec.
#define BERANG "\e[m" 
#define HARA_RANG "\e[32m" 
#define NILA_RANG "\e[36m"

// Core logic of ls command
int ls(string pass) {
	char curr_dir[1024]; 
	DIR *dp = NULL; 
	struct dirent *dptr = NULL; 
	unsigned int count = 0; 
	struct winsize w;
	vector < string > files_name;
	map < string, string > map_files;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w); 

	// Get the current working directory.
	chdir("/path/to/change/directory/to");
	getcwd(curr_dir, sizeof(curr_dir));
	if (NULL == curr_dir)  { 
		cout << endl << "ERROR : Working directory cannot be opened." << endl;
		return -1;
	}

	// Check if the directory can be opened.
	dp = opendir((const char*)curr_dir);    
	if(NULL == dp)  {
		cout << endl << "ERROR : Working directory cannot be opened." << endl;
		return -1;
	}

	if (pass == "") {
		for(count = 0; NULL != (dptr = readdir(dp)); ++count)  {
			if(dptr->d_name[0] != '.')  { 
				// Check if the file is executable
				if(!access(dptr->d_name,X_OK))  {
					int fd = -1;
					struct stat st; 
					fd = open(dptr->d_name, O_RDONLY, 0); 
					if(-1 == fd)  {
						cout << endl << "Opening file/Directory failed" << endl;
						return -1; 
					}

					fstat(fd, &st); 
					// Check if it actaully was a directory with execute 
					// permissions on it. 
					if(S_ISDIR(st.st_mode)) {
						// If it was a directory, print it in Blue
						files_name.push_back(dptr->d_name);
						map_files.insert(make_pair(dptr->d_name, NILA_RANG));
						// cout << NILA_RANG << dptr->d_name << "\t" << BERANG;
					} else  {                                 
						// If it was a normal executable 
						// Print it in green 
						files_name.push_back(dptr->d_name);
						map_files.insert(make_pair(dptr->d_name, HARA_RANG));
						// cout << HARA_RANG << dptr->d_name << "\t" << BERANG;
					}
					close(fd); 
				} else { 
					// No executable flag ON 
					// Print it in black(default)
					files_name.push_back(dptr->d_name);
					map_files.insert(make_pair(dptr->d_name, ""));
					// cout << dptr->d_name << "\t";
				}
			} 
		}
		sort(files_name.begin(), files_name.end(), stringCompare);
		for (int i = 0; i < files_name.size(); ++i) {
			if (map_files[files_name[i]] == "") {
				cout << files_name[i] << "\t";
			} else {
				cout << map_files[files_name[i]] << files_name[i] << "\t" << BERANG;
			}
		}
		if (!files_name.size()) {
			cout << "Current working directory is empty" << endl;
		} else {
			cout << endl;
		}
	} else {
		while ((dptr = readdir(dp)) != NULL){
		  if(dptr->d_name[0] != '.')  {
			struct stat fileStat;
			stat(dptr->d_name,&fileStat);   
			
			((S_ISDIR(fileStat.st_mode)) ? printf("d") : printf("-"));
			((fileStat.st_mode & S_IRUSR) ? printf("r") : printf("-"));
			((fileStat.st_mode & S_IWUSR) ? printf("w") : printf("-"));
			((fileStat.st_mode & S_IXUSR) ? printf("x") : printf("-"));
			((fileStat.st_mode & S_IRGRP) ? printf("r") : printf("-"));
			((fileStat.st_mode & S_IWGRP) ? printf("w") : printf("-"));
			((fileStat.st_mode & S_IXGRP) ? printf("x") : printf("-"));
			((fileStat.st_mode & S_IROTH) ? printf("r") : printf("-"));
			((fileStat.st_mode & S_IWOTH) ? printf("w") : printf("-"));
			((fileStat.st_mode & S_IXOTH) ? printf("x") : printf("-"));
			
			struct passwd *pwd;
                        pwd = getpwuid(fileStat.st_uid);
			//cout<<" "<<pwd->pw_name;
			
			struct group *grp;
			grp= getgrgid(fileStat.st_gid);
			//cout<<" "<<grp->gr_name;
			
			//cout << " "<< fileStat.st_size;
			
			char time[100];
			strftime(time, sizeof(time), "%b %2d %H:%M", localtime(&fileStat.st_mtime));
			//cout<<" "<<time;
			
			//cout << " "<<dptr->d_name << endl;
			
			printf(" %ld %s %s %6ld %s %s\n",(long)fileStat.st_nlink,pwd->pw_name,grp->gr_name,(long)fileStat.st_size,time,dptr->d_name);
		}
		}
	cout << endl;
	}
	return 0;
}	
