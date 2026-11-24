
#include "preprocessor.h"

void file_inclusion(FILE *fp1, FILE *fp2)
{
    FILE *fp;
    char line[200];
    char filename[100];
    int i;

    while(fgets(line, sizeof(line), fp1) != NULL)
    {
        if(strstr(line, "#include") != NULL)
        {
            i = 0;

            char *p = strchr(line, '<');

            if(p != NULL)
            {
                p++;

                while(*p != '>' && *p != '\0')
                {
                    filename[i] = *p;
                    i++;
                    p++;
                }

                filename[i] = '\0';

                fp = fopen(filename, "r");

                if(fp != NULL)
                {
                    while(fgets(line, sizeof(line), fp) != NULL)
                        fputs(line, fp2);

                    fclose(fp);
                }
                else
                {
                    printf("Cannot open included file\n");
                }
            }
        }
        else
        {
            fputs(line, fp2);
        }
    }
}
