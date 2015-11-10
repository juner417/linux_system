// 3_select.c
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
// IO multiplexing


// 2개 이상의 blocking 되는 IO 를 대기하는 방법 select
int main()
{
	int fd[2];
	fd[0] = fileno(stdin); // 표준입력
	fd[1] = open("myfifo", O_RDWR); // FIFO

	fd_set r_fd; //1024 비트
	printf("%d, %d\n", fd[0], fd[1]);

	while(1)
	{
		FD_ZERO(&r_fd); // 1024비트를 0으로 셋팅
		FD_SET(fd[0], &r_fd);
		FD_SET(fd[1], &r_fd);

		// 2개 이상의 IO에서 읽을 data가 있을때ㅔ 마지막까지 대기
		int state = select( fd[1] + 1, // 마지막 파일의 index + 1
							&r_fd, // 읽을 데이터가 있는지 검사할 목로
							0, // 쓰기
							0, // 예외(에러)
							0); // 시간초과

		printf("읽은 data가 있습니다. \n");
		// 리턴값으로 나온 값은 읽을 data의 갯수 입니다. 
		// 루프를 돌면서 읽어 내야 합니다. 

		switch( state )
		{
			case -1: printf("error\n"); break;

			default:
					 {
						 int i = 0;
						 for (i=0;i<2;i++)
						 {
							 // r_fd의 1024 비트중 우리가 셋팅한 2곳이 1인지를 조사함
							 if (FD_ISSET( fd[i], &r_fd ))
							 {
								 // 이제 읽어내면 됨
								 char s[255] = {0};
								 read( fd[i], s, 256);
								 //printf("%d에서 읽어낸 data : %s\n", i, s);
								 printf("%d에서 읽어낸 data : %s\n", fd[i], s);
							 }
						 }
					 }
					 break;
		}
	}
}
// Blocking 개념
// 크기가 0인파일 : read() 했을때 내용이 없으면 EOF를 만나게 되고 바로 빠져나옴
// FIFO혹은 표준입출력 혹은 소켓 : 읽을 내용이 없으면 대기하게 된다. 
//int main()
//{
//	int fd1 = open("myfifo", 0666); // myfifo가 없는 사람은 mkfifo로 생성

//	char s[256] = {0};
//	read(fd1, s, 256);

	//....
//}
