#include "utils.h"
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

namespace utils
{
    //  Declare global variables
    char p1OutputBoard[7][7];
    char p2OutputBoard[7][7];

    char p1Board[7][7];
    char p2Board[7][7];
    
    void gameInit()
    {
        //  True random
        srand(time(NULL));

        //  Assign P1 and P2 names accordingly
        p1 = players[0];
        p2 = players[1];

        //  Clear screen
        cls();

        //  Game initialization 
        initBackgroundBoards();
        initOutputBoards();

        //  Run Game
        game();
    }

    void game()
    {
        //  Declare local variable 
        int turn = 0;

        //  Continue game while P1 and P2 total hits are less than maximum allowed hits on a single board
        while(hits1 != maxHits && hits2 != maxHits)
        {
            if(turn % 2 == 0)
            {
                //  P1 Turn
                getCoords(p1);
                turn++;
            }
            else
            {
                //  P2 turn
                getCoords(p2);
                turn++;
            }  
        }

        //  TODO: PRETTY WIN SCREEN

        //  Output which player won!
        if(hits1 == maxHits)
        {
            cout << "CONGRATULATIONS " << p1 << " YOU WIN!";        
        }
        
        if(hits2 == maxHits)
        {
            cout << "CONGRATULATIONS " << p2 << " YOU WIN!";
        }
    }

    void refresh()
    {
        //  This function refreshes the current viewing boards/displays hits and misses
        //  Declare local variables
        int rows, columns;

        //  Assign local variables
        rows = difficulty;
        columns = difficulty;

        //  Clear/refresh screen
        cls();

        //  P1 & P2 display board headings A B C...etc
        cout << endl << "\t" << p1 << "'s Board:" << "\t\t\t\t" << p2 << "'s Board:" << endl << endl << " ";

        for(char c = 'A'; c < difficulty + 65; c++)
            cout << setw(5) << c;
        cout << "\t\t ";

        for(char c = 'A'; c < difficulty + 65; c++)
            cout << setw(5) << c;
        cout << endl << endl;

        for(int r = 0; r < rows; r++)
        {
            //  Print row numbers
            cout << r + 1;

            //  Refresh P1 Output Board
            for(int c = 0; c < columns; c++)
            {
                cout << setw(5) << p1OutputBoard[r][c];
            }
            cout << "\t\t";
            cout << r + 1;

            //  Refresh P2 Output Board
            for(int c = 0; c < columns; c++)
            {
                cout << setw(5) << p2OutputBoard[r][c];
            }
            cout << endl << endl;
        } 
    }

    void isHit(int r, int c, string t)
    {
        //  Determine if P1 or P2 is firing and then fire on opposing board
        //  The next if statement checks for a previous hit or miss and then prompts user to try a different location
        //  If that statement is false, the board checks for a ship and updates with an 'X' if it was a successful hit and increments hits for that player, otherwise update board with an 'O'
        if(t == p2)
        {
            if(p1OutputBoard[r][c] == 'X' || p1OutputBoard[r][c] == 'O')
            {
                cout << "Hey dummy, you've already fired there!" << endl << endl; 
                getCoords(p2);
            }
            else
            {
                if(isalpha(p1Board[r][c]) != 0)
                {
                    hits2++;
                    p1OutputBoard[r][c] = 'X';
                    refresh();
                }
                else
                {
                    p1OutputBoard[r][c] = 'O';
                    refresh();
                }
            }

        }
        else
        {
            if(t == p1)
            {
                if(p2OutputBoard[r][c] == 'X' || p2OutputBoard[r][c] == 'O')
                {
                    cout << "Hey dummy, you've already fired there!" << endl << endl; 
                    getCoords(p1);
                }
                else
                {
                    if(isalpha(p2Board[r][c]) != 0)
                    {
                        hits1++;
                        p2OutputBoard[r][c] = 'X';
                        refresh();
                    }
                    else
                    {
                        p2OutputBoard[r][c] = 'O';
                        refresh();
                    }
                }

            }
        }
        
    }

