#include <iostream>
#include "utils.h"

using namespace std;

namespace utils
{
    /*	Assignment of global variables */
    const std::string VERSION_INFO = "v1.0.0";
	const std::string TEAM_NAME = "Flaming Burritos";
	const std::string NAVIGATION_MSG = "Use the up and down arrows to navigate. To select, press return.";

	const int REFRESH = 150;
	const int YDOWN = 52;

	bool showHelpMenu = false;
	bool showDifficultyMenu = false;

	int menuAnimation = 60;

    void cls()
    {
        //	Clears screen
        system("cls");
    }

    void textColor(int c)
    {
        //	Changes string color
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
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

    void gotoXY(int x, int y, string msg)
    {
        //	Sets cursor at specific x/y coordinate and outputs string
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout << msg;
    }

    void xyColored(int x, int y, int c, string msg)
    {
        //	Same as gotoXY but w/color
        textColor(c);
        gotoXY(x, y, msg);
    }
}