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

int main() {

	// Get the string using " getline(cin, test); "
	string test = "  ls   -l  ";
	vector < string > command = split(test, ' ');
	for (int i = 0;  i < command.size(); ++i) {
		cout << command[i] << endl;	
	}
	return 0;
}
