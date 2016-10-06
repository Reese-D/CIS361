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
  char *word =  "thisisatest\0";
  if(strcmp("thisiaet\0",removeDuplicates(word))){
    fprintf(stderr, "remove duplicates does not work properly\n");
  }
  char *word2 = "iiiiiiiiiiiiiii\0";
  if(strcmp("i", removeDuplicates(word2))){
    fprintf(stderr, "all i's failed for removeDuplicates\n");
  }
  return 0;
}

int testTargetFound(){
  char *word = "abcdefghij\0";
  if(!targetFound(word, 5, 'j')){
    fprintf(stderr, "faulty find of char in string\n");
  }

  if(targetFound(word, 9, 'j')){
    fprintf(stderr,  "target not found when it should be\n");
  }

  //  if(targetFound(word, -1, 'j')){
  //    fprintf(stderr, "targetfound shouldn't pass with negative values\n");
  //  }
  return 0;
}

int testInitializeEncryptArray(){
  char *word =  "thisisatest\0";
  char *returnVal;
  returnVal = initializeEncryptArray(word);
  if(strcmp("thisaezyxwvurqponmlkjhgfdcb\0", returnVal)){
    fprintf(stderr, "encrypt not working correctly with complex string\n");
    fprintf(stderr, "%s\n", returnVal);
  }
  char *word2 = "iiiiiiiiiiiiiii\0";

  initializeEncryptArray(word2);
  if(strcmp("izyxwvutsrqponmlkjhgfedcba", returnVal)){
    fprintf(stderr, "simple encrypt not working\n");
  }
  return 0;
}
