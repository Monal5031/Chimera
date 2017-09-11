int pwd() {
    char cwd[1024];
    chdir("/path/to/change/directory/to");
    getcwd(cwd, sizeof(cwd));
    cout << cwd << endl;
    return 0;
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
