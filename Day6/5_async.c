// 5_ async.c

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <aio.h> // 비동기 io aiocb를 사용하기 위해 

// gcc 5_async.c -o async -lrt  비동기 io를 하려면 rt라이브러리와 링크해야 함
int main() 
{
	int fd = open("file.txt", O_RDONLY);

	// 비동기 io를 위한 작업들 
	struct aiocb myaiocb; // = {0}; // async io control block
    memset (&myaiocb, 0, sizeof(myaiocb));

	myaiocb.aio_buf = malloc(sizeof(char)*10); // 읽어올 버퍼(힙에 할당해야 한다)
    myaiocb.aio_fildes = fd; // 파일 번호
	myaiocb.aio_nbytes = 10; // 버퍼 크기
	myaiocb.aio_offset = 0; // 파일 offset

	int ret = aio_read(&myaiocb); // 비동기 읽기 요청

	printf("비동기 읽기 시작 : %d\n", ret);

	// 비동기 작업이 종료되는것을 대기한다. 
	struct aiocb* aio_list[1];
	memset( aio_list, 0, sizeof(aio_list));

	aio_list[0] = &myaiocb;

	ret = aio_suspend( aio_list, 1, 0);
    
	printf("ret : %d \n" , ret);
	

	// 비동기 작업의 결과를 얻어온다. 
	ret = aio_return(&myaiocb);
	printf("ret : %d\n", ret);

	printf("buff: %s \n", myaiocb.aio_buf);
}

// 동기 io code
//int main() 
//{
//	int fd = open("file.txt", O_RDONLY);
//
//	char buf[256] = {0};

//	int ret = read( fd, buf, 10); // 동기 io. 읽기 작업이 완전히 끝나면 리턴, 
//	                              // 리턴값으로 읽은 data의 크기가 나온다.
//
//	printf("리턴값 : %d, %s\n", ret, buf);
//}
