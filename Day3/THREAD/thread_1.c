// thread_1.c
#include <stdio.h>
#include <pthread.h>
// 스레드로 수행할 함수 모양 - 정확히 외어야 함

void* foo( void* args )
{
	int i = 0;

	for (i=0; i< 10; i++)
	{
		printf("foo : %d \n", i);

		sleep(1); //1sec wait
	}
	return 0;
}

int main() 
{

	// foo(0); // 주 스레드가 호출하는 코드 
	 
	pthread_t tid = 0;

	int status = pthread_create( &tid,     // 스레드 id를 담을 변수
								0,         // 스레드 attibute
								foo, "A"); // 스레드 함수, 함수에 보낼 인자
	printf("primary thread\n");

	printf("새로운 스레드의 id : %x, primary thread id : %x \n", tid,
			pthread_self());

	// 새로운 스레드가 종료될 때까지 대기하고
	// 자식의 자원을 회수하는 함수(좀비스레드)
	void* result = 0;
	//pthread_join(tid, &result); // windows : WaitFor SingleObject()
	//printf("자식 스레드 종료 : %d \n", result);

	// 자식 종료를 기다리지 않고. 부모는 다른일을 한다.
	// 더이상 자식 스레드에 관심이 없다면.. 관계를 끊어야 한다. 
	pthread_detach(tid); // 자식 스레드 종료시 바로 자원이 수거된다. 
	                     // 부모가 pthread_join()할 필요없다. 
	while(1);
	//pthread_exit(0); // 주스레드만 종료해달라...
	//return 0; // 주스레드가 main 함수에서 return 0 : process종료
}
// gcc thread_1.c -o thread_1 -lpthread //pthread라이브러리와 같이 링크해달라
