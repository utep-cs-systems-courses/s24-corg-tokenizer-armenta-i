#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/*s_Item item_one = {1, "hello world ams", NULL};
  s_Item item_two = {2, "bye world ams" , NULL};
  List item_list;
  item_list.root = item_one;
  item_one.next = item_two;
*/

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;

int main() {
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
}

/* Initialize the linked list to keep the history. */
List *init_history(){

  List *history_list = (List * )malloc(sizeof(List));
  if(history_list != NULL){
    history_list->root = NULL; //Initialize empty root
  }
}

//Function to add string to list
void add_history(List *list, char *str){
  if(list == NULL || str == NULL){
    return NULL;
  }

  if(list->root == NULL){
    list->root = str; //put str on root if list is emtpy
  } else{
    //Have to traverse list to find where to put str
    char *currItem = list->root;
    while(currItem->next != NULL){
      currItem = currItem->next;
    }
    currItem = currItem->next;
  }
  
}

/* Retrieve the string stored in the node where Item->id == id.                                                        
   List* list - the linked list                                                                                        
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  if(list == NULL){
    return;
  }

  
}

/*Print the entire contents of the list. */
void print_history(List *list){
  if(list->root == NULL){
    printf("Empty history");
    return;
  }

  char *currItem = list->root;
  printf("History: ");
  while(currItem != NULL){
    printf("(%d , %s) --",current->id, current->str);
  }
  printf("------------------");
}

/*Free the history list and the strings it references. */
void free_history(List *list){
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
