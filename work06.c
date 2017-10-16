#include "struct_node.h"
#include <stdio.h>
#include <stdlib.h>

//start of functions

void print_list(struct node *list){
  while (list){
    printf("%d\n", list->i);
    list = list->next;
  }
}

struct node * insert_front(struct node *list, int data){
  struct node *new = malloc(sizeof(struct node));
  
  new->i = data;
  new->next = list;
  return new;
}

struct node * free_list(struct node *list){
  while (list){
    struct node *nextup = list->next;
    printf("freed\t%p: %d\n", list, list->i);
    free(list);
    list = nextup;
  }
  return list;
}
