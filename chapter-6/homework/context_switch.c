#define _GNU_SOURCE
#include <bits/time.h>
#include <fcntl.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define N 1000000

int main(int argc, char *argv[]) {
  /*
   * Measure read-write duration without context switches
   */
  int pipedes[2];
  if (pipe(pipedes) != 0) {
    exit(1);
  }
  char buf[1] = {'x'};
  char data[1];
  struct timespec tp_start, tp_end;
  clock_gettime(CLOCK_MONOTONIC, &tp_start);
  for (int i = 0; i < N; i++) {
    write(pipedes[1], buf, 1);
    read(pipedes[0], data, 1);
  }
  clock_gettime(CLOCK_MONOTONIC, &tp_end);
  unsigned long long duration = (tp_end.tv_sec - tp_start.tv_sec) * 1e9 +
                                (tp_end.tv_nsec - tp_start.tv_sec);
  printf("write-read duration per iteration in single context: %lld ns\n",
         duration / N);

  int pipedes_1[2];
  int pipedes_2[2];
  if (pipe(pipedes_1) != 0) {
    exit(1);
  }
  if (pipe(pipedes_2) != 0) {
    exit(1);
  }

  /*
   * Measure read-write duration with context switches
   */
  unsigned long long total_duration;
  int pid = fork();
  if (pid == -1) {
    exit(1);
  } else if (pid == 0) {
    cpu_set_t set;
    CPU_SET(0, &set);
    if (sched_setaffinity(getpid(), sizeof(set), &set) != 0) {
      exit(1);
    }
    clock_gettime(CLOCK_MONOTONIC, &tp_start);
    for (int i = 0; i < N; i++) {
      read(pipedes_1[0], data, 1);
      write(pipedes_2[1], buf, 1);
    }
    clock_gettime(CLOCK_MONOTONIC, &tp_end);
    total_duration = (tp_end.tv_sec - tp_start.tv_sec) * 1e9 +
                     (tp_end.tv_nsec - tp_start.tv_sec);
    printf("write-read duration per iteration with context switches: %lld ns\n",
           total_duration / N);
  } else {
    cpu_set_t set;
    CPU_SET(0, &set);
    if (sched_setaffinity(getpid(), sizeof(set), &set) != 0) {
      exit(1);
    }
    clock_gettime(CLOCK_MONOTONIC, &tp_start);
    for (int i = 0; i < N; i++) {
      write(pipedes_1[1], buf, 1);
      read(pipedes_2[0], data, 1);
    }
    clock_gettime(CLOCK_MONOTONIC, &tp_end);
    total_duration = (tp_end.tv_sec - tp_start.tv_sec) * 1e9 +
                     (tp_end.tv_nsec - tp_start.tv_sec);
    printf("write-read duration per iteration with context switches: %lld ns\n",
           total_duration / N);
    wait(NULL);
  }

  /*
   * Context switch time
   */
  printf("context switch overhead per iteration: %lld ns\n",
         (total_duration - duration) / N / 2);

  return EXIT_SUCCESS;
}
