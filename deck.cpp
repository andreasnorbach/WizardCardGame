#include "deck.h"


#include <random>
#include <ctime>
#include <stdio.h>
#include <string.h>
#include <functional>
#include <thread>
#include "stdlib.h"
#include "windows.h"


Deck::Deck() {
    
};

Deck::~Deck() {

};

int Deck::generateRandomNumber(int random) {
    random_device rd;
    std::mt19937::result_type seed = rd() ^ (
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::now().time_since_epoch()
                ).count() +
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::high_resolution_clock::now().time_since_epoch()
                ).count() );

    std::mt19937 gen(seed);
    std::uniform_int_distribution<unsigned> distrib(1, 52);

    for( unsigned long j = 0; j < 1; ++j )
    {
        random = distrib(gen); 
        //cout << distrib(gen) << ' ';
    }
    //cout << endl; 
  
    return random; 
};


string Deck::getDeck(string Deck[]) {

    return rawDeck[52];

};