// sig3.c

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

// 1. 사용자 정의 시그널 번호 : 프로세스간 통신의 목적으로 만들어진 시그널 번호
// 2. kill 명령어 : 다른 프로세스에 시그널을 보내는 명령
//           쉘명령 : kill -시그널번호 pid
//           c함수 : kill(pid, 시그널번호)
void handler( int signo)
{
	printf("시그널 발생 : %d\n", signo);
}

int main()
{
	printf("PID : %d\n", getpid());

	//2개 이상의 시그널을 같은 함수로 연결해도 됩니다. 
	// sigusr은 다른 프로세스가 보내는 시그날 받는것 
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);

	while(1);
}

