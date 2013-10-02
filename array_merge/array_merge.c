#include <stdbool.h>
#include <stdlib.h>
#include "../mergesort/mergesort.h"

int* array_merge(int num_arrays, int* sizes, int** values){
  int sum = 0;
  int i;
  int j;
  int k;
  int currentIndex = 0;
  bool unique;
  
  for(i = 0; i < num_arrays; ++i){
    sum += sizes[i];
  }
  
  int* tempArray = calloc(sum,sizeof(int));
  
  for(i = 0; i < num_arrays; ++i){
    for (j=0; j < sizes[i]; ++j){
      unique = true;
      for(k=0; k < currentIndex;++k){
	if(values[i][j] == tempArray[k]){
	  unique = false;
	}
      }
      if(unique){
	tempArray[currentIndex] = values[i][j];
	++currentIndex;
      }
    }
  }

  int* temp2Array = calloc(currentIndex, sizeof(int));
  
  for(i=0; i<currentIndex; ++i){
    temp2Array[i] = tempArray[i];
  }

  mergesort(currentIndex, temp2Array);

  int* resultArray = calloc(currentIndex + 1, sizeof(int));

  resultArray[0] = currentIndex;
  for(i = 1; i < currentIndex + 1; ++i){
    resultArray[i] = temp2Array[i-1];
  }

  free(tempArray);
  free(temp2Array);

  return resultArray;

}
