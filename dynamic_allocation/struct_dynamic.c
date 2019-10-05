#include <stdio.h>
#include <stdlib.h>

struct type_informations
{
    char street[20];
    char neighborhood[20];
    char city[20];
};

int main()
{
    struct type_informations *informations;
    int i;

    informations = malloc(2 * sizeof(struct type_informations));

    if(informations == NULL){
        
        printf("cannot allocate memory\n");
        exit(1);

    }else{

        for(i=0; i<2; i++)
        {
            printf("street name:\n");
            scanf(" %[^\n]s", informations[i].street);

            printf("neighborhood:\n");
            scanf(" %[^\n]s", informations[i].neighborhood);

            printf("city:\n");
            scanf(" %[^\n]s", informations[i].city);
        }
        printf("\n\n");

        for(i=0; i<2; i++)
        {
            printf("street %d: %s\n", i, informations[i].street);
            printf("neighborhood: %s\n", informations[i].neighborhood);
            printf("city: %s\n", informations[i].city);
        }
    }

    return 0;
}