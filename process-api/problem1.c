#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int x;
    x = 100;
    int rc = fork();
    if (rc < 0){
      fprintf(stderr, "fork failed\n");
      exit(1);
    } else if (rc == 0){
        x = 120;
      printf("this is x called from child process %d", x);;
    } else {
        x = 140;
      printf("this is x called from parent process %d", x);
    }
}