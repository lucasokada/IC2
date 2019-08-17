#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//------------------------struct----------------------------
struct type_bank_register
{
    int account_number;
    char client_name[50];
    float bank_balance;
    int is_active;
};

//-----------------------functions---------------------------
void choose_menu(int *option)
{
    printf("-----------------MENU------------------\n");
    printf("1 - Register Account\n");
    printf("2 - View all accounts of a client\n");
    printf("3 - Remove the smaller balance account\n");
    printf("4 - Exit\n");
    printf("----------------------------------------\n");
    printf("User, choose the desired option: \n");
    scanf("%d", option);
    printf("\n \n");

}

void register_account(struct type_bank_register bank_register[], int *i) //option 1
{
    printf("enter the account number: \n");
    scanf("%d", &bank_register[*i].account_number);
    printf("enter the client name: \n");
    scanf("%s", &bank_register[*i].client_name);
    printf("enter the bank balance: \n");
    scanf("%f", &bank_register[*i].bank_balance);
    bank_register[*i].is_active = 1;
    (*i)++;
    printf("\n \n");
}

void account_client(struct type_bank_register bank_register[15], int *i)//option 2
{
    char client_name[50];
    int j, count_str = 0;

    printf("enter the client name: \n");
    scanf("%s", &client_name);
    printf("\n");
    //printf("%d\n", i);

    for(j=0 ; j<*i; j++)
    {

        if(strcmp(bank_register[j].client_name, client_name)==0){
            printf("===========================\n");
            printf("name: %s\n", bank_register[j].client_name);
            printf("code: %d\n", bank_register[j].account_number);
            printf("balance: %.2f\n", bank_register[j].bank_balance);
            printf("===========================\n");
            count_str++;
        }
    }
    if(count_str == 0){
        printf("that user doesn't have a bank account\n");
    }
    printf("\n \n");
}

void remove_smaller(struct type_bank_register bank_register[15], int *i)//option 3
{
    int j=0, flag=0;
    float smaller = 9999999999;
    
    for(j=0; j<=(*i); j++) // find the smaller balance account
    {
        if(smaller > bank_register[j].bank_balance && bank_register[j].is_active == 1){
            smaller = bank_register[j].bank_balance;
            flag = j;
        }
    }
    printf("the account of %s was removed\n", bank_register[flag].client_name);
    strcpy (bank_register[flag].client_name, "REMOVED");
    bank_register[flag].account_number = -1;
    bank_register[flag].bank_balance = -1;
    bank_register[flag].is_active = 0;

    printf("\n \n");
}

void mock_bank_register(struct type_bank_register bank_register[15])
{
    // first client
    bank_register[0].account_number = 1;
    bank_register[0].bank_balance = 100;
    bank_register[0].is_active = 1;
    strcpy(bank_register[0].client_name, "TESTE 01");

    // second client
    bank_register[1].account_number = 2;
    bank_register[1].bank_balance = 200;
    bank_register[1].is_active = 1;
    strcpy(bank_register[1].client_name, "TESTE 02");
}

//-----------------------------------------------------------------------
int main()
{
    int i=0, option, count=0;
    struct type_bank_register bank_register[15];

    //MOCK
    // i = 1;
    // mock_bank_register(bank_register);
    // remove_smaller(bank_register, &i);
    // remove_smaller(bank_register, &i);


    do{
        choose_menu(&option);

        if(option >= 1 && option <= 4){
            if(option == 1){
                register_account(bank_register, &i);
                count++;
            }else if(option == 2){
                account_client(bank_register, &i);
            }else if (option == 3){
                remove_smaller(bank_register, &i);
            }
        }
    } while(count != 14 && option != 4);
}