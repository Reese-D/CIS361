/*******************************************************************************
 * Author(s): Reese De Wind
 * Version: 0.0
 * Created: Fri Sep  9 21:30:56 2016
 *******************************************************************************/
#include "substitution_cipher.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#ifdef RUN



int main(int argc, char **argv){
  if(argc != 5){
    printf("Use is: key isEncrypt inFile outFile\n");
    return -1;
  }
  char *decrypt = malloc(sizeof(char) * 27);
  char *encrypt;
  char *key = argv[1];
  FILE *inf;
  FILE *out;
  inf = fopen(argv[3], "r");
  out = fopen(argv[4], "w");

  removeDuplicates("thisisastring\0");
  encrypt = initializeEncryptArray(key);
  fprintf(stderr, "encrypt is: %s\n", encrypt);
  initializeDecryptArray(encrypt, decrypt);
  fprintf(stderr, "Decrypt: %s\n", decrypt);

  if(atoi(argv[2]) == 1){
    processInput(inf, out, encrypt);
  }else{
    processInput(inf, out, decrypt);
  }
  fclose(inf);
  fclose(out);
}
#endif

 
// remove duplicate characters in array word and return the result string
char *removeDuplicates(char word []){
  int size = strlen(word);
  int arraySize = size/sizeof(word[0]);
  short *alreadyFound = (short *) calloc(arraySize, sizeof(short));
  char *returnVal = (char *) malloc(size);
  int returnIndex = 0;
  for(int i = 0; i < arraySize; i++){
    char currentChar = word[i];
    int index = currentChar -'a';
    
    if(!alreadyFound[index]){
      alreadyFound[index] = 1;
      returnVal[returnIndex] = currentChar;
      returnIndex++;
    }else{
      returnVal[returnIndex] = '\0';
    }
  }
  return returnVal;
}

// search the first num characters in array charArray for character target
// return a non-zero integer if found, otherwise, return 0
int targetFound(char charArray[], int num, char target){
  if(num <= 0){
    return 0;
  }
  int i = 0;
  while(i < num){
    if(*(charArray + num) == target){
      return 1;
    }
    i++;
  }
  return 0;
}

// initialize the encrypt array with appropriate cipher letters according to the given key
char *initializeEncryptArray(char key[]){
  char *encrypt = malloc(sizeof(char) * (strlen(key) + 26));
  encrypt[strlen(key) + 25] = '\0';
  key = removeDuplicates(key);
  fprintf(stderr, "key is: %s\n", key);
  int length = strlen(key);
  for(int i = 0; i < length; i++){
    encrypt[i] = key[i];
  }

  for(int j = 0; j < 26; j++){
    encrypt[j + strlen(key)] = (char)('a' + j); 
  }
  return removeDuplicates(encrypt);
  
}

// initialize the decrypt array with appropriate substitute letters based on the encrypt array
void initializeDecryptArray(char encrypt[], char decrypt[]){
  for(int i = 0; i < 26; i++){
    decrypt[encrypt[i] - 'a'] = (char)('a' + i);
  }
}

// process data from the input file and write the result to the output file
// pass the encrypt array to parameter substitute if encryption is intended
// pass the decrypt array to parameter substitute if decryption is intended
void processInput(FILE * inf, FILE * outf, char substitute[]){
  char ch;
  while((ch = (char)getc(inf)) != EOF){
    if(isalpha(ch) && islower(ch)){
      putc(substitute[(int)ch - 'a'],outf);
    }else{
      putc(ch, outf);
    }
  }
}
    
