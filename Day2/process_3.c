// process_13.c
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
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
    // 자식의 종료코드 꺼내기
	// 문제점: 자식이 종료될때 까지 대기..
	wait(0);

	while(1)
	{
		printf("parrent...\n");
		sleep(1);
	}
}
