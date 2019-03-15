/************************************************************************************************************
 *																											*
 *		Project Name:		Battleship																		*
 *																											*
 *		Version:			1.0.0																			*
 *																											*
 *		Team Name:			Flaming Burritos																*
 *																											*
 *		Developers:			Joel H, Will W, Kelby P, Richard O, and Abdul E.								*
 *																											*
 *		Date Created:		3/5/2019																		*
 *																											*
 *		Last Modified:		3/15/2019																		*
 *																											*
 *		Purpose:																							*
 *																											*
 *																											*
 ***********************************************************************************************************/										

#include "pch.h"
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <Windows.h>

using namespace std;

string horizontalAlign(int n);
void cls();
void difficultySelect();
void gotoXY(int x, int y, string msg);
void helpMessage();
void helpScreen();
void init();
void menu();
void textColor(int c);
void titleSplash(int c);
void verticalAlign(int lines);
void xyColored(int x, int y, int c, string msg);

/*	Declaration of global variables  */
const string VERSION_INFO = "v1.0.0";
const string TEAM_NAME = "Flaming Burritos";
const string NAVIGATION_MSG = "Use the up and down arrows to navigate. To select, press return.";

const int REFRESH = 125;
const int YDOWN = 52;

bool showHelpMenu = false;
bool showDifficultyMenu = false;

int menuAnimation = 60;

/*  Begin Main  */
int main()
{
	/*	Game Initialization	 */
	init();

	//	Launch menu
	menu();
	//helpScreen();

	return 0;
}

void init()
{
	/*	Game Initialization	 */
	//	Clear screen
	cls();

	//	Set window title
	string winTitle = "title ~ " + TEAM_NAME + " ~ " + "Battleship [" + VERSION_INFO + "]";
	system(winTitle.c_str());

	//	Change to full screen
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}

void menu()
{
	/*	Main Menu  */
	//	Declare necessary vars for menu items, index, and tab indent
	int index = 0;
	string MenuItems[3] = { "Play", "Help", "Exit" };
	string t = horizontalAlign(13);
	string t2 = horizontalAlign(11);

	//	Clear screen
	cls();

	//	Ensure text color is default for menu items
	textColor(9);

	//	Display titleSplash title
	titleSplash(1);

	//	Properly display navigation instructions and version info, as well as relocate the cursor to original position
	xyColored(2, YDOWN, 3, NAVIGATION_MSG);
	xyColored(202, YDOWN, 3, VERSION_INFO);
	gotoXY(0, 0, "");


	while (showHelpMenu == false || showDifficultyMenu == false)
	{
		//	Only redraw menu items and not the entire screen and therefore reduce flicker
		gotoXY(0, (YDOWN / 2) + 2, "    ");

		//	Display menu items and determine what to highlight as the selected option
		for (int i = 0; i < 3; i++)
		{
			if (i == index)
			{
				textColor(12);
				cout << t << MenuItems[i] << endl << endl;
			}
			else
			{
				textColor(9);
				cout << t << MenuItems[i] << endl << endl;
			}
		}

		while (1)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				index--;
				if (index == -1)
				{
					index = 2;
				}
				break;
			}
			else
			{
				if (GetAsyncKeyState(VK_DOWN) != 0)
				{
					index++;
					if (index == 3)
					{
						index = 0;
					}
					break;
				}
				else
				{
					if (GetAsyncKeyState(VK_RETURN) != 0)
					{
						switch (index)
						{
						case 0:
							showDifficultyMenu = true;
							difficultySelect();
							break;
						case 1:
							showHelpMenu = true;
							helpScreen();
							break;
						case 2:
							cls();
							exit(EXIT_SUCCESS);
							break;
						}
					}
				}
			}
		}
		//	Input delay/reduce flicker
		Sleep(REFRESH);
	}
}

