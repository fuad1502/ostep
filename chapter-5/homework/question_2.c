#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

/*
 * Observations: It seems like the concurrent write works with no problem. And
 * interestingly, closing the file descriptor in a different process does not
 * affect the other.
 */

int main(int argc, char *argv[]) {
  int fd = open("question_2.txt", O_WRONLY | O_CREAT, S_IRWXU);
  pid_t pid = fork();
  if (pid == -1) {
    exit(1);
  } else if (pid == 0) {
    char str[100];
    sprintf(str, "Hello from child process (%d) to %d!\n", getpid(), fd);
    for (int i = 0; i < 10; i++) {
      write(fd, str, strlen(str));
    }
    close(fd);
  } else {
    char str[100];
    sprintf(str, "Hello from parent process (%d) to %d!\n", getpid(), fd);
    wait(NULL);
    for (int i = 0; i < 10; i++) {
      write(fd, str, strlen(str));
    }
    close(fd);
  }
  return 0;
}
