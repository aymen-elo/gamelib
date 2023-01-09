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

void deallocation(collection_t coll){
    for(int i = 0; i < coll.gamesNumber; i++){
        delete coll.collection[i]; 
    }
    delete[] coll.collection;
}

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

    coll.gamesNumber = 1;
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

personalGame_t** allocatePersonalGamesArray(size_t newSize){
    
    personalGame_t** newPersonalGamesArray = new personalGame_t*[newSize];

    for(int i = 0; i < newSize; i++){
        newPersonalGamesArray[i] = new personalGame_t;
    }

    return newPersonalGamesArray;
}


/* TODO: Check if game is already there */
void addGame(game_t & game, collection_t & coll){

    if((coll.maxMemory - occupiedSize(coll)) < game.size){
        cout<<"Not enough storage"<<endl;
        return;
    }

    for(int i = 1; i < coll.gamesNumber; i++){
        
        if(coll.collection[i]->game == &game){
            
            if(coll.collection[i]->isInstalled){
                cout<<"The game is already installed"<<endl;
            }else{
                cout<<"The game is already in your library"<<endl;
            }

        }
    }

    
    personalGame_t** temp = allocatePersonalGamesArray(coll.gamesNumber + 1);

    /**i=1 because we have the ghostGame in the beggining**/
    for(int i = 1; i < coll.installedGamesNumber; i++){
        temp[i] = coll.collection[i];
    }
    
    *temp[coll.installedGamesNumber] = {0, 0, &game, false};
    
    for(int i = coll.installedGamesNumber+1; i < coll.gamesNumber; i++){
        temp[i] = coll.collection[i];
    }

    deallocation(coll);
    coll.collection = temp;
    coll.gamesNumber++;

}


/* TODO: check if game is in installed part*/
void installGame(game_t & game, collection_t & coll){

    for(int i = coll.installedGamesNumber; i < coll.installedGamesNumber; i++){
        if(coll.collection[i]->game == &game){
            coll.collection[i]->isInstalled = true;
            return;
        }
    }
    
    cout<<"Game not found, you need to add it to the collection to be able to install it"<<endl;
}


void displayGame(game_t* game){
    string str = "                     ";
    cout<<"Title: "<<game->title<<str<<"Released: "<<game->releaseYear<<str<<"Size: "<<game->size<<" GB"<<endl;
}

void displayGameStats(personalGame_t* game){
    cout<<"Playtime: "<<game->playtimeHours<<" Hours"<<"   "<<"Trophies: "<<game->trophiesNumber<<endl;
}

void displayCollection(collection_t & coll){
    cout<<endl;

    cout<<"YOUR COLLECTION: "<<endl<<endl;

    if(coll.gamesNumber == 1){
        cout<<"No games to show"<<endl;
    }else{
        cout<<"Installed games: "<<endl<<endl;
        // > 1 because we have a <ghost game>
        if(coll.installedGamesNumber > 1){
            for(int i = 1; i < coll.installedGamesNumber; i++){
                game_t* game = coll.collection[i]->game;
                displayGame(game);

                personalGame_t* myGame = coll.collection[i];
                displayGameStats(myGame);
            }
        }else{
            cout<<" no games to show..."<<endl;
        }
        cout<<endl;

        cout<<"Non installed games: "<<endl<<endl;
        if(coll.gamesNumber > 1){
            for(int i = coll.installedGamesNumber; i < coll.gamesNumber; i++){
                game_t* game = coll.collection[i]->game;
                displayGame(game);

                personalGame_t* myGame = coll.collection[i];
                displayGameStats(myGame);
            }
        }else{
            cout<<" no games to show..."<<endl;
        }
        cout<<endl;
    }


    cout<<endl;
}


int main(){
    
    cout<<"test"<<endl;
    collection_t coll = createCollection(500.0);
    
    game_t warzone = createGame("Warzone", 2020, 100.0);

    addGame(warzone, coll);

    displayCollection(coll);
    deallocation(coll);
}