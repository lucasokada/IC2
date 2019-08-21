/*the difference between struct and union is that, the the union is a shared memory structure. 
    Therefore, the computer will reserve a memory for the biggest variable, and tahat space will be 
    shared between that. OBS: cannot acces more than one element in the same time
                            the previous informations will be subscribed 
                            MEMORY ECONOMY!! */
                            
#include<stdio.h>
#include<stdlib.h>

union type_union_test
{
    int code;
    char name[50];
    float balance;
};

int menu(int option)
{
    
    printf("---------MENU-----------\n");
    printf("1 - register\n");
    printf("2 - see account\n");
    printf("-------------------------\n");
    printf("enter the desired option\n");
    scanf("%d", &option);

    return option;
}

int register_account(union type_union_test union_test[5], int i) //option 1
{
    i = 0;

    printf("enter the account code: \n");
    scanf("%d", &union_test[i].code);
    printf("enter the account name: \n");
    gets(union_test[i].name);
    printf("enter the balance account: \n");
    scanf("%f", &union_test[i].balance);
    i++;

    return i;
}

int main()
{
    int i, option, function;
    union type_union_test union_test[5];

    do{
        function = menu(option);
        
        if(option == 1){
            function = register_account(union_test, i);
        }

    }while(option != -1);
}
