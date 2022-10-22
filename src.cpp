#include <iostream>
using namespace std;

struct t_game{
    string title;
    int release_y;
    double size;
};

struct t_persoGame{
    int playtime_h;
    double nb_tophies;
    t_game* game;
    bool is_installed;
};

/** a collection is an pointer to an array of pointers **/
struct t_collection{
    int nb_games;
    double max_memory;
    t_persoGame** collection;
    int capa;
    int occup;
    int nb_installed;
};

int main(){
    
}