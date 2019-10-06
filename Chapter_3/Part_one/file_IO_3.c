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
    off_t set = lseek(fd,3,SEEK_SET);
    printf("%d",set);
    write(fd,"r",1);    //offset == 4
    lseek(fd,-1,SEEK_CUR);
    write(fd,"e",1);
    return 0;
}

