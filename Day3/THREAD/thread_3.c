// thread_3.c
#include <stdio.h>
#include <pthread.h>
// 3의 배수를 차례대로 리턴하는 함수 이야기 

__thread int n = 0 ; // 정적 TLS(thread local storage, thread specific storage)
// 스레드당 한개의 static 메모리
int next3times()
{
	//int n = 0; //스레드당 한개, 하지만 함수 호출 뒤 파괴
	//static int n = 0; //모든 스레드 공유 함수 호출뒤 파괴 안됨
	n = n + 3;
	return n;
}

void* foo(void* args)
{
	printf("%s : %d\n", (char*)args, next3times());
	printf("%s : %d\n", (char*)args, next3times());
	printf("%s : %d\n", (char*)args, next3times());
	return 0;
}

int main()
{
	pthread_t t1, t2;
	pthread_create(&t1, 0, foo, "A");
	pthread_create(&t2, 0, foo, "\tB");

	pthread_exit(0); //주 스레드만 종료...
}
	
