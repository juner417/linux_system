// mymath.c

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

// 동적 라이브러리(.so, 윈도우의 .dll)로 빌드하는 방법
// gcc mymath.c -shared -fPIC -o libmymath.so mymath.c 
//				-shared : 동적모듈로 빌드 
//              -fPIC : 이동가능한 기계어 코드
