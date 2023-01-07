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

collection_t createCollection(float maxMemo){
    collection_t coll = {0, 0, maxMemo, nullptr};
    return coll;
}


int main(){
    
}