#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


//releor
int main(int argc, char *argv[])
{
    int fd = open("test_1.txt",O_RDWR );  //
    if(fd == -1)
    {
        printf("open err!\n");
        return -1;
    }
    char buff[20] = {0};

    ssize_t s=read(fd,buff,20);
    printf(" %s size is %d\n",buff,s);
    return 0;
}

