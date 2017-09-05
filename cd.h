void print_error(){
	perror("");
	exit(EXIT_FAILURE);

}

int cd(){
    string newDir;
    cin >> newDir;
    int rc = chdir(newDir.c_str());
    if (rc < 0) {
        print_error() ;
		return 1 ;
    }
    return 0 ;
}

