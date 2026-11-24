#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rem_cmt(FILE *fp1, FILE *fp2);
void file_inclusion(FILE *fp1, FILE *fp2);
void macro_handler(FILE *fp1, FILE *fp2);

#endif