#include "utils.h"

using namespace std;

namespace utils
{
    void init()
    {
        /*	Game Initialization	 */
        //	Clear screen
        cls();

        //	Set window title
        string winTitle = "title ~ " + TEAM_NAME + " ~ " + "Battleship [" + VERSION_INFO + "]";
        system(winTitle.c_str());

        //	Change to full screen
       // SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
       system("mode con COLS=700");
       ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
       SendMessage(GetConsoleWindow(),WM_SYSKEYDOWN,VK_RETURN,0x20000000);

    }
}