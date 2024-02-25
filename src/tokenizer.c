#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

char userInput[50];
//Array user to store user input
char *token;
// pointer to keep track of token in strings
int result;

int main(){  
  printf("Enter the string you want to tokenize:\n$");
  fgets(userInput, sizeof(userInput), stdin);
  printf("%s\n",userInput);  

  char **input_array = tokenize(userInput);
  print_tokens(input_array);
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
  while(*str != '\0' || *str != ' '){
    if(non_space_char(*str)){
	return str;
      }
    str++;
  }

  return str;
}
/* Returns a pointer terminator char following *token */
char *token_terminator(char *str){
  while(*str != '\0'){
    if(space_char(*str)){
	return str;
      }
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
    }
  }
  return count;
}
/* Return a freshly allocated new zero-terminated string containing <len> chars from <inStr>*/
char *copy_str(char *inStr, short len){
  char *result = malloc((len + 1) * sizeof(char)); //memory allocation for char pointer of len + 1 for chars in inStr
  int i;
  for(int i = 0; i < 0; i++){
    result[i] = inStr[i];
  }
  result += '\0'; // to denote that it ends
  return result;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated space-separated tokens form zero-terminated str.*/

//Array of strings(Pointer to pointer)
char **tokenize(char *str){
  int total_tokens = count_tokens(str); //var to hold # of tokens
  char **token_array = malloc(sizeof(char *) * (total_tokens + 1)); //array of strings
  char *str_copy = str; //copy of str param
  int i; //counter

  for(i = 0; i < total_tokens;i++){
    str_copy = token_start(str_copy); //pointer for start of curr token
    char *endof_token = token_terminator(str_copy); //pointer to end of curr token
    int token_length = endof_token - str_copy;
    //Put the token into token_array
    token_array[i] = copy_str(str_copy, token_length);
    str_copy = token_terminator(str_copy);
  }
  token_array += '\0'; //to denote end of arr
  //free(str_copy); //cleans pointer
  return token_array; //return array of strings
}

/* Prints all tokens*/
void print_tokens(char **tokens){
  int i = 0;
  while(tokens[i]){
    printf("Token %d%s\n", i, tokens[i]);
    i++;
  }
}

/* Frees all tokens and the vector themx. */
void free_tokens(char **tokens){
  int i = 0;
  while(tokens[i]){
    free(tokens[i]);
    i++;
  }
}
