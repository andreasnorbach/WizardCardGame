#ifndef DECK_H_
#define DECK_H_

#include <array>
#include <cstdlib>
#include <string.h>
#include "stdlib.h"
#include <string.h>

using namespace std;

class Deck {
    string rawDeck[] = {"H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H1", "HJ", "HQ", "HK", "HA",
                      "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S1", "SJ", "SQ", "SK", "SA",
                      "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D1", "DJ", "DQ", "DK", "DA",
                      "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C1", "CJ", "CQ", "CK", "CA"};
  public:
    Deck(); 
    ~Deck();
    int generateRandomNumber(int random);
}; 


#endif /* DECK_H_ */ 