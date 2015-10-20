// process_10.c
#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("hello\n");

	getchar();

	int pid = fork();

	if (pid ==0) // 자식인 경우 
	{
		// 실행파일을 바꾼다....execve
		char* s[] = { "ls", "-al" };
		execve("/bin/ls", s, 0);
		// 아래 줄은 더이상 실행되지 않는다....
	}

	// 부모인 경우
	wait(0);

	printf("parent....\n");
}

