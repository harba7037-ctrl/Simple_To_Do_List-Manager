#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAXIMUM_TASKS 200

typedef struct Tasks{
    char name[100];
}Tasks;
// functions prototypes
void addTask(Tasks task[],int *taskCounter);
void viewAlltasks(Tasks task[], int taskCounter);
void deleteTask(Tasks task[], int *taskCounter);

int main(){
    Tasks task[MAXIMUM_TASKS];
    int taskCounter=0;
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

void addTask(Tasks task[],int *taskCounter){
    if (*taskCounter<MAXIMUM_TASKS){
        write(1,"Enter your task plz: ",sizeof("Enter your task plz: "));
        getchar();
        fgets(task[*taskCounter].name, sizeof(task[*taskCounter].name), stdin);
        task[*taskCounter].name[strlen(task[*taskCounter].name)-1]= '\0';
        (*taskCounter)++;
        write(1,"\n Task is significantly added.\n",sizeof("\n Task is significantly added.\n"));
    }else {
        write(1,"Can Not Add More Tasks! Maximum Tasks Reached!!\n",sizeof("Can Not Add Motre Tasks! Maximum Tasks Reached!!\n"));
    }
}

void viewAlltasks(Tasks task[], int taskCounter){
    //if (taskCounter==0){
    switch(taskCounter){
        case 0:
        write(1,"No Tasks to view\n",sizeof("No Tasks to view\n"));
        return;
           
    }
    write(1,"\n===Tasks List====\n",sizeof("\n===Tasks List====\n"));
    int i=0;
    while(i<=taskCounter-1){
        
        char numbering[10];
        sprintf(numbering,"%d",i);
        write(1,numbering,strlen(numbering));
        write(1,". ",2);
        write(1,task[i].name,strlen(task[i].name));
        write(1,"\n",sizeof("\n"));
        i++;
    }
    
    
}
void deleteTask(Tasks task[], int *taskCounter){
    int index;
    //if(*taskCounter==0)
    switch(*taskCounter){
        case 0:
        write(1,"\nNo Tasks To Delete.\n",sizeof("\nNo Tasks To Delete.\n"));
        return;
    }
    write(1,"Enter an idex of a task that u want to delete (0-",sizeof("Enter an idex of a task that u want to delete (0-"));
    char counters[10];
    sprintf(counters,"%d",*taskCounter-1);
    write(1,counters,strlen(counters));
    write(1,"): ",sizeof("): "));
    scanf("%d",&index);
    if(index>=0 && index<*taskCounter){
        int i=index;
        while(i<*taskCounter-1){
            task[i]=task[i+1];
            i++;
        }(*taskCounter)--;
    write(1,"\nTask Deleted Significantaly!\n",sizeof("\nTask Deleted Significantaly!\n"));
    }else{
        write(1,"\nInvalid Task index. Please try again!\n",sizeof("\nInvalid Task index. Please try again!\n"));
        
    }

}
