#include <iostream>
#include "utils.h"

using namespace std;

namespace utils
{
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
        string t = horizontalAlign(7);
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
        xyColored(2, YDOWN, 3, GO_BACK);
        xyColored(205, YDOWN, 3, VERSION_INFO);
        gotoXY(210, YDOWN + 1, "");

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
        string title = horizontalAlign(12);
        string hbody = horizontalAlign(3);
        string cbody = horizontalAlign(6);

        verticalAlign(4);

        textColor(2);
        cout << title <<  "     How to Play" << endl << endl;

        textColor(5);
        cout << hbody << "Battleship tests your might and wit in an intense one versus one battle between two admirals of the sea. In this game, each player will have their ships randomly" << endl << hbody <<
            "placed on a grid labeled with a series of numbers and letters (ex. A3, C4) and be asked to choose a point on the other players board to fire upon. If the player" << endl << hbody <<
            "is successful, they will land a hit on the opposing players ship, and if they manage to hit each point on the ship, it will sink. If the player misses, well," << endl << hbody <<
            "better luck next time. The game ends when one player successfully destroys the other players entire armada." << endl << endl << endl;
       
        textColor(2);
        cout << title << "      Controls" << endl << endl;
        
        textColor(5);
        cout << cbody << "To navigate, use the up and down arrows on the keyboard. To select an option press the enter key. To go back, press ESC." << endl;
    }

    void difficultySelect()
    {
        /*  Difficulty Select Menu  */
        //	Clear, show splash, version, check for ESC keypress
        cls();
        xyColored(2, YDOWN, 3, GO_BACK);
        xyColored(205, YDOWN, 3, VERSION_INFO);
        gotoXY(210, YDOWN + 1, "");

        while (showDifficultyMenu == true)
        {
            if (GetAsyncKeyState(VK_ESCAPE) != 0)
            {
                showDifficultyMenu = false;
                menu();
            }
        }
    }
}