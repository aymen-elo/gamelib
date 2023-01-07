#include <iostream>
using namespace std;

struct game_t{
    string title;
    int release_y;
    double size;
};

struct personalGame_t{
    int playtime_h;
    double nb_tophies;
    game_t* game;
    bool is_installed;
};

/** a collection is a pointer to an array of pointers **/
struct collection_t{
    int nb_games;
    double max_memory;
    personalGame_t** collection;
    int capa;
    int occup;
    int nb_installed;
};

int main(){
    
}