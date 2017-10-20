void add_song(struct song_node *);
struct song_node * search_song(char song[], char artist[]);
struct song_node * search_artist(char artist[]);
void print_entries(char letter);
void print_songs(char artist[]);
void print_library();
void shuffle();
struct song_node * delete_song(struct song_node *);
struct song_node * delete_everything();   