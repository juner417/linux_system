//file_8.c
#include <unistd.h>
#include <stdio.sh>
#include <fcntl.h> //for open()

int main()
{
	    int fd = open("a.txt", O_RDONLY);
		printf("%d\n", fd);
		if ( fd == -1)
		{
			perror("error open");
		}
		close(fd);
}



