// sub.c
#include <stdio.h>

int sub(int a, int b)
{
	printf("sub 호출됨\n");
	return a - b;
}

// 정적 라이브러리를 만드는 방법 
// 1. c소스로 object 파일 만들기
// gcc add.c -c : 컴파일만 해달라 add.o
// gcc sub.c -c :                 sub.o

//2. object파일을 묶어서 정적 라이브러리로 빌드하기
// ar rscv libmymath.a add.o mul.o : 정적라이브러리는 관례적으로 lib로 시작
