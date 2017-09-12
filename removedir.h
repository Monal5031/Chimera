int remove_directory(const char *delete_dir_name) {
	DIR *dir_pointer = opendir(delete_dir_name);
	size_t path_len = strlen(delete_dir_name);
	int return_val = -1;
	if (dir_pointer) {
		struct dirent *file_pointers;
		return_val = 0;
		while (!return_val && (file_pointers=readdir(dir_pointer))) {
			int r2 = -1;
			char *buf;
			size_t len;
			/* Skip the names "." and ".." as we don't want to recurse on them. */
			if (!strcmp(file_pointers->d_name, ".") || !strcmp(file_pointers->d_name, "..")) {
				continue;
			}
			len = path_len + strlen(file_pointers->d_name) + 2; 
			buf = (char*)malloc(len);
			if (buf) {
				struct stat statbuf;
				snprintf(buf, len, "%s/%s", delete_dir_name, file_pointers->d_name);
				if (!stat(buf, &statbuf)) {
					if (S_ISDIR(statbuf.st_mode)) {
						r2 = remove_directory(buf);
					} else {
						r2 = unlink(buf);
					}
				}
				free(buf);
			}
			return_val = r2;
		}
		closedir(dir_pointer);
	}
	if (!return_val) {
		return_val = rmdir(delete_dir_name);
	}
	return return_val;
}
