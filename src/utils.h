#ifndef _UTILS_H
#define _UTILS_H

#include <string>
#include <Windows.h>

namespace utils
{
     /*	Declaration of global variables */
    extern const std::string VERSION_INFO;
	extern const std::string TEAM_NAME;

    extern int difficulty;

    std::string horizontalAlign(int n);
    void cls();
    void menu();
    void verticalAlign(int lines);
    void drawBoard();
    int getX(std::string input);
    int getY(std::string input);
    
}
  
#endif /* _UTILS_H */   