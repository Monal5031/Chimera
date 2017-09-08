void print_path(){
   char *wd(getcwd(NULL,0));
   string cwd(wd);

   free(wd);

   cout << cwd << endl;
   
}

int cd()
{   
        string newDir;

        string path;
        
        
        cin >> newDir;
       
        
        int rc = -1 ;

        char * wd=(getcwd(NULL,0));

        
        if(newDir=="~")
        {   
                rc=chdir("/home/avsingh");
                path = wd;
                free(wd);   
        }
        else if (newDir=="-")
        {           
                rc = chdir(path.c_str());
                print_path() ;
                path = wd;
                free(wd);
        }
        else
        {
                rc = chdir(newDir.c_str());
                path = wd;
                free(wd);
                if (rc < 0) 
                {
                     cout << "bash: cd: "<<newDir<<": No such file or directory\n" ;
                     exit(1);
                }
        }   
}