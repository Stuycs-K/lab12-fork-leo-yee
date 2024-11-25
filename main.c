#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>


int main(){
  printf("%d about to create 2 child processes\n", getpid());
  pid_t p;
  // for (int i = 0; i < 2; i++){
    p = fork();
    if (p){
      p = fork();
    }
    if (!p){
      int fd = open("/dev/random", O_RDONLY);
      int n  = -1;
      int r = read(fd, &n, 4);
      n = abs(n % 5) + 1;
      // printf("%d\n", n);
      // printf("%d\n", p);
      printf("%d %d sec\n", getpid(), n);
      sleep(n);
      printf("%d finished after %d seconds.\n", getpid(), n);
      exit(0);
    }
  // }

  // if(p < 0){
  // perror("fork fail");
  // printf("%s\n", strerror(errno));
  // exit(1);
  // }
  // else if (p != 0){
  //   pid_t p;
  //   p = fork();
  // }
  // if (p == 0){
  //   // random

// }
int n = 0;
wait(&n);
exit(0);

}
