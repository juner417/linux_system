// file_3.c
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char s1[32] = {0};

	int fd1 = open("file_3.c", O_RDONLY);
	printf("fd1 : %d \n" , fd1);
	read(fd1, s1, sizeof(s1)-1);
	printf("data : %s\n", s1);

// 두번째 fd로 읽으면 기존의 fd와 offset을 공유하지 않음
	char s2[32] = {0};
	
	//int fd2 = open("file_3.c", O_RDONLY); // 파일을 새로오픈
	int fd2 = dup(fd1); // 파일의 번호를 복제  이렇게 하면 fd1에서 읽은내용을 이어서 읽음 offset공유
	printf("fd2 : %d \n" , fd2);
	read(fd2, s2, sizeof(s2)-1);
	printf("data : %s\n", s2);
	
	close(fd1);
	close(fd2);
}
