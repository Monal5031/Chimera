int exit_command() {
    kill(getppid(), SIGKILL);
    return 0;
}
