#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/ioctl.h>



using namespace std;

#include "split_command_and_flags.h"
// Color codes to display dir, files and exec.
#define BERANG "\e[m" 
#define HARA_RANG "\e[32m" 
#define NILA_RANG "\e[36m"

// Core logic of ls command
int ls(bool pass) {
	char *curr_dir = NULL; 
	DIR *dp = NULL; 
	struct dirent *dptr = NULL; 
	unsigned int count = 0; 
	struct winsize w;
	
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w); 

	// Check if working directory is accessible by non-superuser
	curr_dir = getenv("PWD"); 
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

	if (pass) {
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
						cout << NILA_RANG << dptr->d_name << "\t" << BERANG;
					} else  {                                 
						// If it was a normal executable 
						// Print it in green 
						cout << HARA_RANG << dptr->d_name << "\t" << BERANG;
					}
					close(fd); 
				} else { 
					// No executable flag ON 
					// Print it in black(default)
					cout << dptr->d_name << "\t";
				}
			} 
		}
		cout << endl;
	} else {
		while ((dptr = readdir(dp)) != NULL){
			struct stat fileStat;
			stat(dptr->d_name,&fileStat);   

			cout << dptr->d_name << endl;
			cout << "—————————" << endl << endl;
			cout << "File size: \t\t" << fileStat.st_size << "bytes" << endl;
			cout << "Number of Links: \t" << fileStat.st_nlink << endl;
			cout << "File inode: \t\t" << fileStat.st_ino << endl;

			cout << "File Permissions: \t";
			cout << ((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
			cout << ((fileStat.st_mode & S_IRUSR) ? "r" : "-");
			cout << ((fileStat.st_mode & S_IWUSR) ? "w" : "-");
			cout << ((fileStat.st_mode & S_IXUSR) ? "x" : "-");
			cout << ((fileStat.st_mode & S_IRGRP) ? "r" : "-");
			cout << ((fileStat.st_mode & S_IWGRP) ? "w" : "-");
			cout << ((fileStat.st_mode & S_IXGRP) ? "x" : "-");
			cout << ((fileStat.st_mode & S_IROTH) ? "r" : "-");
			cout << ((fileStat.st_mode & S_IWOTH) ? "w" : "-");
			cout << ((fileStat.st_mode & S_IXOTH) ? "x" : "-");
			cout << endl << endl;
			cout << "The file " << ((S_ISLNK(fileStat.st_mode)) ? "is" : "is not") << " a symbolic link" << endl;
		}
	cout << endl;
	}
	return 0;
}

int main() {
	// Make I/O fast	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// Take input from stream
	string inp;
	getline(cin, inp);
	vector <string> command = split(inp, ' ');
	ls(command.size() == 1);
	return 0;
}
