#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    
    //get file attribute
    struct stat st;
    
    lstat("file_12.c", &st);

    printf("inode: %d\n", st.st_ino);
    //protection
    char s[10] = "---------";
    
    char rwx[] = "rwx";

    int i = 0;

    for (i = 0; i< 9; i++)
    {
        if (( st.st_mode >> (8-i)) & 0x1) //!!
            s[i+1]  = rwx[i%3];
    }

    printf("%s\n",s);

    time_t t = st.st_mtime;
    
    print("%ld\n", t); 

    printf("%ld years\n", t / (60*60*24*365)); // years from 1970

    // epoch time => tm
    struct tm * tm = localtime(&t);

    printf("%04d - %02d - %02d\n", tm->tm_year + 1900, tm->tm_mon+1, tm->tm_mday);


}
