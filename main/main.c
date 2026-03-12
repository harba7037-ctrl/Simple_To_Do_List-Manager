#include "../tasks.h"
int main(){
    Tasks task[MAXIMUM_TASKS];
    int taskCounter = 0;
    char choice;

    do{
        write(1,"\n======Simple To_Do_List========\n",sizeof("\n======Simple To_Do_List========\n"));
        write(1,"1. Add Task.\n",sizeof("1. Add Task.\n"));
        write(1,"2. View All Tasks.\n",sizeof("2. View All Tasks.\n"));
        write(1,"3. Delete a Task.\n",sizeof("3. Delete a Task.\n"));
        write(1,"4. Exit.\n",sizeof("4. Exit.\n"));
        write(1,"\nEnter your choice: ",sizeof("\nEnter your choice: "));
        scanf(" %c",&choice);

        switch(choice){
            case '1':
                addTask(task, &taskCounter);
                break;
            case '2':
                viewAlltasks(task, taskCounter);
                break;
            case '3':
                deleteTask(task, &taskCounter);
                break;
            case '4':
                write(1,"\nExiting the program. Ta Ta!\n",sizeof("\nExiting the program. Ta Ta!\n"));
                break;
            default:
                write(1,"\nInvalid choice! Plz try again!.\n",sizeof("\nInvalid choice! Plz try again!.\n"));
        }

    }while(choice!='4');

    return 0;
}