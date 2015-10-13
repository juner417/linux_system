// process_13.c
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void myhandler( int signo )
{
	printf("receive signal %d \n", signo);

	wait(0);
}

int main()
{
	signal(SIGCHLD, myhandler);

	int pid = fork();

	// for child
	if ( pid ==0 )
	{
		int i = 0;
		for ( i=0; i<3; i++)
		{
			printf("\t\t\tchild...\n");
			sleep(1);
		}
		return 0; //main 함수에서 리턴 프로세스종료
	}

	while(1)
	{
		printf("parrent...\n");
		sleep(1);
	}
}
