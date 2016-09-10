/*******************************************************************************
 * Author(s): Reese De Wind
 * Version: 0.0
 * Created: Fri Sep  9 20:27:16 2016
 *******************************************************************************/
#include "substitution_cipher_tests.h"
#include "substitution_cipher.h"

int main(int argc, char **argv){
  testRemoveDuplicates();
  testTargetFound();
  testInitializeEncryptArray();
}

int testRemoveDuplicates(){
  char word[11] =  "ThisIsATest";
  if(strcmp("thisiaet",removeDuplicates(word))){
    fprintf(stderr, "Remove duplicates does not work properly\n");
  }
  char word2[15] = "iiiiiiiiiiiiiii";
  if(strcmp("i", removeDuplicates(word2))){
    fprintf(stderr, "all i's failed for removeDuplicates\n");
  }
  return 0;
}

int testTargetFound(){
  char word[10] = "abcdefghij";
  if(!targetFound(word, 5, 'j')){
    fprintf(stderr, "Faulty find of char in string\n");
  }

  if(targetFound(word, 10, 'j')){
    fprintf(stderr,  "target not found when it should be\n");
  }

  if(targetFound(word, -1, 'j')){
    fprintf(stderr, "targetFound shouldn't pass with negative values\n");
  }
  return 0;
}

int testInitializeEncryptArray(){
  char word[11] =  "ThisIsATest";
  char returnVal[26];
  initializeEncryptArray(word, returnVal);
  if(strcmp("thisaezyxwvurqponmlkjhgfdcb", returnVal)){
    fprintf(stderr, "Encrypt not working correctly with complex string\n");
  }
  char word2[15] = "iiiiiiiiiiiiiii";

  initializeEncryptArray(word2,returnVal);
  if(strcmp("izyxwvutsrqponmlkjhgfedcba", returnVal)){
    fprintf(stderr, "Simple encrypt not working\n");
  }
  return 0;
}
