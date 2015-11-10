// 1_shared_memory.c

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>

int main()
{
	//공유 메모리를 만들기 1단계. 공유 메모리 생성
	int shmid = shmget( (key_t)1234, // 키 값..
			             1024,       // 크기
						 0666 | IPC_CREAT); // 접근권한 | 플래그 (rw)
	printf("공유메모리 ID: %d\n", shmid);

	if (shmid == -1)
	{
		printf("error\n");
		return 0;
	}

	//----
	//공유메모리를 현재 프로세스의 가상주소와 연결
	char* p =(char*)shmat(shmid, // 공유메모리 id
			              0,     // 원하는 주소(0을 주면 비어있는 가상주소를 os선택
						  0);    // 보호속성(0을 주면 shmget시 전달한 보호속석사용
	printf("연결된 주소: %p\n", p);

	while(1)
	{
		printf(">> ");
		fgets( p, 1024, stdin);
	}
}

//$ ipcs <-- 생성된 공유메모리 확인 가능
// nattach 컬럼 값이 0이면 가상 메모리에 맵핑되지 않은 상태
