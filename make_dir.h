int make_dir(string name) {

	if (name == "") {
		cout << "Cannot create directory with empty name" << endl;
		return 1;
	}

	char tab2[1024];
	strcpy(tab2, name.c_str());
	const int dir_err = mkdir(tab2, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	if (-1 == dir_err) {
		cout << "Error creating directory" << endl;
		return 1;
	}
	return 0;
}
