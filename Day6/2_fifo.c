// 2_fifo.c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
// 리눅스 IPC 종류
// 1. mmap으로 파일 매핑 후 사용
// 2. 공유메모리(shmget)
// 3. FIFO(mkfifo)
// 4. 메세지Q
// 5. Pipe
// 6. Domain socker

// IPC2, FIFO사용하기
int main()
{
	// 1. fifo 만들기 // fifo queue만들기
	//int ret = mkfifo("myfifo", 0666);
	//myfifo라는 파일 생성, 진짜 파일은 아님

	//if ( ret == -1) 
	//{
	//	printf("error\n");
	//}

	// 2. fifo는 진짜 파일은 아니지만 파일과 동일한 인터페이스(함수)를 사용해서 읽어내면 됩니다. 
	int fd = open("myfifo" , O_RDWR);
	char buf[256] = {0};

	while(1)
	{
		read(fd, buf, 256); //읽은 데이터가 없으면 대기 됩니다.
		printf("FIFO에서 읽은 data: %s\n", buf);
	}

}

// 터미널에서 mkfifo myfifo2 해도 만들어짐
