// sig1.c
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

//step 2.시그날 무시하기
// kill -9 (SIGKILL)로 죽일수 있음..
// 1. SIG_IGN으로 시그널을 무시할수 있다. 
// 2. SIGSTOP(ctrl+z)와 SIGKILL은 무시할수 없다....
int main() 
{
	signal( SIGINT, SIG_IGN); // Ctrl + C 무시하기
	signal( SIGSTOP, SIG_IGN); // Ctrl + z 
	signal( SIGKILL, SIG_IGN); // SIGKILL , 9번 시그날 

	int i = 0;

	while( 1 )
	{
		printf("signal test ... %d\n", ++i);
		sleep(1);
	}
}


#if 0
// STEP1.
// CTRL + C : SIGINT 라는 "시그널"을 OS가 현재 프로세스에게 보내다.
//           디폴트 동작 - 프로세스 종료
int main()
{
	int i = 0;

	while( 1 )
	{
		printf("signal test...%d\n", ++i);
        sleep(1);
	}

}
#endif
