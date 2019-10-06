#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#define RWXRWXRWX  (S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH|S_IWOTH|S_IXOTH)

int main()
{
    umask(0);
    if(creat("foo",RWXRWXRWX)<0)
    {
        printf("creat err\n");
        return -1;
    }
    umask(0066);
    if(creat("bar",RWXRWXRWX)<0)
    {
        printf("creat err\n");
        return -1;
    }
    return 0;
}
