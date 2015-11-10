#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main() 
{
	int id = shmget( (key_t)1234, 1024, 0666 | IPC_CREAT);

	if ( id == -1)
	{
		printf("error\n");
		return 0;
	}

	char* p = (char*)shmat( id, 0, 0);

	printf("%p \n", p);

	while (1) 
	{
		getchar(); // enter 대기
		printf("%s\n", p);
	}

}

// gcc -o read_shared_momry 1_read_shared_memory.c
// ipcs로 보면 nattach가 2로 되어 있음..
