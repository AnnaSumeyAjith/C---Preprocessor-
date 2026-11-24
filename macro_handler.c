
#include "preprocessor.h"

char macro_name[50][50];
char macro_value[50][100];
char macro_param[50][50];
int macro_type[50];
int count = 0;

void macro_handler(FILE *fp1, FILE *fp2)
{
    char line[200];
    char name[50], word[50], part[50], arg[100];
    char *p;
    int i, j, k, r, t, found;

    while(fgets(line, sizeof(line), fp1) != NULL)
    {
        if(strncmp(line, "#define", 7) == 0)
        {
            p = line + 7;

            while(*p == ' ' || *p == '\t')
                p++;

            i = 0;

            while(*p != ' ' && *p != '\t' &&
                  *p != '(' && *p != '\0' && i < 49)
            {
                name[i++] = *p++;
            }

            name[i] = '\0';

            if(count < 50)
            {
                strcpy(macro_name[count], name);

                if(*p == '(')
                {
                    macro_type[count] = 1;
                    p++;

                    i = 0;

                    while(*p != ')' && *p != '\0' && i < 49)
                        macro_param[count][i++] = *p++;

                    macro_param[count][i] = '\0';

                    if(*p == ')')
                        p++;

                    while(*p == ' ' || *p == '\t')
                        p++;

                    strcpy(macro_value[count], p);
                }
                else
                {
                    macro_type[count] = 0;

                    while(*p == ' ' || *p == '\t')
                        p++;

                    strcpy(macro_value[count], p);
                }

                /* Remove newline from macro value */
                i = 0;

                while(macro_value[count][i] != '\0')
                {
                    if(macro_value[count][i] == '\n' ||
                       macro_value[count][i] == '\r')
                    {
                        macro_value[count][i] = '\0';
                        break;
                    }

                    i++;
                }

                count++;
            }
        }
        else
        {
            i = 0;

            while(line[i] != '\0')
            {
                if((line[i] >= 'A' && line[i] <= 'Z') ||
                   (line[i] >= 'a' && line[i] <= 'z') ||
                   (line[i] >= '0' && line[i] <= '9') ||
                   line[i] == '_')
                {
                    j = 0;

                    while((line[i] >= 'A' && line[i] <= 'Z') ||
                          (line[i] >= 'a' && line[i] <= 'z') ||
                          (line[i] >= '0' && line[i] <= '9') ||
                          line[i] == '_')
                    {
                        if(j < 49)
                            word[j++] = line[i];

                        i++;
                    }

                    word[j] = '\0';
                    found = 0;

                    for(k = 0; k < count; k++)
                    {
                        if(strcmp(word, macro_name[k]) == 0)
                        {
                            found = 1;
                            break;
                        }
                    }

                    if(found == 1 && macro_type[k] == 0)
                    {
                        fputs(macro_value[k], fp2);
                    }
                    else if(found == 1 && macro_type[k] == 1)
                    {
                        j = i;

                        while(line[j] == ' ' || line[j] == '\t')
                            j++;

                        if(line[j] == '(')
                        {
                            j++;
                            t = 0;

                            while(line[j] != ')' && line[j] != '\0')
                            {
                                if(t < 99)
                                    arg[t++] = line[j];

                                j++;
                            }

                            arg[t] = '\0';

                            if(line[j] == ')')
                            {
                                r = 0;

                                while(macro_value[k][r] != '\0')
                                {
                                    if((macro_value[k][r] >= 'A' && macro_value[k][r] <= 'Z') ||
                                       (macro_value[k][r] >= 'a' && macro_value[k][r] <= 'z') ||
                                       macro_value[k][r] == '_')
                                    {
                                        t = 0;

                                        while((macro_value[k][r] >= 'A' && macro_value[k][r] <= 'Z') ||
                                              (macro_value[k][r] >= 'a' && macro_value[k][r] <= 'z') ||
                                              (macro_value[k][r] >= '0' && macro_value[k][r] <= '9') ||
                                              macro_value[k][r] == '_')
                                        {
                                            if(t < 49)
                                                part[t++] = macro_value[k][r];

                                            r++;
                                        }

                                        part[t] = '\0';

                                        if(strcmp(part, macro_param[k]) == 0)
                                            fputs(arg, fp2);
                                        else
                                            fputs(part, fp2);
                                    }
                                    else
                                    {
                                        fputc(macro_value[k][r], fp2);
                                        r++;
                                    }
                                }

                                i = j + 1;
                            }
                            else
                            {
                                fputs(word, fp2);
                            }
                        }
                        else
                        {
                            fputs(word, fp2);
                        }
                    }
                    else
                    {
                        fputs(word, fp2);
                    }
                }
                else
                {
                    fputc(line[i], fp2);
                    i++;
                }
            }
        }
    }
}
