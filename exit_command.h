//#include <unistd.h>
//#include <signal.h>
int exit_command()
{
    kill(getppid(), SIGKILL);
    return 0;
}
