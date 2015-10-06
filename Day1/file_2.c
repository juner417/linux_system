// file_2.c

#include <stdio.h>
#include <fcntl.h> // write()를 사용하기 위해 

int main() {
	
	char s[32] = {0};
	// 새로운 파일 open
	int fd = open("file_2.c", O_RDONLY);

	printf("file no: %d\n", fd);

	int ret = 0;
	while( (ret = read(fd, s, sizeof(s))) > 0 )
		write(1, s, ret);

	getchar(); // enter 키 누를때 까지...

	close(fd);

	getchar();
}

// build : gcc file_2.c -o file_2
// run : file_2

