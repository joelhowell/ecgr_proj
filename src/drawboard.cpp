#include "utils.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

namespace utils
{
    
    void drawBoard()
    {
        


        int rows, columns, x, y;
        char board[difficulty][difficulty];

        rows = difficulty;
        columns = difficulty;

        //  Letters across top
        cout << " "; 
        for(char c = 'A'; c < difficulty + 65; c++)
            cout << setw(5) << c;
        cout << endl << endl;

        //  Display blank board with numbers in column and initialize board to '*' 
        for(int r = 0; r < rows; r++)
        {
            cout << r + 1;
            for(int c = 0; c < columns; c++)
            {
                cout << setw(5) << "*";
                board[r][c] = '*';
            }
            cout << endl << endl;
        }

        cout << endl << endl;


        string input;

        cout << "COORDINATE (EX: C4): ";
        getline(cin, input);

        x = getX(input);
        y = getY(input);

        board[x][y] = 'X';

        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < columns; c++)
            {
                cout << board[r][c];
            }
            cout << endl;
        }
        
    }


    int getY(string input)
    {  
        return (int)input.substr(0, 1)[0] - 65;
    }

    int getX(string input)
    {
        return (int)input.substr(1, 1)[0] - 49;
    }

}