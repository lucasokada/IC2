#include<stdio.h>
#include<stdlib.h>

void creat_file(FILE *file)
{
 
    char str[] = "string test -> function fgets";

        //  'r' = permission to read, 'w' = permission to write, 'a' = permission to apend
    file = fopen("test.txt", "w"); //fopen = creat a file
    fprintf(file, "first test using file in c\n");  //fprintf = write in file      
    while(fgets(str, 100, file) != NULL) //   "fgets(string_name, string_strenght, file_name)" = read strings in file 
    {
        printf("%s", str);
    }

    fclose(file); //close and save the file
    

}

int main()
{
    FILE *file; 

    creat_file(file);

    

}