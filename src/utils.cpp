#include <iostream>
#include "utils.h"

using namespace std;

namespace utils
{
    /*	Assignment of global variables */
    const std::string VERSION_INFO = "v1.0.0";
	const std::string TEAM_NAME = "Flaming Burritos";

    int difficulty = 0;

    void cls()
    {
        //	Clears screen
        system("cls");
    }
    void verticalAlign(int lines)
    {
        //	Vertically aligns using endl
        for (int i = 0; i < lines; i++)
            cout << endl;
    }

    string horizontalAlign(int n)
    {
        //	Horizontally aligns using tab
        string tab;
        for (int i = 0; i < n; i++)
            tab += "\t";
        return tab;
    }
}