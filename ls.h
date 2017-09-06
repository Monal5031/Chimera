


int ls()
{
  DIR *dp;
  struct dirent *ep;
  string dirname;
  cin >> dirname;
  dp = opendir(dirname.c_str());
  if(dp != NULL)
    {
      while(ep = readdir (dp))
        puts (ep->d_name);
       closedir (dp);
       return 0;
    }
  else
    perror ("Couldn't open the directory");
	return -1;
		
}