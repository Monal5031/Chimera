void exit_command() {
	while (1) {
	cout << "Type exit to quit the program" << '\n';
	string command;
	cin >> command;
	if (command == "exit" || command == "Exit" || command == "quit") {
		cout << "type Y to continue" << '\n';
		string confirm;
		cin >> confirm;
		if (confirm == "Y" || confirm == "y") {
			return;
		}
		else {
			break;
		}
	}
	else {
		cout << "Please enter valid commad" << '\n';;
	}
	}
}

