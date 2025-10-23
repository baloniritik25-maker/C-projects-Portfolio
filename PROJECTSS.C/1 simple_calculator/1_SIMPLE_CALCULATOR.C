#include <stdio.h>
#include <math.h>
void print_menu();
double division(double num1,double num2);
double modulus(int num1,int num2);
int main()
{
    int choice;
    double num1, num2,result;
    while (1)
    {
        print_menu();
        scanf("%d", &choice);
        if (choice == 7)
        {
            break;
        }
        if(choice<0 || choice>7){
            fprintf(stderr,"INVALID ARGUMENT FOR MENU");
            continue;
        }
        printf("\nenter first number:- ");
        scanf("%lf", &num1);
        printf("enter second number:- ");
        scanf("%lf", &num2);
        switch(choice)
        {
            case 1:
                result=num1+num2;
                break;
            case 2:
                result=num1-num2;
                break;
            case 3:
                result=num1*num2;
                break;
            case 4:
                result=division(num1,num2);
                break;
            case 5:
                result= modulus((int)num1,(int)num2);
                break;
            case 6:
                result=pow(num1,num2);
                break;
            
            
        }
        if(!isnan(result)){
 
            printf("Result of given operation is:- %0.2lf",result);
        }
    }
}

double division(double num1,double num2){
    if(num2==0){
        fprintf(stderr,"INVALID ARGUMENT  FOR DIVISION");
        return NAN;
    }
    else{
        return num1/num2;
    }
}
double modulus(int num1,int num2){
    if(num2==0){
        fprintf(stderr,"INVALID ARGUMENT  FOR MODULUS");
        return NAN;
    }
    else{
        return  num1% num2;
    }
}
void print_menu()
{
    printf("\n\n---------------------------------------------------------------\n\n");
    printf("WELCOME TO SIMPLE CALCULATOR\n");
    printf("1. ADDITION\n2. SUBTRACTION\n3. MULTIPLICATION\n4. DIVISION\n5. MODULUS\n6. POWER\n7. EXIT\nNOW,enter your choice :-  ");
}
