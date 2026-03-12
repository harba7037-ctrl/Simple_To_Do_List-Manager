#include "../tasks.h"

void addTask(Tasks task[], int *taskCounter){

    if (*taskCounter < MAXIMUM_TASKS){

        write(1,"Enter your task plz: ",sizeof("Enter your task plz: "));

        getchar();

        fgets(task[*taskCounter].name,
              sizeof(task[*taskCounter].name),
              stdin);

        task[*taskCounter].name[
        strlen(task[*taskCounter].name) - 1] = '\0';

        (*taskCounter)++;

        write(1,"\nTask is significantly added.\n",
              sizeof("\nTask is significantly added.\n"));

    }else{

        write(1,
        "Can Not Add More Tasks! Maximum Tasks Reached!!\n",
        sizeof("Can Not Add More Tasks! Maximum Tasks Reached!!\n"));
    }
}