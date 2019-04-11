#include "utils.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <vector>

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
        //  Assign P1 and P2 names accordingly
        p1 = players[0];
        p2 = players[1];

        //  Clear screen
        cls();

        //  Game initialization 
        initBackgroundBoards();
        initOutputBoards();
       // refresh();
        game();
    }

    void game()
    {
        int turn = 0;

        while(hits <= maxHits)
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

    }

    void refresh()
    {

        
    }

    void isHit(int r, int c, string t)
    {
        if(t == p2)
        {
            if(p1OutputBoard[r][c] == 'X' || p1OutputBoard[r][c] == 'O')
            {
                // TODO REFRESH
                cout << "You've already fired there!"; 
            }
            else
            {
                if(isalpha(p1Board[r][c]) != 0)
                {
                    hits++;
                    p1OutputBoard[r][c] = 'X';
                    cout << "HIT!";

                    // TODO REFERSH
                }
                else
                {
                    p1OutputBoard[r][c] = 'O';
                    cout << "MISS!";

                    // TODO REFRESH
                }
            }

        }
        else
        {
            if(t == p1)
            {
                if(p2OutputBoard[r][c] == 'X' || p2OutputBoard[r][c] == 'O')
                {
                    // TODO REFRESH
                    cout << "You've already fired there!"; 
                }
                else
                {
                    if(isalpha(p2Board[r][c]) != 0)
                    {
                        hits++;
                        p2OutputBoard[r][c] = 'X';
                        cout << "HIT!";

                        // TODO REFERSH
                    }
                    else
                    {
                        p2OutputBoard[r][c] = 'O';
                        cout << "MISS!";

                        // TODO REFRESH
                    }
                }

            }
        }
        
    }

    int getRandom()
    {
        int val = rand() % 1000; 
        return val;
    }

    void initBackgroundBoards()
    {
        int random = getRandom();

        switch(difficulty)
        {
            case 5:
                easy(random);
                break;
            case 6:
                med(random);
                break;
            case 7:
                hard(random);
                break;
            default:
                cout << "FATAL ERROR";
                break;
        }
    }

    void easy(int randomNum)
    {
        //  Declare local board sizes
        char board5x51[5][5];
        char board5x52[5][5];

        //  Initialize all values to null (*)
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                board5x51[i][j] = '*';
                board5x52[i][j] = '*';                
            }
        }

        if(randomNum % 3 == 1)
        {
            //  Option 1
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

            //  Assign P1 and P2 boards accordingly
            for(int r = 0; r < 5; r++)
            {
                for(int c = 0; c < 5; c++)
                {
                    p1Board[r][c] = board5x51[r][c];
                    p2Board[r][c] = board5x52[r][c];
                }
            }
        }
        else
        {
            if(randomNum % 3 == 2)
            {
                //  Option 2
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
                board5x52[1][0] = 'D';
                board5x52[2][0] = 'D';
                board5x52[0][2] = 'B';
                board5x52[1][2] = 'B';
                board5x52[2][2] = 'B';
                board5x52[3][2] = 'B';
                board5x52[4][2] = 'S';
                board5x52[4][3] = 'S';
                board5x52[4][4] = 'S';

                //  Assign P1 and P2 boards accordingly
                for(int r = 0; r < 5; r++)
                {
                    for(int c = 0; c < 5; c++)
                    {
                        p1Board[r][c] = board5x51[r][c];
                        p2Board[r][c] = board5x52[r][c];
                    }
                }

            }
            else
            {
                //  Option 3
                //  5x5 Board One
                board5x51[0][0] = 'D';
                board5x51[0][1] = 'D';
                board5x51[1][4] = 'B';
                board5x51[2][4] = 'B';
                board5x51[3][4] = 'B';
                board5x51[4][4] = 'B';
                board5x51[3][0] = 'S';
                board5x51[3][1] = 'S';
                board5x51[3][2] = 'S';

                //  5x5 Board Two  
                board5x52[0][3] = 'D';
                board5x52[0][4] = 'D';
                board5x52[1][2] = 'S';
                board5x52[2][2] = 'S';
                board5x52[3][2] = 'S';
                board5x52[4][0] = 'B';
                board5x52[4][1] = 'B';
                board5x52[4][2] = 'B';
                board5x52[4][3] = 'B';

                //  Assign P1 and P2 boards accordingly
                for(int r = 0; r < 5; r++)
                {
                    for(int c = 0; c < 5; c++)
                    {
                        p1Board[r][c] = board5x51[r][c];
                        p2Board[r][c] = board5x52[r][c];
                    }
                }
            }
        }
    }

    void med(int randomNum)
    {

    }

    void hard(int randomNum)
    {

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
            cout << "Commander " << p << ", enter missle coordinates: ";
            cin >> coord;

            //  Handle lowercase and convert to uppercase
            coord[0] = toupper(coord[0]);

            //  Separate C4 into C and 4 then convert to 2, 3. 
            row = getRow(coord);
            column = getColumn(coord);

            //  Ensure input is within range otherwise continue to ask for input
            if((row > difficulty - 1 || row < 0) || (column > difficulty - 1 || column < 0))
            {
                cout << "Sorry commander, that's not a valid location! Try again." << endl;
            }
            else
            {
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