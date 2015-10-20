// process_7.c
#include <stdio.h>
#include <unistd.h>

int main() 
{
	//fork(); //현재 프로세스의 복사본 생성!!
	system("ls -al"); // 다른 실행 파일 실행 후 종료될때 까지 대기하는 코드
                      // c 표준 함수
	printf("bye...~~~\n");
	return 0;
}
