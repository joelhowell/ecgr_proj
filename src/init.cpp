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

    }
}