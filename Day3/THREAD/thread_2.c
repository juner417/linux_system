// thread_2.c
#include <stdio.h>
#include <pthread.h>

void delay() 
{
	int i = 0;
	
	for ( i=0; i<1000000; i++) ;
}
// 1. 지역변수는 스택에 놓인다. 스택은 스레드당 한개이다. 멀티스레드에 안전
// 2. static 지역변수, 전역변수는 data 메모리(static 메모리), ELF파일의 .data 섹션
// 프로세스당 한개
void* foo( void* args)
{
	static int x = 0;
	//int x = 0;
	int i = 0;

	for (i=0; i<20; i++)
	{
		// 지역변수 x는 스택의 자원이고
		// 스레드 별로 생성된다. 
		x = 100; delay();
		x = x+1; delay();
		printf("%s : %d\n", (char*)args, x); delay();
	}
	printf("%s finish \n", (char*)args);
	return 0;
}

int main()
{
	pthread_t t1, t2;
	pthread_create( &t1, 0, foo, "A");
	pthread_create( &t2, 0, foo, "\tB");

	void *r1, *r2;
	pthread_join( t1, &r1);
	pthread_join( t2, &r2);
}

