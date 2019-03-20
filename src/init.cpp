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
        
        //  Make full screen
        SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

        //  Remove scroll bar (set buffer to same size as window)
        HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hstdout, &csbi);

        csbi.dwSize.X = csbi.dwMaximumWindowSize.X;
        csbi.dwSize.Y = csbi.dwMaximumWindowSize.Y;
        SetConsoleScreenBufferSize(hstdout, csbi.dwSize);

        HWND x = GetConsoleWindow();
        ShowScrollBar(x, SB_BOTH, FALSE);
    }
}