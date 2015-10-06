// Day1  file_0.c

#include <stdio.h>
#include <fcntl.h>

int main()
{
	char s[] = "hello, world\n";

	int ret = write(1, s, sizeof(s));
    // 1(stdout)에 s를 sizeof만큼 써라...
	// 결과는 ret에 저장됨
	printf("write %d bytes \n", ret);
}

// build : gcc file_0.c -o file_0.c
// run : ./file_0.c
