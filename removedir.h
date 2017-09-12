int remdir(string dirname) {

	if (dirname == "") {
		cout << "Directory name cannot be empty" << endl;
		return 1;
	}
	char c[1000];
	strcpy(c,dirname.c_str());
	/*Copies the C string pointed by source into the array pointed by destination,
	including the terminating null character (and stopping at that point).
	To avoid overflows, the size of the array pointed by destination shall be
	long enough to contain the same C string as source (including the terminating null character),
	 and should not overlap in memory with source.
	*/
	// rmdir removes the given directory and returns 0 for successful removal
	// and -1 for Error
	
	if(rmdir(c) == 0) {
		cout << "The directory has been deleted." << endl;
	} else {
		cout << "No such directory exists, or if it does, it is non-empty." << endl;
	}
    return 0;
}
