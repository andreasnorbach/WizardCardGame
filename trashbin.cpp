// #include <iostream>
// #include <algorithm>
// #include <array>
// #include <random>
// #include <cstdlib>
// #include <chrono>
// #include <vector>
// #include <ctime>
// #include <stdio.h>
// #include <functional>
// #include <thread>
// #include <stdlib.h>
// #include <windows.h>
// #include <SDL2/SDL.h>

// #include <sqlext.h>
// #include <sqltypes.h>
// #include <sql.h>

// using namespace std;

// //MAIN FUNCTION
// int main(int args, char *argv[]) {

//   Screen screen;

//   if(screen.init() == false) {
//     cout << "Error for SDL." << endl;
//   }

//   HWND hwndButton = CreateWindow(
//     L"BUTTON",  // Predefined class; Unicode assumed
//     L"OK",      // Button text
//     WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles
//     10,         // x position
//     10,         // y position
//     100,        // Button width
//     100,        // Button height
//     m_hwnd,     // Parent window
//     NULL,       // No menu.
//     (HINSTANCE)GetWindowLongPtr(m_hwnd, GWLP_HINSTANCE),
//     NULL);      // Pointer not needed.

//   while(true) {
//     //Draw the screen
//     screen.update();

//     //Check for messages/events
//     if(screen.processEvents() == false) {
//       break;
//     }
//   }

//   cout << "Length: " <<  len << endl;

//   const string rawDeck2[] = {};

//   string savingTable[52] = {};
//   string posOutTable[52] = {};

//   cout << "savingTable: " << endl;
//   Deck Deck;

//   for (int h = 0; h < len; h++) {
//     srand((unsigned)time(0));
//     int dummyVar1;
//     bool stop = false;

//     int random = Deck.generateRandomNumber(dummyVar1);

//     for(int i=0; i < 52; i++) {
//       if(rawDeck[random] == posOutTable[i]) {
//         stop = true;
//       }
//     };

//     if(stop != true) {
//       Sleep(10);
//       savingTable[h] = rawDeck[random];
//       posOutTable[h] = savingTable[h];

//     }
//     else {
//       stop = false;
//       break;
//     }

//   };

//   for(int i=0; i < sizeof savingTable/sizeof *savingTable; i++) {
//     cout << savingTable[i] << " " << flush;
//   }

//   posOutTable->empty();

//   cout << endl;

//   //Zerstören Objekte und Beenden Bibliothekenzugriff
//   screen.close();

//   return 0;

// }

// string rawDeck[] = {"H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H1", "HJ", "HQ", "HK", "HA",
// //                       "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S1", "SJ", "SQ", "SK", "SA",
// //                       "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D1", "DJ", "DQ", "DK", "DA",
// //                       "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C1", "CJ", "CQ", "CK", "CA"};