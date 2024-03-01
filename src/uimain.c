#include <stdio.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

// pointer to keep track of token in strings
char userInput[100];
char userDecision[3];
int token_count, i;
char **user_tokens;
void flushInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(){
  //Create history for session
  List *historyList = init_history();
  
  printf("Welcome");
  
  //getting user input
 prompt:
    printf("Type one of the following:\n'!1': tokenize string | '!2' to get history | '!3 to get specific token from history | '!q' to quit\n");
    while(1){
      fgets(userDecision, sizeof(userDecision), stdin);              
    
      if(userDecision[0] == '!' && (userDecision[1] == '1' || userDecision[1] == '2' || userDecision[1] == '3' || userDecision[1] == 'q') && userDecision[2] == '\0'){
	
	if(userDecision[1] == '1'){
	  flushInputBuffer();
	  printf("Enter string you want to tokenize\n$");
	  scanf("%[^\n]", userInput);
	  user_tokens = tokenize(userInput);
	  token_count = count_tokens(userInput);
	  for(int i = 0; i <token_count; i++){
	  printf("Token [%d]: %s\n", i+1, user_tokens[i]);
	  add_history(historyList, user_tokens[i]);
	  }
	  goto prompt;
	}
	//Gets entire history
	if(userDecision[1] == '2'){
	  flushInputBuffer();
	  print_history(historyList);
	  goto prompt;
	}
	//gets specific token from history
	if(userDecision[1] == '3'){
	  int userId;
	  flushInputBuffer();
	  printf("Type id of token you want to get: ");
	  char userNum = getchar(); //get userID in char form
	  //Convert char to int
	  if(userNum >= '0' && userNum <= '9'){
	    userId = userNum - '0';
	  }
	  char *historyToken = get_history(historyList, userId);
	  printf("Token: %s\n",historyToken);
	  goto prompt;
	}
	if(userDecision[1] == 'q'){
	  printf("Exiting program...");
	  goto done;
	}
      }else{
	printf("Wrong command, try again...\n");
	flushInputBuffer();
      }
    }
    free_history(historyList); 
 done:
  return 0;
}
