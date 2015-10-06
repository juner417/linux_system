#include <stdio.h>
#include <fcntl.h>

int main()
{
	// c표준 함수로 파일 열기
	FILE *f = fopen("file_6.c", "r"); //결국 open() 호출

	// FILE* 에서 fd_array의 인덱스 얻어내는 방법
	printf("f: %p, fd: %d, %d \n", f, f->_fileno, fileno(f));
    // f : FILE구조체 주소, f->_fileno는 FILE 구조체안의 fd 주소
	// fileno(f) FILE 구조체 안의 fd주소 확인 함수

	printf("%p, %d \n", stdout, fileno(stdout));

	printf("hello"); //개행 노, 
	// 그렇게 되면 개행을 못만났기 때문에 hello는 버퍼에만 있음
	// 그래서 출력이 되지 않고 버퍼에만 존재한뒤 10초뒤 개행을 만나 
	// 출력된다.
	// C FILE 구조체는 라이브러리 버퍼를 가지고 있는걸 설명한다.;

	sleep(10);

	printf("\n");
	
	getchar();

	fclose(f);
}
