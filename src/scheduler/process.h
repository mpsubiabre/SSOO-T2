
// Import used global libraries
#pragma once
#include <stdio.h>  // FILE, fopen, fclose, etc.
#include <string.h> // strtok, strcpy, etc.
#include <stdlib.h> // malloc, calloc, free, etc.

typedef enum {
  RUNNING,
  READY,
  WAITING,
  FINISHED
  } STATES;

struct process;
typedef struct process Process;

struct process{
    int pid;
    char* name;
    int id_factory;
    STATES state;
    int time_start;
    Process* next;
    int quantum;
    int rafagas[];
};

Process* process_init(int pid, char* name, int id_factory, int time_start);
//void process_destroy(Process* process);
