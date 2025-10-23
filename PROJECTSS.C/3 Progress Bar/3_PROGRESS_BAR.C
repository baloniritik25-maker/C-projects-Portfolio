#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
const int BAR_LENGTH=50;// total [          ] loading space
const int MAX_TASK=10;
typedef struct{
    int id;
    int progress;
    int step;
}Task;
void print_bar (Task tasks);
int main(){
    srand(time(0));
    Task tasks[MAX_TASK];
    for(int i=0;i<MAX_TASK;i++){
        tasks[i].id=i+1;
        tasks[i].progress=0;
        tasks[i].step=rand()%5+1;
    }
    int incomplete_task=1;
    while(incomplete_task){
        system("cls");
        incomplete_task=0;
        for(int i=0;i<MAX_TASK;i++){
            tasks[i].progress +=tasks[i].step;
            if(tasks[i].progress>100){
                tasks[i].progress=100;
            }
            else if(tasks[i].progress<100){
                 incomplete_task=1;
             }
            print_bar(tasks[i]);
        }
        sleep(1);
    }
    printf("\n ALL,task are completed.\n");
}
void print_bar (Task tasks){
     int BARS_TO_ShOW=( tasks.progress*BAR_LENGTH)/100; 
     printf("Task %d: [",tasks.id);
        for(int  i=0; i<BAR_LENGTH; i++){
            if( i<BARS_TO_ShOW){
                printf("=");
            }
            else{
                 printf(" ");
            }
        }
        printf("] %d%%\n",tasks.progress);
    }