void titleSplash(int color)
{
	/*	Main Menu Splash Screen  */
	//	Center string horizontally and vertically, as well as change the color of text
	string t = horizontalAlign(6);
	verticalAlign(10);

	textColor(color);	

	//	Show title splash with delay animation
	cout << t << "@@@@@@@       @@@@@@      @@@@@@@     @@@@@@@     @@@          @@@@@@@@      @@@@@@      @@@  @@@     @@@     @@@@@@@ 	" << endl;
	Sleep(menuAnimation);
	cout << t << "@@@@@@@@     @@@@@@@@     @@@@@@@     @@@@@@@     @@@          @@@@@@@@     @@@@@@@      @@@  @@@     @@@     @@@@@@@@	" << endl;
	Sleep(menuAnimation);
	cout << t << "@@!  @@@     @@!  @@@       @@!         @@!       @@!          @@!          !@@          @@!  @@@     @@!     @@!  @@@	" << endl;
	Sleep(menuAnimation);
	cout << t << "!@   @!@     !@!  @!@       !@!         !@!       !@!          !@!          !@!          !@!  @!@     !@!     !@!  @!@	" << endl;
	Sleep(menuAnimation);
	cout << t << "@!@!@!@      @!@!@!@!       @!!         @!!       @!!          @!!!:!       !!@@!!       @!@!@!@!     !!@     @!@@!@! 	" << endl;
	Sleep(menuAnimation);
	cout << t << "!!!@!!!!     !!!@!!!!       !!!         !!!       !!!          !!!!!:        !!@!!!      !!!@!!!!     !!!     !!@!!!  	" << endl;
	Sleep(menuAnimation);
	cout << t << "!!:  !!!     !!:  !!!       !!:         !!:       !!:          !!:               !:!     !!:  !!!     !!:     !!:     	" << endl;
	Sleep(menuAnimation);
	cout << t << ":!:  !:!     :!:  !:!       :!:         :!:        :!:         :!:              !:!      :!:  !:!     :!:     :!:     	" << endl;
	Sleep(menuAnimation);
	cout << t << " :: ::::     ::   :::        ::          ::        :: ::::      :: ::::     :::: ::      ::   :::      ::      ::     	" << endl;
	Sleep(menuAnimation);
	cout << t << ":: : ::       :   : :        :           :        : :: : :     : :: ::      :: : :        :   : :     :        :      	" << endl;
	Sleep(menuAnimation);

	//	Pre-align for menut items
	verticalAlign(10);

	//	After animation has shown once, do not repeat if main menu is repeated.
	menuAnimation = 0;
}

void helpSplash(int color)
{
	/*	Help Splash Screen  */
	//	Center string horizontally and vertically, as well as change the color of text
	string t = horizontalAlign(6);
	verticalAlign(10);

	textColor(color);

	cout << t << "  /\\\\\\        /\\\\\\            /\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\            /\\\\\\                        /\\\\\\\\\\\\\\\\\\\\\\\\\\\\          " << endl;
	cout << t << "  \\/\\\\\\       \\/\\\\\\           \\/\\\\\\///////////            \\/\\\\\\                       \\/\\\\\\/////////\\\\\\        " << endl;
	cout << t << "   \\/\\\\\\       \\/\\\\\\           \\/\\\\\\                       \\/\\\\\\                       \\/\\\\\\       \\/\\\\\\       " << endl;
	cout << t << "    \\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\           \\/\\\\\\\\\\\\\\\\\\\\\\               \\/\\\\\\                       \\/\\\\\\\\\\\\\\\\\\\\\\\\\\/       " << endl;
	cout << t << "     \\/\\\\\\/////////\\\\\\           \\/\\\\\\///////                \\/\\\\\\                       \\/\\\\\\/////////        " << endl;
	cout << t << "      \\/\\\\\\       \\/\\\\\\           \\/\\\\\\                       \\/\\\\\\                       \\/\\\\\\                " << endl;
	cout << t << "       \\/\\\\\\       \\/\\\\\\           \\/\\\\\\                       \\/\\\\\\                       \\/\\\\\\               " << endl;
	cout << t << "        \\/\\\\\\       \\/\\\\\\           \\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\           \\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\           \\/\\\\\\              " << endl;
	cout << t << "         \\///        \\///            \\///////////////            \\///////////////            \\///              " << endl;

	helpMessage();
}

void helpScreen()
{
	/*	Help Screen  */
	//	Show splash, version, and check for ESC keypress
	cls();
	helpSplash(1);
	xyColored(2, YDOWN, 3, "To go back to the main menu, press ESC.");
	xyColored(202, YDOWN, 3, VERSION_INFO);

	while (showHelpMenu == true)
	{
		if (GetAsyncKeyState(VK_ESCAPE) != 0)
		{
			showHelpMenu = false;
			menu();
		}
	}
}

void helpMessage()
{
	/*	Help Screen Body  */
	//	Center string horizontally and vertically, as well as change the color of text
	string title = horizontalAlign(13);
	string body = horizontalAlign(3);
	verticalAlign(4);
	textColor(13);

	cout << title <<  "How to Play" << endl << endl;
	cout << body << "Battleship tests your might and wit in an intense one versus one battle between two admirals of the sea. In this game, each player will have their ships" << endl << body <<
		"randomly placed on a grid labeled with a series of numbers and letters (ex. A3, C4) and be asked to choose a point on the other players board to fire upon." << endl << body <<
		"If the player is successful, they will land a hit on the opposing players ship, and if they manage to hit each point on the ship, it will sink. If the player misses, " << endl << body <<
		"well, better luck next time.The game ends when one player successfully destroys the other players entire armada." << endl;

	
}

void difficultySelect()
{
	/*  Difficulty Select Menu  */
	//	Show splash, version, check for ESC keypress
	cls();
	xyColored(2, YDOWN, 3, "To go back to the main menu, press ESC.");
	xyColored(202, YDOWN, 3, VERSION_INFO);

	while (showDifficultyMenu == true)
	{
		if (GetAsyncKeyState(VK_ESCAPE) != 0)
		{
			showDifficultyMenu = false;
			menu();
		}
	}
}


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