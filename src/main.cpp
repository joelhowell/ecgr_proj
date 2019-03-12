#include <iostream>
#include <Windows.h>
#include <stdlib.h>

using namespace std;

void splash()
{
	cout << "@@@@@@@       @@@@@@      @@@@@@@     @@@@@@@     @@@          @@@@@@@@      @@@@@@      @@@  @@@     @@@     @@@@@@@ 		" << endl;
	cout << "@@@@@@@@     @@@@@@@@     @@@@@@@     @@@@@@@     @@@          @@@@@@@@     @@@@@@@      @@@  @@@     @@@     @@@@@@@@		" << endl;
	cout << "@@!  @@@     @@!  @@@       @@!         @@!       @@!          @@!          !@@          @@!  @@@     @@!     @@!  @@@		" << endl;
	cout << "!@   @!@     !@!  @!@       !@!         !@!       !@!          !@!          !@!          !@!  @!@     !@!     !@!  @!@		" << endl;
	cout << "@!@!@!@      @!@!@!@!       @!!         @!!       @!!          @!!!:!       !!@@!!       @!@!@!@!     !!@     @!@@!@! 		" << endl;
	cout << "!!!@!!!!     !!!@!!!!       !!!         !!!       !!!          !!!!!:        !!@!!!      !!!@!!!!     !!!     !!@!!!  		" << endl;
	cout << "!!:  !!!     !!:  !!!       !!:         !!:       !!:          !!:               !:!     !!:  !!!     !!:     !!:     		" << endl;
	cout << ":!:  !:!     :!:  !:!       :!:         :!:        :!:         :!:              !:!      :!:  !:!     :!:     :!:     		" << endl;
	cout << " :: ::::     ::   :::        ::          ::        :: ::::      :: ::::     :::: ::      ::   :::      ::      ::     		" << endl;
	cout << ":: : ::       :   : :        :           :        : :: : :     : :: ::      :: : :        :   : :     :        :      		" << endl;
}

void init()
{
	//	Clear screen
	system("cls");
	
	//	Full screen
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	splash();
}

int main()
{
	init();

	system("pause");

	return 0;
}