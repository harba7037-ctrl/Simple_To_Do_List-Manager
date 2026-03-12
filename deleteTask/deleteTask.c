#include "../tasks.h"

void deleteTask(Tasks task[], int *taskCounter){

    int index;

    switch(*taskCounter){
        case 0:
            write(1,"\nNo Tasks To Delete.\n",sizeof("\nNo Tasks To Delete.\n"));
            return;
    }

    write(1,"Enter an idex of a task that u want to delete (0-",
          sizeof("Enter an idex of a task that u want to delete (0-"));

    char counters[10];
    sprintf(counters,"%d",*taskCounter - 1);

    write(1,counters,strlen(counters));
    write(1,"): ",sizeof("): "));

    scanf("%d",&index);

    if(index >= 0 && index < *taskCounter){

        int i = index;

        while(i < *taskCounter - 1){
            task[i] = task[i+1];
            i++;
        }

        (*taskCounter)--;

        write(1,"\nTask Deleted Significantaly!\n",
              sizeof("\nTask Deleted Significantaly!\n"));

    }else{

        write(1,"\nInvalid Task index. Please try again!\n",
              sizeof("\nInvalid Task index. Please try again!\n"));
    }
}