    int getRandom()
    {
        //  Random between 1 and 6
        int val = (rand() % 6) + 1; 
        return val;
    }

    void initBackgroundBoards()
    {
        //  Declare local var for random value
        int random;

        //  Based on difficulty level assign background boards accordingly
        //  Each casae gets two random numbers, one for P1 and one for P2
        //  NOTE: It is possible that P1 and P2 will be assigned identical boards
        switch(difficulty)
        {
            case 5:
                random = getRandom();
                easy(random, true);

                random = getRandom();
                easy(random, false);
                break;
            case 6:
                random = getRandom();
                med(random, true);

                random = getRandom();
                med(random, false);
                break;
            case 7:
                random = getRandom();
                hard(random, true);

                random = getRandom();
                hard(random, false);
                break;
            default:
                //  User should NEVER see this
                cout << "FATAL ERROR";
                break;
        }
    }

    void easy(int randomNum, bool p1)
    {
        //  Declare local board sizes
        char board5x51[5][5];
        char board5x52[5][5];
        char board5x53[5][5];
        char board5x54[5][5];
        char board5x55[5][5];
        char board5x56[5][5];

        //  Initialize all values to null (*)
        for (int r = 0; r < 5; r++)
        {
            for (int c = 0; c < 5; c++)
            {
                board5x51[r][c] = '*';
                board5x52[r][c] = '*';
                board5x53[r][c] = '*';
                board5x54[r][c] = '*';
                board5x55[r][c] = '*';
                board5x56[r][c] = '*';
            }
        }

        //  5x5 Board One
        board5x51[1][0] = 'S';
        board5x51[2][0] = 'S';
        board5x51[3][0] = 'S';
        board5x51[3][1] = 'D';
        board5x51[3][2] = 'D';
        board5x51[0][4] = 'B';
        board5x51[1][4] = 'B';
        board5x51[2][4] = 'B';
        board5x51[3][4] = 'B';

        //  5x5 Board Two  
        board5x52[2][0] = 'S';
        board5x52[3][0] = 'S';
        board5x52[4][0] = 'S';
        board5x52[1][2] = 'B';
        board5x52[2][2] = 'B';
        board5x52[3][2] = 'B';
        board5x52[4][2] = 'B';
        board5x52[3][4] = 'D';
        board5x52[4][4] = 'D';

        //  5x5 Board Three
        board5x53[0][1] = 'D';
        board5x53[1][1] = 'D';
        board5x53[2][2] = 'S';
        board5x53[2][3] = 'S';
        board5x53[2][4] = 'S';
        board5x53[4][1] = 'B';
        board5x53[4][2] = 'B';
        board5x53[4][3] = 'B';
        board5x53[4][4] = 'B';

        //  5x5 Board Four
        board5x54[1][0] = 'D';
        board5x54[2][0] = 'D';
        board5x54[0][2] = 'B';
        board5x54[1][2] = 'B';
        board5x54[2][2] = 'B';
        board5x54[3][2] = 'B';
        board5x54[4][2] = 'S';
        board5x54[4][3] = 'S';
        board5x54[4][4] = 'S';

        //  5x5 Board Five
        board5x55[0][0] = 'D';
        board5x55[0][1] = 'D';
        board5x55[1][4] = 'B';
        board5x55[2][4] = 'B';
        board5x55[3][4] = 'B';
        board5x55[4][4] = 'B';
        board5x55[3][0] = 'S';
        board5x55[3][1] = 'S';
        board5x55[3][2] = 'S';

        //  5x5 Board Six
        board5x56[0][3] = 'D';
        board5x56[0][4] = 'D';
        board5x56[1][2] = 'S';
        board5x56[2][2] = 'S';
        board5x56[3][2] = 'S';
        board5x56[4][0] = 'B';
        board5x56[4][1] = 'B';
        board5x56[4][2] = 'B';
        board5x56[4][3] = 'B';

        //  Check if random board needs to be assigned to P1 or P2
        //  Based off of random number assign designated player specific board
        //  Example: P1, randomNumber = 3, every value in 5x53 will be assigned to p1Board 
        if (p1 == true)
        {
            switch (randomNum)
            {
            case 1:
                for (int r = 0; r < 5; r++)
                    for (int c = 0; c < 5; c++)
                        p1Board[r][c] = board5x51[r][c];
                break;
            case 2:
                for (int r = 0; r < 5; r++)
                    for (int c = 0; c < 5; c++)
                        p1Board[r][c] = board5x52[r][c];
                break;
            case 3:
                for (int r = 0; r < 5; r++)
                    for (int c = 0; c < 5; c++)
                        p1Board[r][c] = board5x53[r][c];
                break;
            case 4:
                for (int r = 0; r < 5; r++)
                    for (int c = 0; c < 5; c++)
                        p1Board[r][c] = board5x54[r][c];
                break;
            case 5:
                for (int r = 0; r < 5; r++)
                    for (int c = 0; c < 5; c++)
                        p1Board[r][c] = board5x55[r][c];
                break;
            case 6:
                for (int r = 0; r < 5; r++)
                    for (int c = 0; c < 5; c++)
                        p1Board[r][c] = board5x56[r][c];
                break;
            }
        }
        else
        {
            switch (randomNum)
            {
            case 1:
                for (int r = 0; r < 5; r++)
                    for (int c = 0; c < 5; c++)
                        p2Board[r][c] = board5x51[r][c];
                break;
            case 2:
                for (int r = 0; r < 5; r++)
                    for (int c = 0; c < 5; c++)
                        p2Board[r][c] = board5x52[r][c];
                break;
            case 3:
                for (int r = 0; r < 5; r++)
                    for (int c = 0; c < 5; c++)
                        p2Board[r][c] = board5x53[r][c];
                break;
            case 4:
                for (int r = 0; r < 5; r++)
                    for (int c = 0; c < 5; c++)
                        p2Board[r][c] = board5x54[r][c];
                break;
            case 5:
                for (int r = 0; r < 5; r++)
                    for (int c = 0; c < 5; c++)
                        p2Board[r][c] = board5x55[r][c];
                break;
            case 6:
                for (int r = 0; r < 5; r++)
                    for (int c = 0; c < 5; c++)
                        p2Board[r][c] = board5x56[r][c];
                break;
            }
        }
    }

