void add_song(struct song_node * [], struct song_node *);
struct song_node * search_song(struct song_node * [], char song[], char artist[]);
struct song_node * search_artist(struct song_node * [], char artist[]);
void print_entries(struct song_node * [], char letter);
void print_songs(struct song_node * [], char artist[]);
void print_library(struct song_node * []);
void shuffle(struct song_node * [], int length);
struct song_node * delete_song(struct song_node * [], char song[], char artist[]);
struct song_node * delete_everything(struct song_node * []);   