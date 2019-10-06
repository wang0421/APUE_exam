#include <stdlib.h>
#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>

int
main(int argc, char * argv[])
{
    int     fdr;
    int     fdw;
    int     ch;
    if (argc != 3)
        printf("Usage: ./test4_6 <srcfile> <dstfile>");

    if ((fdr = open(argv[1], O_RDONLY)) < 0)
        printf("Open %s: error", argv[1]);

    if ((fdw = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,0600)) < 0)
        printf("Open %s: error", argv[2]);

    while(read(fdr, &ch, 1) == 1)
    {
        if(ch == '\0')
            continue;
        if (write(fdw, &ch, 1) != 1)
            printf("Write to %s: error!", argv[2]);

    }
    exit (0);
}
