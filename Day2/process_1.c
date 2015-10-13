// process_1.c

#include <stdio.h>
#include <unistd.h>

int main() 
{
	printf("hello \n");

	fork();// 아래 줄 부터 자식 프로세스에서 실행함

	printf("world \n");
}
