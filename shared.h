#ifndef SHARED_H
#define SHARED_H

#include <ctype.h>
#include <getopt.h>
#include <signal.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

enum procState { idle, want_in, in_cs };

struct SharedProcessMemory {
  size_t total;   //total number of programs in at a time
  pid_t pidIP;    //program ID to be in process
  bool ready;     //procress is ready tp go
  bool complete;  //is process done?
  int nDepth;     //depth of the node
  int value;      //actual integer value
  state State;    //flag state to enter critical section
};



void usage(char **);
void touchFile(char*);

#endif
