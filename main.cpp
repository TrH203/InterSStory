#include"Game.h"
#include <iostream>
#include <chrono>
#include <ctime>    

int main(void)
{
	Game game;
	game.init();
	if (game.init())
		game.run();
   // std::time_t t = std::time(0);   // get time now
   // std::tm* now = std::localtime(&t);
   // std::cout << (now->tm_year + 1900) << '-' 
   //      << (now->tm_mon + 1) << '-'
   //      <<  now->tm_mday << endl
		 //<< now->tm_hour
   //      << "\n";
}