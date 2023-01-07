#include <iostream>
using namespace std;

/** size in gigabytes **/
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
/** maxMemory in gigabytes **/
struct collection_t{
    int gamesNumber;
    int installedGamesNumber;
    float maxMemory;
    personalGame_t** collection;
};

game_t createGame(string title, int releaseY, float size){
    game_t game = {title, releaseY, size};
    return game;
}

/*
** ghostGame to access an actually allocated array when
** needed even when there are no games in the collection
*/
game_t g_ghostGame = createGame("nullgame", 2077, 0.0);

collection_t createCollection(float maxMemo){
    
    collection_t coll;
    
    coll.collection = new personalGame_t*[1];
    coll.collection[0] = new personalGame_t;
    coll.collection[0]->game = &g_ghostGame;

    coll.gamesNumber = 0;
    coll.installedGamesNumber = 0;
    coll.maxMemory = maxMemo;

    return coll;
}

void desallocation(collection_t coll){
    for(int i = 0; i < coll.gamesNumber; i++){
        delete coll.collection[i]; 
    }
    delete[] coll.collection;
}

int main(){
    
}