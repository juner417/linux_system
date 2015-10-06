#include <stdio.h>
#include <fcntl.h>

int main( int argc, char ** argv)
{
	char s[32] = {0};
	int ret = 0;

	if ( argc == 2 )
	{
		int fd = open(argv[1], O_RDONLY );
		close(0);
		dup(fd); // 0번째 복사
		close(fd);
	}


	while( ( ret = read(0, s, sizeof(s)-1) >0 ))
			write(1, s, sizeof(ret));

}

// "a.out file_5.c"를 입력했을때 
// 표준입력 대신 file_5.c의 내용이 화면에 출력되게 됨
