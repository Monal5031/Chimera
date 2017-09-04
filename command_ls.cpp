#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <dirent.h>
#include <sys/stat.h>


using namespace std;

// Color codes to display dir, files and exec.
#define BERANG "\e[m" 
#define HARA_RANG "\e[32m" 
#define NELA_RANG "\e[36m"

// Core logic of ls command
int ls() {
	// Logic to be added here
	return 0;
}


int main() {
	// Make I/O fast	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// Take input from stream
	string inp;
	getline(cin, inp);
	vector <string> command = split(inp, ' ');
	if (command.size() == 1) {
		// Logic for only ls
	} else {
		// Logic for ls -l
	}
	return 0;
}
