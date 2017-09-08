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

	// CMD interpreter and calling will be done here later.	
	
	// For now just add something to test your code.
	// Get the string using " getline(cin, test); "

	// Testing split function
	string test = "  ls   -l  ";
	vector < string > command = split(test, ' ');
	for (int i = 0;  i < command.size(); ++i) {
		cout << command[i] << endl;	
	}

	// Testing pwd command

	pwd();
	// Add tests here. 
	make_dir();
	cd();
	pwd();
	ls(true);
	// Testing rmdir()
	string t="rmdir dir";
	vector<string> com = split(t, ' ');
	remdir(com.back());
	exit_command();
	return 0;
}
