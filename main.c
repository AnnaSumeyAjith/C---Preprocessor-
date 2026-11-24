

#include "preprocessor.h"

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    char output[100];
    char *p;

    if(argc != 2)
    {
        printf("Usage: mypreprocessor inputfile.c\n");
        return 1;
    }

    strcpy(output, argv[1]);

    p = strrchr(output, '.');

    if(p != NULL)
        strcpy(p, ".i");
    else
        strcat(output, ".i");

    // File inclusion
    fp1 = fopen(argv[1], "r");
    fp2 = fopen("temp1.c", "w");

    if(fp1 == NULL || fp2 == NULL)
    {
        printf("File opening error\n");
        return 1;
    }

    file_inclusion(fp1, fp2);

    fclose(fp1);
    fclose(fp2);

    // Comment removal
    fp1 = fopen("temp1.c", "r");
    fp2 = fopen("temp2.c", "w");

    if(fp1 == NULL || fp2 == NULL)
    {
        printf("File opening error\n");
        return 1;
    }

    rem_cmt(fp1, fp2);

    fclose(fp1);
    fclose(fp2);

    // Macro substitution
    fp1 = fopen("temp2.c", "r");
    fp2 = fopen(output, "w");

    if(fp1 == NULL || fp2 == NULL)
    {
        printf("File opening error\n");
        return 1;
    }

    macro_handler(fp1, fp2);

    fclose(fp1);
    fclose(fp2);

    remove("temp1.c");
    remove("temp2.c");

    return 0;
}

