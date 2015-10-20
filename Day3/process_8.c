// process_8.c

#include <stdio.h>
#include <unistd.h>

// 현재 프로세스의 실행파일을 다른 실행 파일로 교체하는 함수 

int main()
{
	printf("hello\n");

	getchar();

	char* s[] = {"/bin/ls", "-al"};

	// 아래 함수가 현재 실행파일을 바꾸는 함수
	// 신규프로세스 생성이 아닌 실행파일의 교체입니다. 
	execve("/bin/ls", s, 0);
    // execve가 자기자신의 실행파일을 ls로 변경함

	// 오버헤드가 심함 이유는 자신의 사용하는 동적 라이브러리들을 모두 내리고 다시 올려야 함...
	printf("world\n");
}
