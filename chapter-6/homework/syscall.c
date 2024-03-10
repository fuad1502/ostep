#include <bits/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define N 10000000

int main(int argc, char *argv[]) {
  struct timespec tp_start, tp_end;
  clock_gettime(CLOCK_MONOTONIC, &tp_start);
  for (int i = 0; i < N; i++) {
    read(STDIN_FILENO, NULL, 0);
  }
  clock_gettime(CLOCK_MONOTONIC, &tp_end);
  unsigned long long duration = (tp_end.tv_sec - tp_start.tv_sec) * 1e9 +
                                (tp_end.tv_nsec - tp_start.tv_nsec);
  printf("syscall overhead: %lld ns\n", duration / N);
  return EXIT_SUCCESS;
}
