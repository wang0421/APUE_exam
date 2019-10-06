#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define MAXSIZE 4096

int mydup2(int fd1,int fd2 )
{
    if(fd1<0||fd2<0)
    {
        return -1;
    }
    if(fd1 == fd2)
    {
        return fd1;
    }
    close(fd2);
    int fd_arr[MAXSIZE] = {0},num = 0,fd_tmp;
    while( (fd_tmp = dup(fd1))<fd2 )
    {
        fd_arr[num] = fd_tmp;
        num++;
    }
    while (num>0) {
        close(fd_arr[num]);
        num--;
    }

    return fd2;
}

int main()
{

    return 0;
}
