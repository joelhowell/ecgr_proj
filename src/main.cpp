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
 *		Last Modified:		3/12/2019																		*
 *																											*
 *		Purpose:																							*
 *																											*
 *																											*
 ***********************************************************************************************************/										

#include "pch.h"
#include "libraries.h"

using namespace std;

/*	Declaration of global variables  */
const string VERSION_INFO = "v1.0.0";
const string TEAM_NAME = "Flaming Burritos";
const string NAVIGATION_MSG = "Use the up and down arrows to navigate. To select, press return.";

const int REFRESH = 75;
const int YDOWN = 52;

bool showHelpMenu = false;
bool showDifficultyMenu = false;


/*	Declare functions  */
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

	while (showHelpMenu == false || showDifficultyMenu == false)
	{
		//	Clear screen
		cls();

		//	Ensure text color is default
		textColor(9);

		//	Properly display navigation instructions and version info, as well as relocate the cursor to original position
		xyColored(2, YDOWN, 3, NAVIGATION_MSG);
		xyColored(202, YDOWN, 3, VERSION_INFO);
		gotoXY(0, 0, "");

		//	Display titleSplash title
		titleSplash(1);

		//	Display menu items and determine what to highlight as selected
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
				Sleep(REFRESH);
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
					Sleep(REFRESH);
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
		//	Reduce flicker
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

	cout << t << "@@@@@@@       @@@@@@      @@@@@@@     @@@@@@@     @@@          @@@@@@@@      @@@@@@      @@@  @@@     @@@     @@@@@@@ 	" << endl;
	cout << t << "@@@@@@@@     @@@@@@@@     @@@@@@@     @@@@@@@     @@@          @@@@@@@@     @@@@@@@      @@@  @@@     @@@     @@@@@@@@	" << endl;
	cout << t << "@@!  @@@     @@!  @@@       @@!         @@!       @@!          @@!          !@@          @@!  @@@     @@!     @@!  @@@	" << endl;
	cout << t << "!@   @!@     !@!  @!@       !@!         !@!       !@!          !@!          !@!          !@!  @!@     !@!     !@!  @!@	" << endl;
	cout << t << "@!@!@!@      @!@!@!@!       @!!         @!!       @!!          @!!!:!       !!@@!!       @!@!@!@!     !!@     @!@@!@! 	" << endl;
	cout << t << "!!!@!!!!     !!!@!!!!       !!!         !!!       !!!          !!!!!:        !!@!!!      !!!@!!!!     !!!     !!@!!!  	" << endl;
	cout << t << "!!:  !!!     !!:  !!!       !!:         !!:       !!:          !!:               !:!     !!:  !!!     !!:     !!:     	" << endl;
	cout << t << ":!:  !:!     :!:  !:!       :!:         :!:        :!:         :!:              !:!      :!:  !:!     :!:     :!:     	" << endl;
	cout << t << " :: ::::     ::   :::        ::          ::        :: ::::      :: ::::     :::: ::      ::   :::      ::      ::     	" << endl;
	cout << t << ":: : ::       :   : :        :           :        : :: : :     : :: ::      :: : :        :   : :     :        :      	" << endl;

	verticalAlign(10);
}

void helpSplash(int color)
{
	/*	Help Splash Screen  */
	//	Center string horizontally and vertically, as well as change the color of text
	string t = horizontalAlign(6);
	verticalAlign(6);

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
	string t = horizontalAlign(9);
	verticalAlign(2);
	textColor(13);

	cout << t << " _     _                                   _             " << endl;
	cout << t << "| |   | |               _                 | |            " << endl;
	cout << t << "| |__ | | ___  _ _ _   | |_  ___     ____ | | ____ _   _ " << endl;
	cout << t << "|  __)| |/ _ \\| | | |  |  _)/ _ \\   |  _ \\| |/ _  | | | |" << endl;
	cout << t << "| |   | | |_| | | | |  | |_| |_| |  | | | | ( ( | | |_| |" << endl;
	cout << t << "|_|   |_|\\___/ \\____|   \\___)___/   | ||_/|_|\\_||_|\\__  |" << endl;
	cout << t << "                                    |_|           (____/ " << endl;
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