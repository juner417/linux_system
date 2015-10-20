// thread_2_1.c
#include <stdio.h>
#include <pthread.h>

void delay() 
{
	int i = 0;
	
	for ( i=0; i<1000000; i++) ;
}

// 리눅스 뮤텍스
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//MUTEX의 정적 초기화 기법

void* foo( void* args)
{
	static int x = 0;
	//int x = 0;
	int i = 0;

	for (i=0; i<20; i++)
	{
		pthread_mutex_lock(&mutex); // 하나의 스레드만 뮤텍스를 잡을수 있다
									// 다른스레드는 대기해야 한다
		// ------------------------------------------
		x = 100; delay();
		x = x+1; delay();
		printf("%s : %d\n", (char*)args, x); delay();
		// ------------------------------------------
		pthread_mutex_unlock(&mutex);
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

