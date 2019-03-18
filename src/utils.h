#ifndef _UTILS_H
#define _UTILS_H

#include <string>
#include <Windows.h>

namespace utils
{
     /*	Declaration of global variables */
    extern const std::string VERSION_INFO;
	extern const std::string TEAM_NAME;
	extern const std::string NAVIGATION_MSG;

	extern const int REFRESH;
	extern const int YDOWN;

	extern bool showHelpMenu;
	extern bool showDifficultyMenu;

	extern int menuAnimation;

    std::string horizontalAlign(int n);
    void cls();
    void difficultySelect();
    void gotoXY(int x, int y, std::string msg);
    void helpMessage();
    void helpScreen();
    void init();
    void menu();
    void textColor(int c);
    void titleSplash(int c);
    void verticalAlign(int lines);
    void xyColored(int x, int y, int c, std::string msg); 
}
  
#endif /* _UTILS_H */   