    void med(int randomNum, bool p1)
    {
        //  Declare local board sizes
        char board6x61[6][6];
        char board6x62[6][6];
        char board6x63[6][6];
        char board6x64[6][6];
        char board6x65[6][6];
        char board6x66[6][6];

        //  Initialize all values to null (*)
        for (int r = 0; r < 6; r++)
        {
            for (int c = 0; c < 6; c++)
            {
                board6x61[r][c] = '*';
                board6x62[r][c] = '*';
                board6x63[r][c] = '*';
                board6x64[r][c] = '*';
                board6x65[r][c] = '*';
                board6x66[r][c] = '*';
            }
        }

        //	6x6 Board One
        board6x61[0][0] = 'S';
        board6x61[1][0] = 'S';
        board6x61[2][0] = 'S';
        board6x61[0][5] = 'B';
        board6x61[1][5] = 'B';
        board6x61[2][5] = 'B';
        board6x61[3][5] = 'B';
        board6x61[5][2] = 'D';
        board6x61[5][3] = 'D';

        //	6x6 Board Two
        board6x62[2][4] = 'S';
        board6x62[3][4] = 'S';
        board6x62[4][4] = 'S';
        board6x62[1][0] = 'B';
        board6x62[1][1] = 'B';
        board6x62[1][2] = 'B';
        board6x62[1][3] = 'B';
        board6x62[3][1] = 'D';
        board6x62[3][2] = 'D';

        //	6x6 Board Three
        board6x63[0][0] = 'S';
        board6x63[0][1] = 'S';
        board6x63[0][2] = 'S';
        board6x63[4][0] = 'D';
        board6x63[5][0] = 'D';
        board6x63[3][2] = 'B';
        board6x63[3][3] = 'B';
        board6x63[3][4] = 'B';
        board6x63[3][5] = 'B';

        //	6x6 Board Four
        board6x64[0][0] = 'D';
        board6x64[0][1] = 'D';
        board6x64[0][4] = 'S';
        board6x64[1][4] = 'S';
        board6x64[2][4] = 'S';
        board6x64[4][1] = 'B';
        board6x64[4][2] = 'B';
        board6x64[4][3] = 'B';
        board6x64[4][4] = 'B';
        
        //	6x6 Board Five
        board6x65[1][1] = 'S';
        board6x65[2][1] = 'S';
        board6x65[3][1] = 'S';
        board6x65[4][1] = 'D';
        board6x65[4][2] = 'D';
        board6x65[1][5] = 'B';
        board6x65[2][5] = 'B';
        board6x65[3][5] = 'B';
        board6x65[4][5] = 'B';

        //	6x6 Board Six
        board6x66[2][5] = 'S';
        board6x66[3][5] = 'S';
        board6x66[4][5] = 'S';
        board6x66[4][0] = 'B';
        board6x66[4][1] = 'B';
        board6x66[4][2] = 'B';
        board6x66[4][3] = 'B';
        board6x66[1][3] = 'D';
        board6x66[1][4] = 'D';
        
        //  Check if random board needs to be assigned to P1 or P2
        //  Based off of random number assign designated player specific board
        //  Example: P1, randomNumber = 3, every value in 5x53 will be assigned to p1Board 
        if (p1 == true)
        {
            switch (randomNum)
            {
            case 1:
                for (int r = 0; r < 6; r++)
                    for (int c = 0; c < 6; c++)
                        p1Board[r][c] = board6x61[r][c];
                break;
            case 2:
                for (int r = 0; r < 6; r++)
                    for (int c = 0; c < 6; c++)
                        p1Board[r][c] = board6x62[r][c];
                break;
            case 3:
                for (int r = 0; r < 6; r++)
                    for (int c = 0; c < 6; c++)
                        p1Board[r][c] = board6x63[r][c];
                break;
            case 4:
                for (int r = 0; r < 6; r++)
                    for (int c = 0; c < 6; c++)
                        p1Board[r][c] = board6x64[r][c];
                break;
            case 5:
                for (int r = 0; r < 6; r++)
                    for (int c = 0; c < 6; c++)
                        p1Board[r][c] = board6x65[r][c];
                break;
            case 6:
                for (int r = 0; r < 6; r++)
                    for (int c = 0; c < 6; c++)
                        p1Board[r][c] = board6x66[r][c];
                break;
            }
        }
        else
        {
            switch (randomNum)
            {
            case 1:
                for (int r = 0; r < 6; r++)
                    for (int c = 0; c < 6; c++)
                        p2Board[r][c] = board6x61[r][c];
                break;
            case 2:
                for (int r = 0; r < 6; r++)
                    for (int c = 0; c < 6; c++)
                        p2Board[r][c] = board6x62[r][c];
                break;
            case 3:
                for (int r = 0; r < 6; r++)
                    for (int c = 0; c < 6; c++)
                        p2Board[r][c] = board6x63[r][c];
                break;
            case 4:
                for (int r = 0; r < 6; r++)
                    for (int c = 0; c < 6; c++)
                        p2Board[r][c] = board6x64[r][c];
                break;
            case 5:
                for (int r = 0; r < 6; r++)
                    for (int c = 0; c < 6; c++)
                        p2Board[r][c] = board6x65[r][c];
                break;
            case 6:
                for (int r = 0; r < 6; r++)
                    for (int c = 0; c < 6; c++)
                        p2Board[r][c] = board6x66[r][c];
                break;
            }
        }
    }

