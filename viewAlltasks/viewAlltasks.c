#include "../tasks.h"

void viewAlltasks(Tasks task[], int taskCounter){

    switch(taskCounter){
        case 0:
            write(1,"No Tasks to view\n",sizeof("No Tasks to view\n"));
            return;
    }

    write(1,"\n===Tasks List====\n",sizeof("\n===Tasks List====\n"));

    int i = 0;

    while(i <= taskCounter - 1){

        char numbering[10];
        sprintf(numbering,"%d",i);

        write(1,numbering,strlen(numbering));
        write(1,". ",2);
        write(1,task[i].name,strlen(task[i].name));
        write(1,"\n",sizeof("\n"));

        i++;
    }
}