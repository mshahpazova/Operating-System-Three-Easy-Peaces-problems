#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main()
{
    int fd = open("./text_file.txt", O_CREAT, O_RDWR);
    write(fd, "First line.\n", strlen("First line.\n"));
    int i;
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        write(fd, "child writes a line.\n", strlen("child writes a line.\n"));
    }
    else
    {
        write(fd, "parent writes a line.\n", strlen("parent writes a line.\n"));
    }
    return 0;
}