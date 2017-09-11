int make_dir(string name) {

	if (name == "") {
		cout << "Cannot create directory with empty name" << endl;
		return 1;
	}

	char tab2[1024];
	//array of the chars which will be passed to mkdir method

	strcpy(tab2, name.c_str());

/*Copies the C string pointed by source into the array pointed by destination,
including the terminating null character (and stopping at that point).
To avoid overflows, the size of the array pointed by destination shall be
long enough to contain the same C string as source (including the terminating null character),
 and should not overlap in memory with source.
*/

	const int dir_err = mkdir(tab2, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
/*makes a new directory of the given name passd as array of characters
	return -1 if Error occurs
	else returns 0
*/


	if (-1 == dir_err) {
		cout << "Error creating directory" << endl;
		return 1;
	}
	return 0;
}
