#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


int main(){
  // for (int i = 0; i < 2; i++){
  //   if (p == o)
  // }
  pid_t p;
  p = fork();
  if(p < 0){
  perror("fork fail");
  printf("%s\n", strerror(errno));
  exit(1);
  }
  else if (p != 0){
    pid_t p;
    p = fork();
  }
  if (p == 0){
    // random
    int fd = open("/dev/random", O_RDONLY);
    if (!fd){
      printf("%s\n", strerror(errno));
      exit(-1);
    }
    int n  = -1;
    int r = read(fd, &n, 4);
    if (!r){
      printf("%s\n", strerror(errno));
      exit(-1);
    }
    n = abs(n % 5) + 1;
    printf("%d\n", n);

  }


}
