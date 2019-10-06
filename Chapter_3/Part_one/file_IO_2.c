#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd = open("test_1.txt",O_RDWR|O_CREAT|O_EXCL,0666 );  //
    if(fd == -1)
    {
        printf("creat err!\n");
        return -1;
    }

    write(fd,"hello!",6);

    return 0;
}

