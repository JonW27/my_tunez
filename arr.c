#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "linked_list.h"
typedef enum { false, true } bool;

void add_song(struct song_node * library[], struct song_node * node){
    int i = tolower(node->artist[0])-97; // use ascii value to get slot
    if(library[i] == NULL){
        library[i] = node;
    }
    else{
        insert_ordered(library[i], node->name, node->artist); 
    }
}

struct song_node * search_song(struct song_node * library[], char song[], char artist[]){
    struct song_node * corpus = library[tolower(artist[0])-97];
    return find_song(corpus, song, artist);
}

struct song_node * search_artist(struct song_node * library[], char artist[]){
    struct song_node * corpus = library[tolower(artist[0])-97];
    return first_song(corpus, artist);
}


void print_entries(struct song_node * library[], char letter){
    struct song_node * corpus = library[tolower(letter)-97];
    print_list(corpus);
}

void print_songs(struct song_node * library[], char artist[]){
    struct song_node * corpus = library[artist[0]-97];
    while(corpus){
        if(corpus->artist == artist){
            printf("%s by %s ", corpus->name, corpus->artist);
        }
    }
    printf("\n");
}

void print_library(struct song_node * library[]){
    int i = 0;
    for(; i<26; i++){
        print_list(library[i]);
    }
    printf("\n");
}

void shuffle(struct song_node * library[], int length){ // how many songs
    int i = 0;
    srand(time(NULL));
    for(; i < length; i++){
        int r = rand() % 26;
        struct song_node * tmp = random_song(library[r]);
        printf("%s by %s", tmp->name, tmp->artist);
    }
}

struct node * delete_song(struct song_node * library[], char song[], char artist[]){
    struct song_node * corpus = library[tolower(artist[0])-97];
    remove_song(corpus, song, artist);
    return NULL;
}

struct node * delete_everything(struct song_node * library[]){
    int i = 0;
    for(; i<26; i++){
        while(library[i]){
            free_list(library[i]);
        }
    }
    return NULL;
}