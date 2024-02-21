A#include <tokenizer.h>

/* Return true (non-zero) if c is a whitespace character ('\t' or ' ').
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if(c == ' ' || c == '\t'){
    return 1;
  }
  else{
    return 0;
  }
}

/* Return true (non-zero) if c is a non-white space character (not tab or space).
   Zero terminators are not printable (therefore false) */

int non_space_char(char c){
  if(isspace(c)){
    return 0;
  }
  else{
    return 1;
  }
}

/* Returns a pointer to the first character of the next space-separated token in zero-terminated str.
   Return a zero pointer if str does not contain any tokens. */
char *token_start(char *str){
  while(*str != '\0' && (*str == ' ' || *str == '\t')){
    str++;
  }
  if(*str == '\0'){
    return NULL;
  }
  return str;
}
/* Returns a pointer terminator char following *token */
char *token_terminator(char *str);

/* Counts the number of tokens in the string aargument*/
int count_tokens(char *str);

/* Return a freshly allocated new zero-terminated string containing <len> chars from <inStr>*/
char *copy_str(char *inStr, short len);

/* Returns a freshly allocated zero-terminated verctor of freshly allocated space-separated tokens form zero-terminated str.

 For example, tokenize("hello world string)" would result in:
    tokens[0] = "hello"
    tokens[1] = "world"
    tokens[2] = "string
    tokens[3] = 0
*/
char **tokenize(char *str);

/* Prints all tokens*/
void print_tokens(char **tokens);

/* Frees all tokens and the vector themx. */
void free_tokens(char **tokens);