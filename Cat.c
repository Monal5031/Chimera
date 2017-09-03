#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char buff[200];
	//scanf("%s %s",c,f);
	printf("%s\n", argv[1]);

	int fd=open(argv[1],O_RDONLY,S_IREAD);

	while(read(fd,&buff,500)>0)
	{

		printf("%s\n",buff);
	}
	
	close(fd);

	
	return 0;
}