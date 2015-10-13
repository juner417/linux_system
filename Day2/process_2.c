// process_2.c
#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("hello\n");

	int pid = fork();

	if (pid == 0)
	{
        printf("i am a child... my pid is %d\n", getpid());
	}
	else
	{
		printf("i am a parent.. my pid is %d, my child is %d \n", getpid(), pid);
	}
	printf("bye~~ \n");
}
