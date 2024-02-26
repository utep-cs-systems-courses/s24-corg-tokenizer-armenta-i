#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char userInput[50];
//Array of tokenized user input
// pointer to keep track of token in strings
int token_count;

int main(){  
  printf("Enter the string you want to tokenize:\n$");
  scanf("%49[^\n]", userInput);
  printf("%s\n",userInput);

  //char **user_tokens = tokenize(userInput);
  //token_count = count_tokens(userInput);
  //printf("NUM %d", token_count);
  char* token = userInput;

  token = token_start(token);
  printf("Token: %s\n", token);
  token = token_terminator(token);
  printf("Token: %s\n", token);
  
  return 0;
}

/* Return true (non-zero) if c is a whitespace character ('\t' or ' ').
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if((c == ' ' || c == '\t') && c != '\0'){
    return 1;
  }
  else{
    return 0;
  }
}

/* Return true (non-zero) if c is a non-white space character (not tab or space).
   Zero terminators are not printable (therefore false) */

int non_space_char(char c){
  if(c == ' ' || c == '\t' || c == '\0'){
    return 0;
  }
  else{
    return 1;
  }
}

/* Returns a pointer to the first character of the next space-separated token in zero-terminated str.
   Return a zero pointer if str does not contain any tokens. */
char *token_start(char *str){
  while(*str != '\0' && space_char(*str)){
      str++;
  }
  //if string is empty return NULL
  if(*str == '\0'){
    return NULL;
  }
  //get current position of token
  char *startPos = str; //Questionable

  while(*str != '\0' && *str != ' '){
    str++;
  }
  if (*str != '\0') {
        *str = '\0';
        str++;
  }

  return startPos;
}
/* Returns a pointer terminator char following *token */
char *token_terminator(char *str){
  while(*str != '\0' && non_space_char(*str)){
    str++;
  }
  if(*str == '\0'){
    return NULL;
  }

  //char *endPost = str;
  
  while(*str != '\0' && *str != ' '){
    str++;
  }
  return str;
}


/* Counts the number of tokens in the string aargument*/
int count_tokens(char *str)
{
  int count = 0;
  char *temp;
  while(*str != '\0'){
    temp = token_start(str);
    if(temp != NULL){
      count++;
      str = token_terminator(temp);
    } else{
      break;
    }
  }
  return count;
}
/* Return a freshly allocated new zero-terminated string containing <len> chars from <inStr>*/
char *copy_str(char *inStr, short len){
  char *result = malloc((len + 1) * sizeof(char)); //memory allocation for char pointer of len + 1 for chars in inStr
  int i;
  for(i = 0; i < len; i++){
    result[i] = inStr[i];
  }
  result[i] = '\0'; // to denote string ends
  return result;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated space-separated tokens form zero-terminated str.*/

//Array of strings(Pointer to pointer)
char **tokenize(char *str){
  int total_tokens = count_tokens(str); //var to hold # of tokens
  char **token_array = malloc(sizeof(char *) * (total_tokens + 1)); //array of strings
  char *str_copy = str; //copy of str param
  int i; //counter

  for(i = 0; str_copy != NULL ;i++){
    str_copy = token_start(str_copy); //pointer for start of curr token
    char *endof_token = token_terminator(str_copy); //pointer to end of curr token
    int token_length = endof_token - str_copy;
    //Put the token into token_array
    token_array[i] = copy_str(str_copy, token_length);
    str_copy = endof_token;
    
  }
  token_array[i] = NULL; //to denote end of arr
  return token_array; //return array of strings
}

/* Prints all tokens*/
void print_tokens(char **tokens){
  int i = 0;
  while(tokens[i] != NULL){
    printf("Token %d: %s\n", i, tokens[i]);
    i++;
  }
}

/* Frees all tokens and the vector themx. */
void free_tokens(char **tokens){
  int i;
  for(i = 0; tokens[i] != NULL; i++){
    free(tokens[i]);
  }
  free(tokens);
}
