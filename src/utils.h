#ifndef _UTILS_H
#define _UTILS_H

#include <string>

namespace utils
{
     /*	Declaration of global variables */
    extern const std::string VERSION_INFO;
	extern const std::string TEAM_NAME;

    extern const int maxHits;
    extern int difficulty;
    extern int hits1;
    extern int hits2;

    extern std::string players[2];
    extern std::string p1;
    extern std::string p2;

    int getColumn(std::string input);
    int getRandom();
    int getRow(std::string input);

    void cls();
    void easy(int randomNum, bool p1);
    void game();
    void gameInit();
    void getCoords(std::string p);
    void hard(int randomNum, bool p1);
    void initBackgroundBoards();
    void initOutputBoards();
    void isHit(int r, int c, std::string t);
    void med(int randomNum, bool p1);
    void menu();
    void refresh();
}
  
#endif /* _UTILS_H */   