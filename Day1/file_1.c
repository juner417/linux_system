// file_1.c

#include <stdio.h>
#include <fcntl.h> // write()를 사용하기 위해 

int main() {
	
	char s[32] = {0};
	int ret = 0; // 자신이 읽어드린 byte를 확인하기 위한

	while( (ret = read(0, s, sizeof(s))) > 0 )
		write(1, s, ret);
}

// build : gcc file_1.c -o file_1
// run : file_1

