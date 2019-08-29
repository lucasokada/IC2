/*OBS scanf("%s", str) para strings nao admite espaço; ex: eu gosto -> espaço entre "eu" e "gosto"
para resolver o problema usa-se =======    scanf( "%[^\n]", str);  */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct type_profession{
    int profession_code;
    char profession_name[100];
    char profession_description[100];
};

typedef struct type_profession profession;



void fill_professions(struct type_profession profession[5], int *count)
{
   *count=0;
   
   //FILE * pfile;

   //pfile = fopen ("MyFileTest.txt" , "r");
    
    do{
        printf("enter the %d profession code: \n", *count + 1);
        scanf("%d", &profession[*count].profession_code);
        if(profession[*count].profession_code != -1){
            printf("enter the %d profession name: \n", *count + 1);
	    scanf("%s", profession[*count].profession_name);
            //fgets(profession[*count].profession_name, 100, pfile);
            printf("enter the %d profession description\n", *count + 1);
            scanf("%s", profession[*count].profession_description);
            //fgets(profession[*count].profession_description, 100, pfile);
            (*count)++;
        }
    }while(profession[*count].profession_code != -1 || (*count) == 4);     
}

void choose_profession(struct type_profession profession[5], int *count)
{
    int desired_code, i;
    
    do{
        printf("enter the desired profession code: \n");
        scanf("%d", &desired_code);

        if(desired_code != -1){
            for(i=0; i<(*count); i++)
            {
                if(desired_code == profession[i].profession_code){
                    printf("profession name: %s \n", profession[i].profession_name);
                    printf("profession description: %s \n", profession[i].profession_description);
                }
            }
        }
    }while(desired_code != -1);
}

int main()
{
    struct type_profession profession[5];
    int count;
    
    fill_professions(profession, &count);
    choose_profession(profession, &count);
}