    void hard(int randomNum, bool p1)
    {
        //  Declare local board sizes
        char board7x71[7][7];
        char board7x72[7][7];
        char board7x73[7][7];
        char board7x74[7][7];
        char board7x75[7][7];
        char board7x76[7][7];

        //  Initialize all values to null (*)
        for (int r = 0; r < 7; r++)
        {
            for (int c = 0; c < 7; c++)
            {
                board7x71[r][c] = '*';
                board7x72[r][c] = '*';
                board7x73[r][c] = '*';
                board7x74[r][c] = '*';
                board7x75[r][c] = '*';
                board7x76[r][c] = '*';
            }
        }

        //	7x7 Board One
        board7x71[1][2] = 'D';
        board7x71[1][3] = 'D';
        board7x71[3][1] = 'B';
        board7x71[4][1] = 'B';
        board7x71[5][1] = 'B';
        board7x71[6][1] = 'B';
        board7x71[3][3] = 'S';
        board7x71[3][4] = 'S';
        board7x71[3][5] = 'S';

        //	7x7 Board Two
        board7x72[2][5] = 'D';
        board7x72[2][6] = 'D';
        board7x72[0][3] = 'B';
        board7x72[0][4] = 'B';
        board7x72[0][5] = 'B';
        board7x72[0][6] = 'B';
        board7x72[4][4] = 'S';
        board7x72[4][5] = 'S';
        board7x72[4][6] = 'S';

        //	7x7 Board Three
        board7x73[6][5] = 'D';
        board7x73[6][6] = 'D';
        board7x73[6][0] = 'B';
        board7x73[6][1] = 'B';
        board7x73[6][2] = 'B';
        board7x73[6][3] = 'B';
        board7x73[0][3] = 'S';
        board7x73[1][3] = 'S';
        board7x73[2][3] = 'S';

        //	7x7 Board Four
        board7x74[0][4] = 'D';
        board7x74[1][4] = 'D';
        board7x74[1][0] = 'B';
        board7x74[2][0] = 'B';
        board7x74[3][0] = 'B';
        board7x74[4][0] = 'B';
        board7x74[4][2] = 'S';
        board7x74[5][2] = 'S';
        board7x74[6][2] = 'S';
        
        //	7x7 Board Five
        board7x75[5][6] = 'D';
        board7x75[6][6] = 'D';
        board7x75[3][2] = 'B';
        board7x75[3][3] = 'B';
        board7x75[3][4] = 'B';
        board7x75[3][5] = 'B';
        board7x75[0][0] = 'S';
        board7x75[1][0] = 'S';
        board7x75[2][0] = 'S';

        //	7x7 Board Six
        board7x76[6][2] = 'D';
        board7x76[6][3] = 'D';
        board7x76[2][5] = 'B';
        board7x76[3][5] = 'B';
        board7x76[4][5] = 'B';
        board7x76[5][5] = 'B';
        board7x76[3][0] = 'S';
        board7x76[3][1] = 'S';
        board7x76[3][2] = 'S';
        
        //  Check if random board needs to be assigned to P1 or P2
        //  Based off of random number assign designated player specific board
        //  Example: P1, randomNumber = 3, every value in 5x53 will be assigned to p1Board 
        if (p1 == true)
        {
            switch (randomNum)
            {
            case 1:
                for (int r = 0; r < 7; r++)
                    for (int c = 0; c < 7; c++)
                        p1Board[r][c] = board7x71[r][c];
                break;
            case 2:
                for (int r = 0; r < 7; r++)
                    for (int c = 0; c < 7; c++)
                        p1Board[r][c] = board7x72[r][c];
                break;
            case 3:
                for (int r = 0; r < 7; r++)
                    for (int c = 0; c < 7; c++)
                        p1Board[r][c] = board7x73[r][c];
                break;
            case 4:
                for (int r = 0; r < 7; r++)
                    for (int c = 0; c < 7; c++)
                        p1Board[r][c] = board7x74[r][c];
                break;
            case 5:
                for (int r = 0; r < 7; r++)
                    for (int c = 0; c < 7; c++)
                        p1Board[r][c] = board7x75[r][c];
                break;
            case 6:
                for (int r = 0; r < 7; r++)
                    for (int c = 0; c < 7; c++)
                        p1Board[r][c] = board7x76[r][c];
                break;
            }
        }
        else
        {
            switch (randomNum)
            {
            case 1:
                for (int r = 0; r < 7; r++)
                    for (int c = 0; c < 7; c++)
                        p2Board[r][c] = board7x71[r][c];
                break;
            case 2:
                for (int r = 0; r < 7; r++)
                    for (int c = 0; c < 7; c++)
                        p2Board[r][c] = board7x72[r][c];
                break;
            case 3:
                for (int r = 0; r < 7; r++)
                    for (int c = 0; c < 7; c++)
                        p2Board[r][c] = board7x73[r][c];
                break;
            case 4:
                for (int r = 0; r < 7; r++)
                    for (int c = 0; c < 7; c++)
                        p2Board[r][c] = board7x74[r][c];
                break;
            case 5:
                for (int r = 0; r < 7; r++)
                    for (int c = 0; c < 7; c++)
                        p2Board[r][c] = board7x75[r][c];
                break;
            case 6:
                for (int r = 0; r < 7; r++)
                    for (int c = 0; c < 7; c++)
                        p2Board[r][c] = board7x76[r][c];
                break;
            }
        }
    }

