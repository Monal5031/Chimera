#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

vector <string> split(const string &text, char sep) {
	vector<string> tokens;
	size_t start = 0, end = 0;
	while ((end = text.find(sep, start)) != string::npos) {
		tokens.push_back(text.substr(start, end - start));
		start = end + 1;
	}
	tokens.push_back(text.substr(start));
	tokens.erase(remove(tokens.begin(), tokens.end(), ""), tokens.end());
	return tokens;
}


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
