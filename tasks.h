#ifndef TASKS_H
#define TASKS_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAXIMUM_TASKS 200

typedef struct Tasks{
    char name[100];
} Tasks;

void addTask(Tasks task[], int *taskCounter);
void viewAlltasks(Tasks task[], int taskCounter);
void deleteTask(Tasks task[], int *taskCounter);

#endif