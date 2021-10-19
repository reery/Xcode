//
//  main.c
//  malloc
//
//  Created by Anne Schumann on 22.11.17.
//  Copyright © 2017 Slavko Stanic. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LIMIT 10

void askInput(int *);
void printData(int *);
int inputNumL(int, int);

static int size = 0;

int main(int argc, const char * argv[]) {
  //int * pointer_input;
  
  printf("How many int-blocks do you want to assign? ");
  size = inputNumL(1, LIMIT);

  int * restrict pointer_input = (int *) malloc(size * sizeof(int));
  printf("int * restrict pointer_input = (int *) malloc(%d * sizeof(int));\n", size);
  puts("Let's go through your Blocks and input data.");
  
  askInput(pointer_input);
  puts("Data input complete.");
  printData(pointer_input);
  puts("That was it. Calling free(pointer_input).");
  free(pointer_input);
  puts("Ah wait, let's see again if free() worked:");
  printData(pointer_input);
  puts("Nah, that didn't work, lets manipulate again and print.");
  askInput(pointer_input);
  printData(pointer_input);
  puts("Finished.");
  //free(pointer_input);
  
  return 0;
}

void askInput(int * input){
  int i;
  
  printf("You have asked for %d fields of data.\n", size);
  
  for(i = 0; i < size; i++){
    printf("Field %d of %d: ", i + 1, size);
    scanf(" %d", &input[i]);
  }
}

void printData(int * data){
  int i;
  puts("Your data:");
  
  for(i = 0; i < size; i++){
    printf("%2d | %2d\n", i + 1, data[i]);
  }
}

int inputNumL(int min, int max){
  _Bool valid_input = 0;
  int input = 0;
  
  while(valid_input == 0){
    if(scanf(" %d", &input) == 1){
      if(input < min || input > max){
        printf("Oops, number should be between %d and %d. Try again: ", min, max);
        continue;
      } else return input;
    }
    
    printf("Please type a number between %d and %d: ", min, max);
    while(getchar() != '\n')
      continue;
    valid_input = 0;
  }
  
  return input;
}
