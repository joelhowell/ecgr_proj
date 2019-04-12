#include <iostream>
#include <string>
#include "utils.h"

using namespace std;

namespace utils
{
    void menu()
    {
        //  Declare local vars
        string input;
        bool valid = true;

        //  Title info
        cout << "Battleship by " << TEAM_NAME << " | " << VERSION_INFO << endl << "---------------------------------------" << endl;
        
        //  Get P1 and P2 names
        for(int i = 0; i < 2; i++)
        {
            cout << "Commander " << i + 1 << " enter your name: ";
            getline(cin, input);
            cout << "Welcome aboard, '" << input << "', your fleet awaits your command." << endl << endl;
            players[i] = input;
        } 
        cout << "---------------------------------------" << endl;
        
        //  Get input until valid selection
        //  Difficulty not case sensitive
        do
        {
            cout << "Please enter a difficulty: 'e' for easy, 'm' for medium, or 'h' for hard: ";
            getline(cin, input);
            
            if(input == "e" || input == "E")
            {
                cout << endl << endl << "You have selected easy difficulty." << endl;
                difficulty = 5;
                valid = true;
            }
            else
            {
                if(input == "m" || input == "M")
                {
                    cout << endl << endl << "You have selected medium difficulty." << endl;
                    difficulty = 6;
                    valid = true;
                }
                else
                {
                    if(input == "h" || input == "H")
                    {
                        cout << endl << endl << "You have selected hard difficulty." << endl;
                        difficulty = 7;
                        valid = true;
                    }
                    else
                    {
                        valid = false;
                    }
                }
            }
        } while (valid == false);  
        
        //  Run Game
        gameInit();
    }
}