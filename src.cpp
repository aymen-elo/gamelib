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
    coll.installedGamesNumber = 1;
    coll.maxMemory = maxMemo;

    return coll;
}

float occupiedSize(collection_t coll){
    float size = 0.0;
    for(int i = 0; i < coll.installedGamesNumber; i++){
        if(coll.collection[i]->isInstalled)
            size += coll.collection[i]->game->size;
    }

    return size;
}

void addGame(game_t & game, collection_t & coll){

    if((coll.maxMemory - occupiedSize(coll)) < game.size){
        cout<<"Not enough storage"<<endl;
        return;
    }

    personalGame_t** temp = new personalGame_t*[coll.gamesNumber + 1];

    /**i=1 because we have the ghostGame in the beggining**/
    for(int i = 1; i < coll.installedGamesNumber; i++){
        temp[i] = coll.collection[i];
    }
    
    *temp[coll.installedGamesNumber] = {0, 0, &game, false};
    
    for(int i = coll.installedGamesNumber+1; i < coll.gamesNumber; i++){
        temp[i] = coll.collection[i];
    }
}

void desallocation(collection_t coll){
    for(int i = 0; i < coll.gamesNumber; i++){
        delete coll.collection[i]; 
    }
    delete[] coll.collection;
}

int main(){
    
}