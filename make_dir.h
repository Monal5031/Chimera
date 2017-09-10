int make_dir(string name) {

	char tab2[1024];
	strcpy(tab2, name.c_str());
	const int dir_err = mkdir(tab2, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	if (-1 == dir_err) {
		cout << "error creating directory" << '\n';
		return 1;
	}
	return 0;
}
