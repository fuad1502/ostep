#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int x = 100;
  pid_t pid = fork();
  switch (pid) {
  case -1:
    exit(1);
  case 0:
    x = 10;
    printf("Child process (%d): x = %d\n", getpid(), x);
    break;
  default:
    wait(NULL);
    printf("Parent process (%d): x = %d\n", getpid(), x);
    break;
  }
  return 0;
}
