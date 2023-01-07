#include <iostream>
using namespace std;

struct game_t{
    string title;
    int releaseYear;
    float size;
};

struct personalGame_t{
    int playtimeHours;
    int trophiesNumber;
    game_t* game;
    bool isInstalled;
};

/** a collection is a pointer to an array of pointers **/
struct collection_t{
    int gamesNumber;
    int installedGamesNumber;
    float maxMemory;
    personalGame_t** collection;
    int capacity;
    int occupied;
};

game_t createGame(string title, int releaseY, float size){
    game_t game = {title, releaseY, size};
    return game;
}



int main(){
    
}