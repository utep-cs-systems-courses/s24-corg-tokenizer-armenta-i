#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

// pointer to keep track of token in strings
char userInput[100];
char userDecision[3], decision;
int token_count, i, userId, c;
char **user_tokens;
void flushInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(){
  //Create history for session
  List *historyList = init_history();
  
  printf("Welcome\n");
  
  //getting user input
 prompt:
  while(1){
    printf("Type one of the following:\n'1': tokenize string | '2' to get history | '3 to get specific token from history | 'q' to quit\n");
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF){		     /* terminate on end-of-file */
      goto done;
    }
                    
      //switch to select which function to call
      switch(c){
	//tokenize is called
      case '1':
	flushInputBuffer();
          printf("Enter string you want to tokenize\n$");
          scanf("%[^\n]", userInput);
	  add_history(historyList, &userInput);
          user_tokens = tokenize(userInput);
          token_count = count_tokens(userInput);
          for(int i = 0; i <token_count; i++){
          printf("Token [%d]: %s\n", i+1, user_tokens[i]);
          }
	  break;
          
      case '2':
	//Gets entire history
          flushInputBuffer();
          print_history(historyList);
          break;
	  
      case '3':
	//gets specific token from history
	flushInputBuffer();
	printf("Type id of token you want to get: ");
	scanf("%d", &userId); //get userId in char form
	if(userId > 0){
	//Call to get_history with userId
	char *historyToken = get_history(historyList, userId);
	printf("Token: %s\n\n",historyToken);
	break;
	} else {
	  printf("Not an id");
	  break;
	}
	
      case 'q':
	printf("Exiting program...\n");
	goto done;
	free_history(historyList);
      default:
	printf("Wrong command, try again...\n");
	break;
      }	
    }
    free_history(historyList); 
 done:
  return 0;
}
