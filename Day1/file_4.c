#include <stdio.h>
#include <fcntl.h>

//file_4.c

int main(int argc, char ** argv)
{
	int i = 0;

	if (argc == 2) // arg 카운트가 2개이면 ,
		// 아니면 바로 출력
	{
		//close(1); //표준 출력을 닫는다. 

		int fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0666); 
		// 666은 권한

		close(1);
		printf("fd: %d\n", fd); 
		dup(fd); // fd를 하나더 복제 

		close(fd);
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d\n", i); // 결국 write(1, ...);로 변경
	}
}

// ./a.out  ./a.out aa.txt
