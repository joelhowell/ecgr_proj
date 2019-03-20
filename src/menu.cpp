#include <iostream>
#include "utils.h"

using namespace std;

namespace utils
{
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

        //	Properly display navigation instructions and version info, as well as relocate the cursor to set position
        xyColored(2, YDOWN, 3, NAVIGATION_MSG);
        xyColored(205, YDOWN, 3, VERSION_INFO);
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
                    cout << t << "  " << MenuItems[i] << endl << endl;
                }
                else
                {
                    textColor(9);
                    cout << t << "  " << MenuItems[i] << endl << endl;
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
}