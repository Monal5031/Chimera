


int make_dir() {

  char tab2[1024];


  std::string name;
  std::cout << "enter file name" << '\n';
  std::cin >> name;
  strcpy(tab2, name.c_str());
  const int dir_err = mkdir(tab2, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  if (-1 == dir_err)
  {
      std::cout << "error creating directory" << '\n';
      exit(1);
  }
}
