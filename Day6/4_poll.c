// 4_poll.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>

int main()
{
	char buf[256] = {0};

	int fd = open("myfifo", O_RDWR);

	struct pollfd fds[2]; // select의 fd_set 비트 배열의 역할

	while(1)
	{
		// pollfd 배열을 채우고.. poll 함수호출
		fds[0].fd = 0; //stdin
		fds[0].events = POLLIN; // 입력대기 POLLIN | POLLOUT

		fds[1].fd = fd; // myfifo 번호
		fds[1].events = POLLIN;

		poll(fds, 2, -1); //입력데이터가 있을때 까지 대기 - select()와 유사한 기능

		printf("읽을 data가 있습니다. \n"); // 누구한테 읽을 데이터가 있는지는 모름 그래서 조사를 해야 함

		// 각 파일에 읽을 데이터가 있는지 조사한 후 읽어낸다. 
		if (fds[0].revents & POLLIN)
		{
			int n = read( fds[0].fd, buf, 256 );
			buf[n-1] = 0; // null 문자
			printf("표준입력 : %s\n", buf);
		}

		if (fds[1].revents & POLLIN)
		{
			int n = read( fds[1].fd, buf, 256 );
			buf[n-1] = 0; // null 문자
			printf("FIFO : %s\n", buf);
		}
	}
}
