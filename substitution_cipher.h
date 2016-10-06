#ifndef SUBSTITUTION_CIPHER_H
#define SUBSTITUTION_CIPHER_H

#include <stdio.h>
#include <stdlib.h>


char *removeDuplicates(char word []);
int targetFound(char charArray[], int num, char target);
char *initializeEncryptArray(char key[]);
void initializeDecryptArray(char encrypt[], char decrypt[]);
void processInput(FILE * inf, FILE * outf, char substitute[]);

#endif
