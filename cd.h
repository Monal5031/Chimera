void print_path() {
   char *wd(getcwd(NULL,0));
   string cwd(wd);
   free(wd);
   cout << cwd << endl;
}

int cd(string newDir) {
	if (newDir == "") {
		cout << "Directory name cannot be empty" << endl;
		return 1;
	}
        string path;
        int rc = -1 ;

        char * wd=(getcwd(NULL, 0));
        if(newDir == "~") {   
		rc=chdir("/home/avsingh");
		path = wd;
		free(wd);   
	}
	else if (newDir == "-") {           
                rc = chdir(path.c_str());
                print_path() ;
                path = wd;
                free(wd);
	}
	else {
		rc = chdir(newDir.c_str());
		path = wd;
		free(wd);
		if (rc < 0)  {
			cout << "bash: cd: "<< newDir << ": No such file or directory" << endl;
			exit(1);
		}
	}   
}

