#ifndef BASE_STAT_H
#define BASE_STAT_H


#include <iostream>


class Base_Stats
{
	public:
		std::string C_Name = "";
		int DEX = 0, HP = 0, STR = 0, AGL = 0, STR_MOD = 0;
		int SP_Points = 10;
		bool can_play = true;
		bool flee = false;
		int attackArr[4] = {6, 7 , 1, 0};
};

#endif // !BASE_STAT_H