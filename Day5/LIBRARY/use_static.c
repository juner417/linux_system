// use_static.c
#include <stdio.h>

// 정적라이브러리(.a)를 사용하는 방법
// 1. 헤더파일을 추가 - 결국 함수 선언부가 이 위치에 놓이는 것
#include "mymath.h"

int main() 
{
	int n = add(1,2);

	printf("res: %d\n", n);

	return 0;
}

// 컴파일 gcc use_static.c -c : 컴파일은 문제 없이 됨 use_static.o생성

// 라이브러리와 링크해서 실행파일 만들기
// 1. add.o와 링킹하기
// ld use_static.o add.o -o use_static : 이게 정확한 옵션 하지만 옵션 필요

// gcc use_static.o add.o -o use_static : gcc가 알아서 ld를 실행해 줌
// objdump use_static -d | less

// 2. libmymath.a와 링킹하기
// gcc use_static.o libmymath.a -o use_static2 : 라이브러리를 링크해도 add만 불러온다
// gcc use_static.o -L./ -lmymath -L : 라이브러리가 있는 디렉토리 지정
//                                -l : 라이브러리 이름 지정 (lib와 .a제외한이름)

// 3. 라이브러리 사용자가 컴파일과 링킹을 한번에 하려면
// gcc use_static.c -L./ -lmymath -v -> cc컴파일러로 컴파일 하고
//                                    ld 또는 collect2 링커로 링킹 수행..
//									-v : 컴파일과정 보기 vervose

