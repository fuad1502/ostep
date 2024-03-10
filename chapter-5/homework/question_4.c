#include <stdlib.h>
#include <unistd.h>

/*
 * Observations: "v" stands for "vector", and "l" stands for "list". "e" means
 * input environment variables. "p" means search for the file in PATH.
 */

int main(int argc, char *argv[]) {
  pid_t pid = fork();
  if (pid == -1) {
    exit(-1);
  } else if (pid == 0) {
    // char *argv[] = {"ls", "-l", NULL};
    // execvp("ls", argv);

    // char *argv[] = {"ls", "-l", NULL};
    // execv("/bin/ls", argv);

    // char *argv[] = {"/bin/ls", "-l", NULL};
    // char *envp[] = {NULL};
    // execve("/bin/ls", argv, envp);

    // execlp("ls", "ls", "-l", NULL);

    // execl("ls", "ls", "-l", NULL);

    execle("/bin/ls", "/bin/ls", "-l", NULL, NULL);
  }
  return EXIT_SUCCESS;
}