    void initOutputBoards()
    {
        //  Declare local variables
        int rows, columns;

        //  Assign local variables
        rows = difficulty;
        columns = difficulty;

        //  P1 & P2 display board headings A B C...etc
        cout << endl << "\t" << p1 << "'s Board:" << "\t\t\t\t" << p2 << "'s Board:" << endl << endl << " ";

        for(char c = 'A'; c < difficulty + 65; c++)
            cout << setw(5) << c;
        cout << "\t\t ";

        for(char c = 'A'; c < difficulty + 65; c++)
            cout << setw(5) << c;
        cout << endl << endl;

        for(int r = 0; r < rows; r++)
        {
            //  Print row numbers
            cout << r + 1;

            //  Initialize P1 Board
            for(int c = 0; c < columns; c++)
            {
                cout << setw(5) << "*";
                p1OutputBoard[r][c] = '*';
            }
            cout << "\t\t";
            cout << r + 1;

            //  Initialize P2 Board
            for(int c = 0; c < columns; c++)
            {
                cout << setw(5) << "*";
                p2OutputBoard[r][c] = '*';
            }
            cout << endl << endl;
        }
    }

    void getCoords(string p)
    {
        //  Declare local variables
        string coord;
        bool validLocation = false;
        int row, column;

        //  Check to see if valid location on current boards
        while(validLocation == false)
        {
            //  Get coordinate to "fire" upon
            cout << "Commander " << p << ", enter firing coordinates (Ex: A4): ";
            cin >> coord;

            //  Handle lowercase and convert to uppercase
            coord[0] = toupper(coord[0]);

            //  Separate C4 into C and 4 then convert to 2, 3. 
            row = getRow(coord);
            column = getColumn(coord);

            //  Ensure input is within range otherwise continue to ask for input
            if((row > difficulty - 1 || row < 0) || (column > difficulty - 1 || column < 0))
            {
                cout << "Sorry commander, that's not a valid location! Try again." << endl << endl;
            }
            else
            {
                //  Break loop and check if hit or miss
                validLocation = true;
                isHit(row, column, p);
            }
        }     
    }

    int getColumn(string input)
    {  
        //  Returns the first val as number. EX: A3 returns as A converted into 0
        return (int)input[0] - 65;
    }

    int getRow(string input)
    {
       //  Returns the second val as number. EX: A3 returns as 3 converted into 2
       return (int)input[1] - 49;
    }
}