#include<stdio.h>
#include<time.h>
#include<unistd.h>// to acces function sleep
#include<stdlib.h>//to acces system{"cls"} function.
void fill_time(char [],int);
void fill_date(char[]);
int input_formate();
int main(){
    char time[50],date[100];
    int choice=input_formate();
    while(1){
        fill_time(time,choice);
        fill_date(date);
        printf("The current date is:- %s\n",date);
        printf("The current time is:- %s\n",time);
        sleep(1);// sleep for 1 second after followin all steps above.
        system("cls");// for clearing the screen
    }
}
int input_formate(){
    int choice;
    printf("CHOOSE THE TIME FORMATE.\n");
    printf("ENTER 1 FOR 24-HOUR CLOCK \n");
    printf("ENTER 2 FOR 12-Hour clock (defult)\n");
    printf("Now,make your choice (1/2):-  ");
    scanf("%d",&choice);
    return choice;
}
void fill_date(char buffer[]){
    time_t rawtime;// time_t will store all the seconds paaseed since epoch 1 jan 1970 in rawtime thats we named it rawtime cause it is not readable to us'
    struct tm*current_time; // struct tm will broke the since epoch time into day month year formatt.
    // buffer will show the time so we are giving him space of 50. 
    time(&rawtime);// now, this time will do convert the rawtime into readable time.
    current_time=localtime(&rawtime); //now rawtime is in according to our timezone.
    strftime(buffer, 100,"%A:%d:%b:%Y ",current_time);
}
void fill_time(char buffer[],int choice){
    time_t rawtime;// time_t will store all the seconds paaseed since epoch 1 jan 1970 in rawtime thats we named it rawtime cause it is not readable to us'
    struct tm*current_time; // struct tm will broke the since epoch time into day month year formatt.
    // buffer will show the time so we are giving him space of 50. 
    time(&rawtime);// now, this time will do convert the rawtime into readable time.
    current_time=localtime(&rawtime); //now rawtime is in according to our timezone.
    if(choice==1){
        strftime(buffer, 50,"%H:%M:%S ",current_time); // string_formate_time is doing store cuurent time in rawtime.
    }
    else{
        strftime(buffer, 50,"%I:%M:%S %p",current_time); // string_formate_time is doing store cuurent time in rawtime.
    }
}