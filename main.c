#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>


int main(){
  int * arr = (int*) malloc(sizeof(int) * 2);
  printf("%d about to create 2 child processes\n", getpid());
  pid_t p;
  // for (int i = 0; i < 2; i++){
    p = fork();
    if (p){
      p = fork();
    }
    if (!p){
      int fd = open("/dev/urandom", O_RDONLY);
      int n;
      int r = read(fd, &n, 8);
      n = abs(n % 5) + 1;
      printf("%d %d sec\n", getpid(), n);
      sleep(n);
      printf("%d finished after %d seconds.\n", getpid(), n);
      exit(n);
    }

int x = 0;
int n = wait(&x);
int status = WEXITSTATUS(x);
printf("Main Process %d is done. Child %d slept for %d sec\n", getpid(), n, status);
exit(0);

}
