/*
 *file	    :  show_contents.c
 *Author      :  Wang Fuguang <wfg2008913@126.com>
 *Date & Time :  2013-12-03 14:30:38
 *Description :  Display the contents of the specified file;
 practising using system IO call
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAXSIZ 10
char basebuf[MAXSIZ];

int main(int argc, char *argv[])
{
    int fd;
    
    memset(basebuf, '\0', MAXSIZ);
    if (argc != 2) {
        printf("Error : No input file\n");
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    int ret = 0, len = MAXSIZ-1;
    char *buf = NULL;

    do {
        len = MAXSIZ-1;
        buf = basebuf;

        while(len != 0 && (ret = read(fd, buf, len)) != 0) {
            if (ret == -1) {
                if (errno == EINTR) 
                    continue;

                perror("read");
                break;
            }

            len -= ret;
            buf += ret;
        }
        *buf = '\0';
        printf("%s",basebuf);

    } while(ret);
    /*puts("\n");*/

    if (close(fd) == -1) {
        perror("close");
    }

    return 0;
}
