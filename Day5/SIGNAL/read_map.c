// read_map.c
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

char* p = 0;
void handler(int signo)
{
	// 
	if (signo == SIGUSR1)
	{
		// 공유메모리의 data를 읽어낸다. 
		printf("data >> %s", p);
	}
}

int main() 
{
	signal(SIGUSR1, handler);

	//1. 파일오픔.
	int fd = open("test.txt", O_RDONLY); //읽기 전용으로
	p = (char*)mmap(0, 100, PROT_READ, MAP_SHARED, fd, 0);
	printf("매핑된 주소: %p\n", p);
	printf("MYPID : %d\n", getpid());

	while(1)
	{
		pause(); //시그널 대기

	//	getchar();
	//	printf("data >> %s\n", p);
	}
	munmap(p, 100);
	close(fd);
}
 // 실행해서 enter키를 눌러보세요
// map 프로그램에서 다른 문자열을 입력하고 여기서 enter치면 됩니다. 

