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
    string Deck rawDeck[] = {"H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H1", "HJ", "HQ", "HK", "HA",
                      "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S1", "SJ", "SQ", "SK", "SA",
                      "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D1", "DJ", "DQ", "DK", "DA",
                      "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C1", "CJ", "CQ", "CK", "CA"};
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