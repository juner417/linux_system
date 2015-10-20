// thread_2_1.c
#include <stdio.h>
#include <pthread.h>

void delay() 
{
	int i = 0;
	
	for ( i=0; i<1000000; i++) ;
}

// 스레드사이에 공유할 자료 구조 - 대부분 구조체로 만들어지게 된다. 
typedef struct _Data
{
	int x;
	int y;
	// 그외 여러 자원들...
	// 이 구조체의 접근을 동기화 하기 위한 뮤텍스
	pthread_mutex_t mutex; // 구조체 안에 있으므로 정적 초기화가 불가능
	  						// 동적초기화를 해야 한다. 
} DATA;

DATA data; // 스레드간 공유될 전역변수

void init_data()
{
	data.x = 0;
	data.y = 0;
	pthread_mutex_init(&data.mutex, 0); // 뮤텍스의 동적초기화...
	
	printf("init_data\n");
}

// 하나의 함수를 2개의 스레드가 지나갈때...
// 오직 한번만 수행되는 코드를 만들고 싶을때 사용하는 도구

pthread_once_t one = PTHREAD_ONCE_INIT;

void* foo( void* args)
{
	int i = 0;

	//init_data(); // foo가 사용하는 공유 자원 초기화

	pthread_once(&one, init_data); // 스레드가 여러번 지나가도 최초에 한번만
	                              // init_data를 호출해 달라는 개념

	for (i=0; i<20; i++)
	{
		pthread_mutex_lock(&data.mutex); 
		// 하나의 스레드만 뮤텍스를 잡을수 있다
									// 다른스레드는 대기해야 한다
		// ------------------------------------------
		data.x = 100; delay();
		data.x = data.x+1; delay();
		printf("%s : %d\n", (char*)args, data.x); delay();
		// ------------------------------------------
		pthread_mutex_unlock(&data.mutex);
	}
	printf("%s finish \n", (char*)args);
	return 0;
}

int main()
{
	pthread_t t1, t2;

	//init_data(); //스레드간 사용될 자료구조와 뮤텍스 초기화
	pthread_create( &t1, 0, foo, "A");
	pthread_create( &t2, 0, foo, "\tB");

	void *r1, *r2;
	pthread_join( t1, &r1);
	pthread_join( t2, &r2);
}

