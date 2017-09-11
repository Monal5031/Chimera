int exit_command() {
    kill(getppid(), SIGKILL);
    //kills the process with certain ppid
    //getppid() gets the pid of the certain process
    //SIGKILL sends the process signal to kill that process
    return 0;
}
