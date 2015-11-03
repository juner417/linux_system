// sig4.c
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <setjmp.h>

// 스택의 상태를 보관하기 위한 전역변수
sigjmp_buf stk;

void handler(int signo)
{
	printf("시간초과\n");
	siglongjmp(stk, 1); // sigsetjmp 자리로 이동(goto)한다. 그런데 sigsetjmp리턴값은 1로 바뀜
}

int main()
{
	char buff[100];
    signal(SIGALRM, handler); // 알람핸들러를 연결하고
	alarm(5);  // 5초후에 signal이 발생하게 요청하고

	// 현재 스택의 상태를 보관한다. 
	int savesig = 0;
	if ( sigsetjmp(stk, savesig) == 0 ) // sigsetjmp()를 처음으로 호출하면 리턴값이 0이다. 
	{
		read(0, buff, sizeof(buff)); // 입력대기상태에 들어감
	}

	printf("다른처리...\n");
}

#if 0
void handler(int signo)
{
	printf("receive signal \n");
}


int main() 
{
	signal(SIGALRM, handler);

	alarm(10); // 10초 뒤에 sigalr을 보내달라
	printf("befor pause\n");

	// signal이 발생할때까지 대기한다. 
	//while(1); // cpu를 사용하면서 대기
	pause(); // signal발생시 까지 cpu를 사용하지 않고 대기

	printf("after wakeip\n");
}
#endif
