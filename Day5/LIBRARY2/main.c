// main.c
// 동적라이브러리 사용하는 코드

#include <stdio.h>
#include "mymath.h"

int main()
{
	int n = add(1,2);

	printf("결과 : %d \n", n);

}

// 정적라이브러리 사용할 때 빌드 명령
// gcc use_static.c -o use_static -L./ -lmymath - lib과 .a가 없다. 

// 동적라이브러리 사용할 대 빌드 명령
// gcc main.c -o main -L./ -lmymath - lib와 .so가 없다. 

// 1.실행파일 기계어 코드 조사
// objdump main -d | less  - add의 기계어 코드가 있는지 확인
// 실행파일의 .text 섹션의 기계어 코드 보여줌

// readelf main -a | less - 로 실행파일 포맷 조사. .dynamic 섹션을 보세요. 
// 실행파일의 모든 섹션의 대략적인 내용

// ldd main : main이 사용하는 모든 동적 모듈 열거..

// 환경변수 LD_LIBRARY_PATH에 있습니다. 
//  LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH
// export LD_LIBRARY_PATH 적용후 실행 
