// process_9.c

#include <stdio.h>
#include <unistd.h>

// 현재 프로세스의 실행파일을 다른 실행 파일로 교체하는 함수 

int main()
{
	printf("hello\n");

	getchar();

	char* s[] = {"hello", "-al"};

	// 아래 함수가 현재 실행파일을 바꾸는 함수
	// 신규프로세스 생성이 아닌 실행파일의 교체입니다. 
	execve("./hello", s, 0);
    // execve가 자기자신의 실행파일을 hello로 변경함
	// /proc/pid안의 maps 파일로 확인
	printf("world\n");
}
