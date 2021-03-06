#include "song_node.h"

//function headers
void print_list(struct song_node *);
struct song_node * insert_front(struct song_node *, char *, char *);
struct song_node * insert_ordered(struct song_node *, char *, char *);
struct song_node * find_song(struct song_node *, char *, char *);
struct song_node * first_song(struct song_node *, char *);
struct song_node * random_song(struct song_node *);
int remove_song(struct song_node *, char *, char *);
struct song_node * free_list(struct song_node *);
