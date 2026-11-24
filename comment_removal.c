
#include "preprocessor.h"

void rem_cmt(FILE *fp1, FILE *fp2)
{
    int ch, next, prev;

    while((ch = fgetc(fp1)) != EOF)
    {
        if(ch == '/')
        {
            next = fgetc(fp1);

            // Single-line comment
            if(next == '/')
            {
                fputc(' ', fp2);

                while((ch = fgetc(fp1)) != '\n' && ch != EOF);

                if(ch == '\n')
                    fputc('\n', fp2);
            }

            // Multi-line comment
            else if(next == '*')
            {
                fputc(' ', fp2);
                prev = 0;

                while((ch = fgetc(fp1)) != EOF)
                {
                    if(ch == '\n')
                        fputc('\n', fp2);

                    if(prev == '*' && ch == '/')
                        break;

                    prev = ch;
                }
            }

            // Normal division operator
            else
            {
                fputc('/', fp2);

                if(next != EOF)
                    fputc(next, fp2);
            }
        }
        else
        {
            fputc(ch, fp2);
        }
    }
}
