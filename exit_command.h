void exit_command() {
  /* code */
  while (1) {
		/* code */
		std::cout << "Type exit to quit the program" << '\n';
	  std::string command;
	  std::cin >> command;
	  if (command == "exit" || command == "Exit" || command == "quit") {
	    /* code */
			std::cout << "type Y to continue" << '\n';
			std::string confirm;
			std::cin >> confirm;
			if (confirm == "Y" || confirm == "y") {
				/* code */
				
				return;

			}
			else{
				break;
			}
	    }
	  else{
	  std::cout << "Please enter valid commad" << '\n';;
	}
	}
}
