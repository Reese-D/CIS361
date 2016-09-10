/*******************************************************************************
 * Author(s): Reese De Wind
 * Version: 0.0
 * Created: Fri Sep  9 21:30:56 2016
 *******************************************************************************/
#include "substitution_cipher.h"

#ifdef RUN
int main(int argc, char **argv){
  return 0;
}
#endif

// remove duplicate characters in array word and return the result string
char *removeDuplicates(char word [], int size){
  char t[1] = "a";
  int a = atoi(t);
  int arraySize = size/sizeof(word[0]);
  short *alreadyFound = (short *) calloc(arraySize, sizeof(short));
  char *returnVal = (char *) malloc(size);
  int returnIndex = 0;
  
  for(int i = 0; i < arraySize; i++){
    char currentChar = word[i];
    int index = atoi(&currentChar)/a;
    
    if(!alreadyFound[index]){
      alreadyFound[index] = 1;
      returnVal[returnIndex] = currentChar;
      returnIndex++;
    }      
  }
  
  return returnVal;
}

// search the first num characters in array charArray for character target
// return a non-zero integer if found, otherwise, return 0
int targetFound(char charArray[], int num, char target){
  return -1;
}

// initialize the encrypt array with appropriate cipher letters according to the given key
void initializeEncryptArray(char key[], char encrypt[]){
  return;
}

// initialize the decrypt array with appropriate substitute letters based on the encrypt array
void initializeDecryptArray(char encrypt[], char decrypt[]){
  return;
}

// process data from the input file and write the result to the output file
// pass the encrypt array to parameter substitute if encryption is intended
// pass the decrypt array to parameter substitute if decryption is intended
void processInput(FILE * inf, FILE * outf, char substitute[]){
  return;
}
    
