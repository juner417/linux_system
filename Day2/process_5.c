// process_5.c
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int n = 0;

/*
void myhandler( int signo )
{
	printf("%d: receive signal %d \n", ++n, signo);
	wait(0);
}
*/
/*
void myhandler( int signo )
{
	// wait하고 성공하면  0보다 큰값 리턴, 살아있는 자식이 없으면 -1 리턴 죽을때까지 대기
	while ( wait(0) >0 )
	{
		printf("%d: receive signal %d \n", ++n, signo);
	}
}
*/
void myhandler( int signo )
{

	printf("%d : receive signal %d\n", ++n, signo);
	// wait하고 성공하면 >0 리턴, 죽은 자식이 없으면 죽을때까지 대기하지 않음

	while( waitpid(-1, 0, WNOHANG) >0);
}

int main()
{
	signal(SIGCHLD, myhandler);

	int pid = 0;

	int i = 0; 

	for (i = 0; i<100; i++)
	{
		pid = fork();

	// for child
	if ( pid ==0 )
	{
		int i = 0;
		for ( i=0; i<3; i++)
		{
			printf("\t\t\tchild...\n");
			//sleep(rand() * getpid() % 3);
			sleep(1);
		}
		return 0; //main 함수에서 리턴 프로세스종료
	}
	}

	while(1)
	{
		//printf("parrent...\n");
		sleep(1);
	}
}
