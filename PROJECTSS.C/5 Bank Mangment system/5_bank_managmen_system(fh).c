#include<stdio.h>
#include<string.h>
#include<unistd.h>

typedef struct{
    char name[50];
    int acc_no;
    float balance;
}Account;
char ACCOUNT_NAME[30]="accont.dat";

int menu();
void create_account();
void Deposit_Money();
void Withraw_Money();
void Check_Balance();


int main(){
    while(1){
        int choice; 
        choice=menu();
        switch(choice)
        {
            case 1:
             create_account();
             break;
            case 2:
             Deposit_Money();
             break;
            case 3:
             Withraw_Money();
             break;
            case 4:
             Check_Balance();
             break;
            case 5:
            printf("Closing the Bank, Thanks for your visit.\n");
            return 0;
            default:
             printf("Invalid Choice!\n");
        }
    }
}
int menu(){
    int choice;
    printf("\n\n***Bank Managment System***\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    getchar();
    return choice;
}

void create_account(){
    Account acc;
    int check_account_no;
    FILE*file=fopen(ACCOUNT_NAME,"rb+");
    if(file==NULL){
        file=fopen(ACCOUNT_NAME,"wb+");
        if(file==NULL){
            printf("Unable to open file!!!");
            sleep(2);
            return;
        }
    }
    rewind(file);
    printf("Enter the account number you want: ");
    scanf("%d",&check_account_no);
    getchar();
    while(fread(&acc,sizeof(acc),1,file)){
        if(check_account_no==acc.acc_no){
            printf("Please choose another account number %d. As it is been assigned to another user!!\n ",check_account_no);
            sleep(3);
            fclose(file);
            return;
        }
    }
    fclose(file);
    FILE*ptr=fopen(ACCOUNT_NAME,"ab+");
    printf("Enter your name: ");
    fgets(acc.name,sizeof(acc.name),stdin);
    int idx=strcspn(acc.name,"\n");
    acc.name[idx]='\0';
    acc.acc_no=check_account_no;
    acc.balance= 0; 
    fwrite(&acc,sizeof(acc),1,ptr);
    fclose(ptr);
    printf("Account created succesfully!");
    sleep(2);
}
void Deposit_Money(){
   Account acc;
   FILE*file=fopen(ACCOUNT_NAME,"rb+");
   if(file==NULL){
    printf("Unable to open file!!\n");
    sleep(2);
    return;
}
   int check_acc_no;
   float amount;
   printf("Enter account number: ");
   scanf("%d",&check_acc_no);
   while(fread(&acc,sizeof(acc),1,file)){
        if(acc.acc_no==check_acc_no){
            printf("Enter amount to deposit: ");
            scanf("%f",&amount);
            getchar();
            acc.balance+=amount;
            fseek(file,-sizeof(acc),SEEK_CUR);
            fwrite(&acc,sizeof(acc),1,file);
            printf("Sucessefully deposited Rs %0.2f . New balance is Rs %0.2f ",amount,acc.balance);
            sleep(2);
            fclose(file);
            return;
        }
    }
    printf("Account number %d was not found!!",check_acc_no);
    sleep(2);
    fclose(file);
    return;
}

void Withraw_Money(){
    Account acc;
    int check_acc_no;
    float amount;
    FILE*file=fopen(ACCOUNT_NAME,"rb+");
    if(file==NULL){
        printf("Unable to open file!!");
        sleep(2);
        return;
    }
    printf("Enter account number: ");
    scanf("%d",&check_acc_no);
    while(fread(&acc,sizeof(acc),1,file)){
        if(check_acc_no==acc.acc_no){
            printf("Enter amount to withraw: ");
            scanf("%f",&amount);
            getchar();
            if(acc.balance<amount){
                printf("Insufficient balance!");
                sleep(2);
                return;
            }
            else if(acc.balance>=amount){
                fseek(file,-sizeof(acc),SEEK_CUR);
                acc.balance-=amount;
                fwrite(&acc,sizeof(acc),1,file);
                printf("Successfully withrawn Rs.%0.2f. Remaining balance is Rs.%0.2f.",amount,acc.balance);
                sleep(4);
                fclose(file);
                return;
            }
        }
    }
    fclose(file);
    printf("Account number %d was not found!!",check_acc_no);
    sleep(2);
}
void Check_Balance(){
   Account acc;
   FILE*file=fopen(ACCOUNT_NAME,"rb");
   if(file==NULL){
    printf("Unable to open the file!!");
    sleep(2);
    return;
   }
   int check_acc_no;
   printf("Enter your account no: ");
   scanf("%d",&check_acc_no);
   while(fread(&acc,sizeof(acc),1,file)){
    if(check_acc_no==acc.acc_no){
        printf("Your current balance is Rs %0.2f",acc.balance);
        sleep(2);
        fclose(file);
        return;
    }
   }
   fclose(file);
   printf("Account NO: %d was not found!!",check_acc_no);
   sleep(2);
}