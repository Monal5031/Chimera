// Include your STL headers here
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

// Include your header file below here
#include "split_command_and_flags.h"


int main() {
	// Make I/O faster
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// CMD interpreter and calling will be done here later.	
	
	// For now just add something to test your code.
	// Get the string using " getline(cin, test); "

	// Testing ls command
	string test = "  ls   -l  ";
	vector < string > command = split(test, ' ');
	for (int i = 0;  i < command.size(); ++i) {
		cout << command[i] << endl;	
	}

	// Add tests here.


	return 0;
}
