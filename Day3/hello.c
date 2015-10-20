// hello.c

#include <stdio.h>
//..초기화된 전역 변수 .data 섹션에 높이게 됩니다. 
char s[] = "abcdefg"; 

// 함수의 기계어는 .text 섹션에 놓이게 됨 
int main()
{

	int y = 0;
	printf("stack 주소: %p \n", &y);
	printf("전역변수 주소 : %p \n", s);

	printf("main 함수 주소 : %p \n", &main);
	printf("printf 함수 주소 : %p \n", &printf);

	getchar();

}
