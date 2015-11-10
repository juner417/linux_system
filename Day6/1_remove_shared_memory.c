// 1_remove_shared_memory

#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>

int main()
{
	int id = shmget((key_t)1234, 1024, 0666 | IPC_CREAT);

	shmctl(id, IPC_RMID, 0); // 공유메모리 제거
}
// 프로그래 실행한뒤 ipcs로 제거되었는지 확인 
