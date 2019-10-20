#include <stdio.h>
#include <stdlib.h>

struct type_informations
{
    char street[20];
    char neighborhood[20];
    char city[20];
};

struct type_informations *fill_informations()
{
    struct type_informations *info;

    info = malloc(sizeof(struct type_informations));

    printf("street name:\n"); 
    scanf(" %[^\n]s", info->street);

    printf("neighborhood:\n");
    scanf(" %[^\n]s", info->neighborhood);

    printf("city:\n");
    scanf(" %[^\n]s", info->city);

    printf("\n\n");

    return info;
}

void print_informations(struct type_informations *info)
{
    printf("street: %s\n", info->street);
    printf("neighborhood: %s\n", info->neighborhood);
    printf("city: %s\n", info->city);
}

int main()
{
    struct type_informations *informations;
    int i;

    informations = malloc(sizeof(struct type_informations));

    informations = fill_informations();

    print_informations(informations);

    return 0;
}