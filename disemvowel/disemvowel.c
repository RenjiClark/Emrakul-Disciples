#include <stdlib.h>
#include <string.h>
#include "disemvowel.h"

char* disemvowel(char* str) {

  //count # vowels
  int vowelCount = 0;
  int i;
  char* disemVoweled;
  int currentIndex = 0;

  for(i=0;i<strlen(str);i++){
    if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
      vowelCount++;
    }
  }

  //allocate correct length
  disemVoweled = (char*) calloc(strlen(str) - vowelCount + 1, sizeof(str[0]));

  //copy non-vowels over
  for(i=0;i<strlen(str);i++){
    if(!(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')){
      disemVoweled[currentIndex] = str[i];
      currentIndex++;      
    }
  }

  return disemVoweled;
}
