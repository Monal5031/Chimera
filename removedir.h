int remdir(string dirname) {

	if (dirname == "") {
		cout << "Directory name cannot be empty" << endl;
		return 1;
	}
	char c[1000];
	strcpy(c,dirname.c_str());
	if(rmdir(c) == 0) {
		cout << "The directory has been deleted." << endl;
	} else {
		cout << "No such directory exists, or if it does, it is non-empty." << endl;
	}
    return 0;
}
