#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/*s_Item item_one = {1, "hello world ams", NULL};
  s_Item item_two = {2, "bye world ams" , NULL};
  List item_list;
  item_list.root = item_one;
  item_one.next = item_two;
*/

/*int main() {
  // Create a new list
  List *myList = init_history();

  // Add items to the list
  addHistory(myList, createItem( "First Item"));
  addHistory(myList, createItem(2, "Second Item"));
  addHistory(myList, createItem(3, "Third Item"));

  // Print the contents of the list
  printList(myList);

  // Free the memory used by the list and its items
  freeList(myList);

  return 0;
  }*/

// Create item that goes in linked list
Item *newItem(int id, char *str){
  Item *newItem = (Item *)malloc(sizeof(Item)); //Allocate space for newItemc
  if(newItem != NULL){
    newItem->id = id;

    size_t stringLen = 0;
    while(str[stringLen] != '\0'){
      stringLen++;
    }
    //Allocating memory for string and copying it 
    newItem->str = (char *)malloc(sizeof(stringLen + 1));
    if(newItem->str != NULL){
      //Copy string by char
      for(int i = 0; i < stringLen;i++){
	newItem->str[i] = str[i];
      }
    } else{
      free(newItem);
      return NULL;
    }

    newItem->next = NULL;
  }
  return newItem;
}
/* Initialize the linked list to keep the history. */
List *init_history(){

  List *history_list = (List *)malloc(sizeof(List));
  if(history_list != NULL){
    history_list->root = NULL; //Initialize empty root
  }
  return history_list;
}

//Function to add string to list
void add_history(List *list, char *str){
  Item *newStr = (Item *)malloc(sizeof(Item));

  //Assigning newList
  if(newStr != NULL){
    newStr->id = 0;  //need to decide which id goes in
    newStr->str = str; //string goes into newStr
    newStr->next = NULL; //newStr is last item on list so next is null
  }
  
  if(list->root == NULL){
    list->root = newStr; //put str on root if list is emtpy
  } else{
    //Have to traverse list to find where to put str
    Item *currStr = list->root;
    while(currStr->next != NULL){
      currStr = currStr->next;
    }
    currStr->next = newStr;
  }  
}

/* Retrieve the string stored in the node where Item->id == id.                                                        
   List* list - the linked list                                                                                        
   int id - the id of the Item to find */
/*char *get_history(List *list, int id){
  if(list == NULL){
    return;
  }

  
}
*/
/*Print the entire contents of the list. */
void print_history(List *list){
  Item *currItem = (Item *)malloc(sizeof(Item));
  if(list->root == NULL){
    printf("Empty history");
    return;
  }

  currItem = list->root;
  printf("History: ");
  while(currItem != NULL){
    printf("(%d , %s) --",currItem->id, currItem->str);
  }
  printf("------------------");
}

/*Free the history list and the strings it references. */
/*void free_history(List *list){
  if(list == NULL){
    return;
  }

  char *currItem = list->root; //Get head of list
  while(currItem != NULL){
    char *nextItem = currItem->next; //pointer to move through list
    free(currItem->str); //Clears memory for string 
    free(currItem); //Clears memeory for current item on list
    currItem = nextItem; //currItem gets updated to next item in list
  }
  free(list); //Free entire list
}

*/
