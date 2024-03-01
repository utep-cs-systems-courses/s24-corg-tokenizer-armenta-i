#include <stdio.h>
#include <stdlib.h>
#include "history.h"


/*int main() {
  
  // Testing init_history function
  List *myList = init_history();
      
  //Testing add_history function
  add_history(myList, "First");
  add_history(myList, "Second");
  add_history(myList, "Third");

  //Testing get_history
  char *saver = get_history(myList,2);
  printf("ID: 2%s\n", saver);
  //Testing print_history function
  print_history(myList);

  //Testing free_history function
  free_history(myList);
  
  return 0;
  }*/

/* Initialize the linked list to keep the history. */
List *init_history(){
  //Allocating space for string
  List *history_list = (List *)malloc(sizeof(List));
  if(history_list != NULL){
    history_list->root = NULL; //Initialize empty root
  }
  return history_list;
}

//Function to add string to list
void add_history(List *list, char *str){
  static int num_id = 1;
  
  Item *newStr = (Item *)malloc(sizeof(Item));
  if(list == NULL){ //This if statement checks to see if list is empty
    fprintf(stderr, "memory allocation failed\n");
    return;
  }

  int len = 0;
  //Get lenght of string
  while (str[len] != '\0'){
    len++;
  }

  //allocated memory for string on new item
  newStr->str = (char *)malloc((len + 1)*(sizeof(char)));
  if(newStr == NULL){
    fprintf(stderr, "Failed to create memory for newStr");
  }

  //Loop to copy str by char
  for(int i = 0; i < len; i++){
    newStr->str[i] = str[i];
  }
  
   //to denote end of str
  newStr->next = NULL; //Set next item on list empy

  if(list->root == NULL){ //if list is empty
    newStr->id = num_id;
    list->root = newStr; //set root to str
  } else{
    Item *currentStr = list->root;
    //copy root to Item that is going to iterate
    while(currentStr->next != NULL){ //iterate until empty space 
      currentStr = currentStr->next;
    }
    newStr->id = currentStr->id + 1;
    currentStr->next = newStr;     
  }
  num_id++;
}

/* Retrieve the string stored in the node where Item->id == id.                                                        
   List* list - the linked list                                                                                        
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  Item *currItem = list->root;
  if(list == NULL || list->root ==NULL){
    return NULL;
  }
  //Traverse List to find item
  while(currItem != NULL){ 
    if(currItem->id == id){ //Looking for id
      return currItem->str; //Returns string that has same id as param.
    }
    currItem = currItem->next; //Move to next item in list
  }
  return NULL; //No string with matching id was found
  }

/*Print the entire contents of the list. */
void print_history(List *list){
  //Item *currItem = (Item *)malloc(sizeof(Item));
  if(list->root == NULL || list == NULL){
    printf("Empty history\n");
    return;
  }

  Item *currItem = list->root;
  printf("History: \n");
  
  while(currItem != NULL){
    if(currItem->str != NULL){
      printf("(ID:[%d] , %s)\n",currItem->id, currItem->str);
      currItem = currItem->next;
    } else {
      printf("(%d , NULL)\n",currItem->id);
    }
  }
  printf("\n------------------\n");
}

/*Free the history list and the strings it references. */
void free_history(List *list){
  Item *currItem = (Item *)malloc(sizeof(Item));
  if(list == NULL){
    return;
  }

  currItem = list->root; //Get head of list
  while(currItem != NULL){
    Item *nextItem = currItem->next; //pointer to move through list
    free(currItem->str); //Clears memory for string 
    free(currItem); //Clears memeory for current item on list
    currItem = nextItem; //currItem gets updated to next item in list
  }
  free(list); //Free entire list
}
