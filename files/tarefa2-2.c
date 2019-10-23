#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct type_student_information
{
    int student_registration;
    char student_name[20];
    float grade1;
    float grade2;
};

void menu()
{
    printf("---------------MENU---------------\n");
    printf("1 - see student information\n");
    printf("2 - change student notes\n");
    printf("3 - exit\n");
    printf("-----------------------------------\n");
}

int choose_option()
{
    int option;

    printf("enter the desired option:\n");
    scanf("%d", &option);

    return option;
}

int verify_student_existence(struct type_student_information student_information[], int *count, int *exist)
{
    int i;
    *exist = 0;

    for(i=0; i<(*count); i++)
    {
        *exist = student_information[i].student_registration == student_information[*count].student_registration ? 1 : 0;
        if(*exist == 1){
            printf("this student already exits\ntry again\n");
        }
    }
}

void register_student(struct type_student_information student_information[], int *count, int *exist)
{
    char escolha;
    int verify;

    FILE *file;
    file = fopen("students.txt", "w");// creat/acces file withe write permission
    
    do{
        printf("enter the registration code:\n");
    
        do{                                                             //verify student existence
            scanf("%d", &student_information[*count].student_registration);
            verify = verify_student_existence(student_information, &count, &exist);
        }while(verify != 0);
    
        printf("enter de student name:\n");
        scanf(" %[^\n]s", student_information[*count].student_name);
        printf("enter the grade 1:\n");
        scanf("%f", &student_information[*count].grade1);
        printf("enter the grade 2:\n");
        scanf("%f", &student_information[*count].grade2);
        (*count)++;
        printf("do you want register more students? 'y' or 'n'");
        scanf("%c", &escolha);
    }while(escolha != 'n');

    fwrite(&student_information, sizeof(struct type_student_information), 1, file);
    
    fclose(file);
}



int main()
{
    int tamanho = 15, count = 0, exist;
    struct type_student_information student_information[tamanho];

    menu();
    choose_option();
    register_student(student_information,&count, &exist);
}
