// Include your STL headers here
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <fcntl.h> 
#include <sys/ioctl.h>
#include <pwd.h>
#include <grp.h>
#include <utility>
#include <map>
#include <signal.h>

using namespace std;

// Include your header file below here
#include "split_command_and_flags.h"
#include "pwd.h"
#include "exit_command.h"
#include "make_dir.h"
#include "cd.h"
#include "removedir.h"
#include "ls.h"

int main() {

	register struct passwd *pw;
	register uid_t uid;
	uid = geteuid ();
	pw = getpwuid (uid);
	string root_name = pw->pw_name;
	while (1) {
		char cwd[1024];
		chdir("/path/to/change/directory/to");
		getcwd(cwd, sizeof(cwd));
		string command;
		cout << HARA_RANG <<root_name << "@ubuntu" << BERANG << ":" << NILA_RANG << cwd << BERANG << "$";
		getline(cin, command);
		vector < string > commands = split(command, ' ');
		if (commands[0] == "pwd") {
			pwd();
		}
		else if (commands[0] == "mkdir") {
			make_dir((commands.size() == 1) ? "": commands[1]);
		}
		else if (commands[0] == "cd") {			
			cd((commands.size() == 1) ? "": commands[1]);
		}
		else if (commands[0] == "ls") {
			ls((commands.size() == 1) ? "" : commands[1]);
		}
		else if (commands[0] == "rmdir") {
			remdir((commands.size() == 1) ? "": commands[1]);
		}
		else if(commands[0] == "exit") {
			exit_command();
		}
		else {
			cout <<commands[0] << ": Command not found" << endl;
		}
	}
	return 0;
}
