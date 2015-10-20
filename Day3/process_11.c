// process_11.c
#include <stdio.h>
#include <unistd.h>
// C표준 system() 함수처럼 구현하는 방법
// 129 page
void mysystem(const char* name)
{
	if ( fork() == 0)
	{

		char* s[] = {"ls", "-al", 0};
		execve("/bin/ls", s, 0);
	}
	wait(0);
}

int main()
{
	printf("hello\n");

	getchar();

	mysystem("ls -al");

	printf("parent....\n");
}

