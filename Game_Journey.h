#ifndef GAME_JOURNEY_H
#define GAME_JOURNEY_H

#include <iostream>
#include "Enemy.h"
#include "Player_Character.h"
#include "Helper.h"
#include "Attacks.h"

void Display_MoveSet(Player_Character* PPtr)
{
	std::cout << "Choose a Move to Play" << std::endl;
	std::cout << "1. " << AttackNames[PPtr->attackArr[0]] << std::endl;
	std::cout << "2. " << AttackNames[PPtr->attackArr[1]] << std::endl;
	std::cout << "3. " << AttackNames[PPtr->attackArr[2]] << std::endl;
	std::cout << "4. " << AttackNames[PPtr->attackArr[3]] << "\n" << std::endl;

}

void Player_turn(Enemy* EPtr, Player_Character* PPtr, int initiator)
{

	int moveChoice;
	Display_MoveSet(PPtr);
	std::cin >> moveChoice;
	table[PPtr->attackArr[moveChoice -  1]](EPtr, PPtr, initiator);


}

void Enemy_turn(Enemy* EPtr, Player_Character* PPtr, int initiator)
{
	if (randomGen(100) < 10)
	{
		table[0](EPtr, PPtr, 0);
	}

	if (EPtr->Current_Health < 5)
	{
		table[2](EPtr, PPtr, 0);
		return;
	}
	else
	{
		table[EPtr->attackArr[randomGen(2)]](EPtr, PPtr, initiator);
	}


}

void Enemy_Fight(Enemy* EPtr, Player_Character* PPtr)
{
	*EPtr = Enemy::Create_Enemy();
	std::cout << "You have encountered a " << EPtr->C_Name << std::endl;
	
	while (EPtr->Current_Health > 0 && PPtr->Current_Health > 0 && !PPtr->flee && !EPtr->flee)
	{
		
		//Agility Check
		if (PPtr->AGL > EPtr->AGL)
		{//Player Plays First
			if (PPtr->can_play)
			{
				Player_turn(EPtr, PPtr, 1);
			}
			else
			{
				PPtr->can_play = true;
			}

			if (EPtr->can_play && EPtr->Current_Health > 0)
			{
				Enemy_turn(EPtr, PPtr, 0);
			}
			else
			{
				EPtr->can_play = true;
			}
			
			
		}
		else
		{//Enemy Plays First
			if (EPtr->can_play)
			{
				Enemy_turn(EPtr, PPtr, 0);
			}
			else
			{
				EPtr->can_play = true;
			}

			if (PPtr->can_play && PPtr->Current_Health > 0)
			{
				Player_turn(EPtr, PPtr, 1);
			}
			else
			{
				PPtr->can_play = true;
			}
			

		}
		std::cout << PPtr->Current_Health << " Player Health || " << EPtr->Current_Health << " Enemy Health" << std::endl;
	}
}





void find_chest(Player_Character* PPtr)
{
	int chance = randomGen(10);
	int lockpick;
	char cUInput;
	std::cout << "You have found a chest. Do you wish to open it? (y / n): " << std::endl;
	std::cin >> cUInput;

	if (cUInput == 'Y' || cUInput == 'y')
	{
		if (chance < 5)
		{
			lockpick = randomGen(10);
			if (PPtr->DEX > lockpick)
			{
				std::cout << "You open the Chest and Gained XP!!" << std::endl;
				PPtr->DEX += 15;
			}
			else
			{
				std::cout << "Your DEX is too low to open the Chest!" << std::endl;
			}
			return;
		}
		else if (chance >= 5 && chance < 8)
		{
			lockpick = randomGen(10);
			if (PPtr->DEX > lockpick)
			{
				std::cout << "You open the Chest and found an XP Potion!!" << std::endl;
				if (PPtr->Current_Potion_Reserve < PPtr->Max_Potion_Reserve)
				{
					++PPtr->Current_Potion_Reserve;
				}
				else
				{
					std::cout << "You cannot carry any more potions!" << std::endl;
				}
			}
			else
			{
				std::cout << "Your DEX is too low to open the Chest!" << std::endl;
			}
			return;
		}
		else
		{
			lockpick = randomGen(10);
			if (PPtr->DEX > lockpick)
			{
				std::cout << "You open the Chest and Found a Key!!" << std::endl;
				PPtr->Player_keys;
			}
			else
			{
				std::cout << "Your DEX is too low to open the Chest!" << std::endl;
			}
			return;
		}
	}
	return;
	 
}

#endif // !GAME_JOURNEY_H

