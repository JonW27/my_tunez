#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "linked_list.h"
typedef enum { false, true } bool;

struct song_node * library[26];

void add_song(struct song_node * node){
    int i = tolower(node->artist[0])-97;
    if(library[i] == NULL){
        insert_front(library[i], node->name, node->artist); // use ascii value to get slot
    }
    else{
        insert_ordered(library[i], node->name, node->artist); // use ascii value to get slot
    }
}

struct song_node * search_song(char song[], char artist[]){
    struct song_node * corpus = library[tolower(artist[0])-97];
    while(corpus){
        if(corpus->name == song){
            return corpus;
        }
        corpus++;
    }
    return NULL;
}
/*struct song_node * search_song(char song[]){
    int i = 0;
    for(; i<26; i++){
        while(library[i]){
            if(library[i]->name == song){
                return library[i];
            }
            library[i]++;
        }
    }
    return NULL;
}*/
struct song_node * search_artist(char artist[]){
    struct song_node * corpus = library[artist[0]-97];
    while(corpus){
        if(corpus->artist == artist){
            return corpus;
        }
        corpus++;
    }
    return NULL;
}


void print_entries(char letter){
    struct song_node * corpus = library[letter-97];
    while(corpus){
        printf("%s by %s ", corpus->name, corpus->artist);
    }
    printf("\n");
}

void print_songs(char artist[]){
    struct song_node * corpus = library[artist[0]-97];
    while(corpus){
        if(corpus->artist == artist){
            printf("%s by %s ", corpus->name, corpus->artist);
        }
    }
    printf("\n");
}

void print_library(){
    int i = 0;
    for(; i<26; i++){
        while(library[i]){
            printf("%s by %s ", library[i]->name, library[i]->artist);
            library[i]++;
        }
    }
    printf("\n");
}

void shuffle(int length){ // how many songs
    int i = 0;
    srand(time(NULL));
    int r = rand() % 26;
    for(; i < length; i++){
        struct song_node * tmp = random_song(library[r]);
        printf("%s by %s", tmp->name, tmp->artist);
    }
}

struct node * delete_song(char song[], char artist[]){
    struct song_node * corpus = library[song[0]-97];
    remove_song(corpus, song, artist);
    return NULL;
}

struct node * delete_everything(){
    int i = 0;
    for(; i<26; i++){
        while(library[i]){
            free_list(library[i]);
        }
    }
    return NULL;
}