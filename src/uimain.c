#include <stdio.h>
#include <string.h>
#include "tokenizer.h"

char userInput[50];
//Array user to store user input
char *token;
// pointer to keep track of token in strings

int  main(){
  printf("Enter the string you want to tokenize:\n$");
  fgets(userInput, sizeof(userInput), stdin);
  printf("%s\n",userInput);

  /*while((token = token_start(userInput)) != NULL){
    printf("%s", token);
    token = token;
    }*/

}
