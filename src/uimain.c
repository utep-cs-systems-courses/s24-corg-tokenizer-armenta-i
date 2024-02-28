#include <stdio.h>
#include <string.h>
#include "tokenizer.h"

// pointer to keep track of token in strings
char userInput[50];
//Array of tokenized user input                                                                                       
// pointer to keep track of token in strings                                                                          
int token_count, i;
char **user_tokens;

  int main(){                                            
    //getting user input
    printf("Enter the string you want to tokenize:\n$");     
    fgets(userInput, sizeof(userInput), stdin);              
    printf("%s\n",userInput);                                
                                                           
    user_tokens = tokenize(userInput);                       
    token_count = count_tokens(userInput);                                            
                                                           
    //code below is used to test for answers                 
    i=0;                                                     
    //print_tokens(user_tokens);                             
    while(i < token_count){                                 
      printf("ARRAY: %s\n", user_tokens[i]);                 
      i++;                                                   
    }                                                        
    return 0;                                                
  }

