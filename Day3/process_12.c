#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() 
{
	int pid = fork();

	if ( pid == 0)
	{
		printf("i am child, my pid is %d \n", getpid());
		//return 5;
		exit(5);
	}

	int status = 0;
	wait(&status); //자식이 종료할때 리턴된 값을 얻어온다. 

	if ( (status & 0xff) == 0 )
		printf("정상종료: %d \n", (status >> 8) & 0xff);
	else
		printf("비정상종료 : %d \n", status);
}

// 비정상 종료 : kill -9 프로세스id의 경우 
