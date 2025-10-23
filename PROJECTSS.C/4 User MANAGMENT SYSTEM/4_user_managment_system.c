 #include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<conio.h>

#define MAX_USER 10
#define CREDENTIAL_LENGTH 30

typedef struct{
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];
}USER;
USER users[MAX_USER];
int user_count=0;

void registration();
void login();
int menu();
void password(char*);
void fgets_error(char*);
int main(){
    while(1){
        int choice;
        choice=menu();
        switch(choice){
        case 1:
         registration();
         break;
        case 2:
         login();
         
         break;
        case 3:
         printf("Exitting Programm.");
         return 0;
         break;
        default:
         printf("INVALID OPTION!!!! Please enter option from menu.\n");
         sleep(2);
         break;
        }
    }
}
int menu(){
    int option;
    printf("\n\n\n\n\n");
    printf("______ WELCOME TO USER MANAGMENT SYSTEM______\n\n");
    printf("1.Register\n");
    printf("2.Login\n");
    printf("3.Exit\n");
    printf("Select an option:- ");
    scanf("%d",&option);
    printf("\n");
    getchar();
    return option;
}
void registration(){
     if(user_count>=MAX_USER){
        printf("ALL USER HAS BEEN REGISTERED!! RESGITRATION CLOSED\n");
        sleep(2);
    }
    else{
        int index=user_count;
        printf("Register a new user\n");
        printf("Enter Username:- ");
        fgets( users[index].username, CREDENTIAL_LENGTH, stdin);
        fgets_error(users[index].username);
        printf("Enter password(masking enabled):- ");
        password(users[index].password);
        printf("\nYOU have been sucessfuluy Regiseterd as %s\n",users[index].username);
        sleep(3);

        user_count++;
    }
}
void login(){
    int CHECK_INDEX=-1;
    for(int warning=3;warning>=1;warning--){
        printf("Enter Username: ");
        char check_username[CREDENTIAL_LENGTH];
        fgets(check_username,CREDENTIAL_LENGTH,stdin);
        int index =strcspn(check_username,"\n");
        check_username[index]='\0';
        for(int i=0;i<MAX_USER;i++){
            if(strcmp(users[i].username,check_username)==0){
                 CHECK_INDEX=i;
                 break;
            }
        }
        if(CHECK_INDEX!=-1){
            printf("-----------\n");
             break;
        }
        else{
            printf("\nYou have entred wrong user name!! %d ATTEMPT left to try \n",warning-1);
        }
        
    }
    if(CHECK_INDEX!=-1){
        for(int warning=3;warning>=1;warning--){
             printf("Enter Username: %s\n",users[CHECK_INDEX].username);
             printf("Enter Password: ");
             char check_password[CREDENTIAL_LENGTH];
             password(check_password);
             if(strcmp(users[CHECK_INDEX].password,check_password)==0){
                printf("\nLOG in succesfull!! Welcome back %s\n",users[CHECK_INDEX].username);
                sleep(3);
                break;
            }
            else{
                printf("\n\nnyou have entred wrong password!! %d ATTEMPT left to try \n",warning-1);
            }
        }
    }
}
void fgets_error(char *sanjeev){
    int index=strcspn(sanjeev,"\n");
    sanjeev[index]='\0';
}
void password(char*password){
    char ch;
    int i=0;
    while(1){
        ch=_getch();
        if(ch==13){
            password[i]='\0';
            break;
        }
        else if(ch==8 && i>0){
            printf("\b \b");
            i--;
        }
        else{
            printf("*");
            password[i]=ch;
        }
    }

}