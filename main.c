#include <stdlib.h>
#include <stdio.h>
#include "work06.h"

//main method
int main(){
  struct node *s1 = malloc(sizeof(struct node));
  struct node *s2 = malloc(sizeof(struct node));
  
  s1->i = 1;
  s2->i = 2;
  s1->next = s2;
  s2->next = NULL;


  printf("s1: {1, s2}\n");
  printf("s2: {2, NULL}\n");

  printf("Testing print_list(s1):\n");
  print_list(s1);

  printf("Testing insert_front(s1, 3):\n");
  struct node *s3 = insert_front(s1, 3);
  print_list(s3);

  printf("Testing free_list(s3):\n");
  printf("list = %p\n", free_list(s3));
  
  return 0;
}
