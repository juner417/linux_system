// process_6.c

#include <stdio.h>

// process_5 -a -l로 실행하면

// const char* argv[] = { "process_6 -a -l"}; 후에 
// main(3, argv) 로 실행됨니다. 

int main(int argc, char* argv[] )
{
	printf("%d\n", argc);

	int i = 0;

	for (i=0; i<argc; i++)
	{
		printf("%s\n", argv[i]);
	}
}
// gcc -o process_6 process_6.c 빌드
// ./process_6 -a -l 로 실행
