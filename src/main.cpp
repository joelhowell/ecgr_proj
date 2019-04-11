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
 *		Purpose:            To play battleship :)															*
 *																											*
 *																											*
 ***********************************************************************************************************/										

#include "utils.h"
#include <iostream>
using namespace std;
using namespace utils;

int main()
{
    /*	Game Initialization	 */
    cls();
    menu();
    //difficulty = 5;
    
    gameInit();

    system("pause");
    
    return 0;
}