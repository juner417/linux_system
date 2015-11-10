// 5_async2.c

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <aio.h> // 비동기 io aiocb를 사용하기 위해 

void foo( sigval_t s) 
{
	printf("foo\n");
	struct aioncb* p = (struct aiocb*)s.sival_ptr; // 비동기 요청시 전달한 aiocb 구조체 포인터
	int ret = aio_return ( p ); 

	printf("%d \n", ret);
	printf("%s \n", p->aio_buf);

}

int main() 
{
	int fd = open("file.txt", O_RDONLY);

	struct aiocb myaiocb; 
    memset (&myaiocb, 0, sizeof(myaiocb));

	myaiocb.aio_buf = malloc(sizeof(char)*10); 
    myaiocb.aio_fildes = fd; // 파일 번호
	myaiocb.aio_nbytes = 10; // 버퍼 크기
	myaiocb.aio_offset = 0; // 파일 offset

	// 비동기 작업이 마무리 되면 호출될 함수를 지정한다. 
	myaiocb.aio_sigevent.sigev_notify = SIGEV_THREAD;
	myaiocb.aio_sigevent.sigev_notify_function = foo;
	myaiocb.aio_sigevent.sigev_notify_attributes = 0;
	myaiocb.aio_sigevent.sigev_value.sival_ptr = &myaiocb;

	int ret = aio_read(&myaiocb); // 비동기 읽기 요청

	printf("비동기 읽기 시작 : %d\n", ret);

	while(1); // 다른작업
	
}

