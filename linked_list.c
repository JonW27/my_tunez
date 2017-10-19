#include "song_node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//start of functions

void print_list(struct song_node *list){
  while (list){
    printf("%s -- %s\n", list->name, list->artist);
    list = list->next;
  }
}

struct song_node * insert_front(struct song_node *list, char *name, char *artist){
  struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));

  strcpy(new->name, name);//dest, src
  strcpy(new->artist, artist);
  new->next = list;
  return new;
}

struct song_node * insert_ordered(struct song_node *list, char *name, char *artist){
  struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));

  strcpy(new->name, name);
  strcpy(new->artist, artist);
  while ( strcmp(new->name, list->name) > 0 ){
    if( strcmp(new->name, list->next->name) < 0 ){
      new->next = list->next;
      list->next = new;
      break;
    }
    list = list->next;
  }
  return new;
}

struct song_node * find_song(struct song_node *list, char *name, char *artist){
  while (list){
    if (strcmp(list->name, name) == 0 && strcmp(list->artist, artist) == 0){
      return list;
    }
    list = list->next;
  }
  return list;
}

struct song_node * first_song(struct song_node *list, char *artist){
  while (list){
    if (strcmp(list->artist, artist) == 0){
      return list;
    }
    list = list->next;
  }
  return list;
}

struct song_node * random_song(struct song_node *list){
  int num_songs = 0;
  struct song_node *temp = list;
  while (temp){
    num_songs++;
    temp = temp->next;
  }
  srand(time(NULL));
  int r = rand() % num_songs;
  while (r != 0){
    list = list->next;
    r--;
  }
  return list;
}

int remove_song(struct song_node *list, char *name, char *artist){
  if (!find_song(list, name, artist)){
    return -1;
  }
  while ( strcmp(name, list->name) > 0 ){
    if( strcmp(name, list->next->name) == 0 ){
      list->next = list->next->next;
      return 1;
    }
    list = list->next;
  }
  return 0; //should not get to this point
}

struct song_node * free_list(struct song_node *list){
  while (list){
    struct song_node *nextup = list->next;
    printf("freed %p: %s -- %s\n", list, list->name, list->artist);
    free(list);
    list = nextup;
  }
  return list;
}
