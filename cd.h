/*
cd function change the directory of the programm
if it is executed successfully returns  0 ; 
if the given path or directory does not exits gives error message
and returns  1 ;
*/

string previous_path_cd ; /*global variable to store the previous path
			  used in " cd - " call*/

string get_path() {

	char *wd(getcwd(NULL,0));
  	string cwd(wd);
 	free(wd);
  	return cwd ;

	/*
	get_path() ;
	somewhat similar to " pwd() " ;
	return the path of current directory in which the program is going on ;
	used in " int cd() " 
	*/


}
	

string determine_home(){

	struct passwd *pw;
	pw = getpwuid(geteuid());
    return pw->pw_dir;

	/*
	used for determining the path "/home/username" 
	this path used in "cd ~" call
	*/
}

int cd(string newDir) {
	
	string path = previous_path_cd;
        int rc = -1 ;
	/*chdir changes directory to the mentioned path*/
	/*if chdir executes successfully then returns 0 otherwise -1 */
        if(newDir == "~") {
		/*
		cd ~ call is used to go to the user's home directory
		*/
		previous_path_cd = get_path();
		rc=chdir(determine_home().c_str());
	}
	else if (newDir == "-") {
                /*cd - call used to toggle between current and previous directory*/
		string temp = get_path();
                rc = chdir(path.c_str());
		previous_path_cd = temp ;
                cout << get_path() << endl ;
	}
	else {	
		/*get any path or directory name and change current directory to that*/
		previous_path_cd = get_path();
		rc = chdir(newDir.c_str());
		if (rc < 0)  {
			/*rc = -1 ,means chdir has not executed successfully so 
			now we will print error message and int cd() returns int value 1 */
			cout << "bash: cd: "<< newDir << ": No such file or directory" << endl;
			return 1 ;
		}
	}
	return 0 ;//current directory changes successfully , returns 0
}
