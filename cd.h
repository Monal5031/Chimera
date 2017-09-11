void print_path() {
   char *wd(getcwd(NULL,0));
   string cwd(wd);
   free(wd);
   cout << cwd << endl;

   /*

   #define _POSIX_SOURCE
   #include <unistd.h>

   char *getcwd(char *buffer, size_t size);



   Determines the path name of the working directory and stores it in buffer.
   size
   The number of characters in the buffer area.
   buffer
   The name of the buffer that will be used to hold the
   path name of the working directory.
   buffer must be big enough to hold the working directory name,
   plus a terminating NULL to mark the end of the name.
   */


}
/*
  cd function creates the directory and also checks if the input name is in
  accordance to the standards
*/

int cd(string newDir) {
	if (newDir == "") {
		cout << "Directory name cannot be empty" << endl;
		return 1;
	}
        string path;
        int rc = -1 ;

        char * wd=(getcwd(NULL, 0));
        if(newDir == "~") {
		rc=chdir("/home/ajayguru");
    /*Makes pathname your new working directory
      If successful, chdir() changes the working directory and returns 0.
    */
		path = wd;
		free(wd);
	}
	else if (newDir == "-") {
                rc = chdir(path.c_str());

                /*
                The member function returns a pointer to a non-modifiable C string constructed by adding a terminating null
                element (value_type()) to the controlled sequence.
                Calling any non-const member function for *this can invalidate the pointer.
                chdir changes directory to the mentioned path
                */
                
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
