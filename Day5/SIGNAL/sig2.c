// sig2.c
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

//사용자 정의 signal 핸들러.

void myhandler(int signo)
{
	printf("시그널 발생 : %d \n", signo);
	signal(SIGINT, SIG_DFL);// 다음부터 sigint가 나옴면 default핸들러가 수행되게 해달라
	                        // 이순간 ctrl+c를 누른 효과 .. 즉, default핸들러 수행.. 종료

	// 나 또한 다른 프로세스에 시그널 보내기
	kill( getpid(), signo);
	//raise(signo); // 자신에게 시그널을 보내는 함수 raise(시그널번호)
	// 핸들러 수행후에 .. 원래 실행되던 곳으로 이동...
}

int main() 
{
	// signal(SIGINT, SIG_IGN); //무시
	signal(SIGINT, myhandler); //핸들러를 수행해 달라

	int i = 0;
	while( 1 )
	{
		printf("test... \n");
		sleep(1);
	}

}
