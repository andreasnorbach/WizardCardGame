#ifndef DECK_H_
#define DECK_H_

#include <array>
#include <cstdlib>
#include <string.h>
#include "stdlib.h"
#include <string.h>

using namespace std;

class Deck {
  public:  
    string rawDeck[52];
    
  public:
    Deck(); 
    ~Deck();
    string getDeck(string Deck[]);
    int generateRandomNumber(int random);
}; 


#endif /* DECK_H_ */ 