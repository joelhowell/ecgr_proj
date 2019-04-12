#include <iostream>
#include "utils.h"

using namespace std;

namespace utils
{
    /*	Assignment of global variables */
    const std::string VERSION_INFO = "v1.4.0";
	const std::string TEAM_NAME = "Flaming Burritos";
    
    const int maxHits = 9;
    int hits1;
    int hits2;
    int difficulty = 0;

    std::string players[2]; 
    std::string p1;
    std::string p2;

    void cls()
    {
        //	Clears screen
        system("cls");
    }
}