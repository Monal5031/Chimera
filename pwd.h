int pwd() {
    char cwd[1024];
    chdir("/path/to/change/directory/to");
    getcwd(cwd, sizeof(cwd));
    cout << cwd << endl;
    return 0;
}
