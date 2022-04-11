#ifndef ATTACKS_H
#define ATTACKS_H


#include <iostream>
#include "Enemy.h"
#include "Player_Character.h"



//Function Pointer Table
typedef bool (* FPtr)(Enemy*, Player_Character*, int);
FPtr table[20];
std::string AttackNames[] = { "Flee", "Potion Heal", "Enemy Heal", "Toxic Sludge", "Dagger Attack", "Claw Attack", "Sword Attack", "FireBall", "Health Drain", "HeadButt", "Sheild Wall", "War Cry", "Poison Arrow", "Regenerate" };

//Helper Functions Start Here
void deal_damage(Enemy* EPtr, Player_Character* PPtr, int initiator, int damagePoints)
{
	std::cout << "Initiator " << initiator << std::endl;
	if (initiator == 0)
	{
		if (PPtr->Current_Health > damagePoints)
		{
			PPtr->Current_Health -= damagePoints;
		}
		else
		{
			PPtr->Current_Health = 0;
		}
	}
	else
	{
		if (EPtr->Current_Health > damagePoints)
		{
			EPtr->Current_Health -= damagePoints;
		}
		else
		{
			EPtr->Current_Health = 0;
		}
	}
}


//Attack Functions Starts Here
bool Flee(Enemy* EPtr, Player_Character* PPtr, int initiator)
{
	if (initiator == 0)
	{
		std::cout << EPtr->C_Name << " has decided to flee" << std::endl;
		EPtr->flee = true;
		EPtr->STR_MOD = 0;
		PPtr->STR_MOD = 0;
		return true;
	}
	else
	{
		std::cout << "You have chosen to flee! You do not gain any XP! " << std::endl;
		EPtr->STR_MOD = 0;
		PPtr->STR_MOD = 0;
		PPtr->flee = true;
		return true;
	}
}

bool Player_Heal(Enemy* EPtr, Player_Character* PPtr, int initiator)
{
	if (PPtr->Current_Potion_Reserve > 0 && PPtr->Current_Health != PPtr->Max_Health)
	{
		PPtr->Current_Health += ((PPtr->Max_Health - PPtr->Current_Health) > 50) ? 50 : (PPtr->Max_Health - PPtr->Current_Health);
		--PPtr->Current_Potion_Reserve;
		return true;
	}
	else
	{
		if (PPtr->Current_Potion_Reserve == 0)
		{
			std::cout << "You do not have any Health Potions on you!" << std::endl;
			return false;
		}
		else
		{
			std::cout << "Your Health is already at its Max, You cannot use the Health Potion!" << std::endl;
			return false;
		}
	}
}

bool Enemy_Heal(Enemy* EPtr, Player_Character* PPtr, int initiator)
{
	EPtr->Current_Health += 50;
	return true;
}

bool Toxic_Sludge(Enemy* EPtr, Player_Character* PPtr, int initiator)
{
	std::cout << "The Slime Attacks you with Toxic Sludge" << std::endl;
	deal_damage(EPtr, PPtr, 0, (EPtr->STR + EPtr->STR_MOD) * 15);

	std::cout << "You take " << (EPtr->STR + EPtr->STR_MOD) * 15 << " damage. Your Health is now " << PPtr->Current_Health << std::endl;
	EPtr->STR_MOD = 0;
	return true;
}

bool DaggerAttack(Enemy* EPtr, Player_Character* PPtr, int initiator)
{
	std::cout << "The Goblin attacks you with a dagger" << std::endl;
	deal_damage(EPtr, PPtr, 0, (EPtr->STR + EPtr->STR_MOD) * 20);

	std::cout << "You take " << (EPtr->STR + EPtr->STR_MOD) * 20 << " damage. Your Health is now " << PPtr->Current_Health << std::endl;
	EPtr->STR_MOD = 0;
	return true;

}

bool ClawAttack(Enemy* EPtr, Player_Character* PPtr, int initiator)
{
	std::cout << "The Goblin attacks you with its Claws" << std::endl;
	deal_damage(EPtr, PPtr, 0, (EPtr->STR + EPtr->STR_MOD) * 10);

	std::cout << "You take " << (EPtr->STR + EPtr->STR_MOD) * 10 << " damage. Your Health is now " << PPtr->Current_Health << std::endl;
	EPtr->STR_MOD = 0;
	return true;

}

bool SwordAttack(Enemy* EPtr, Player_Character* PPtr, int initiator)
{
	std::string attacker = (initiator == 0) ? EPtr->C_Name : "You ";
	std::string victim = (initiator == 0) ? "You " : EPtr->C_Name;
	std::cout << attacker << " attack with a Sword" << std::endl;
	deal_damage(EPtr, PPtr, initiator, (initiator == 0) ? (EPtr->STR + EPtr->STR_MOD) * 30 : (PPtr->STR + PPtr->STR_MOD) * 30);
	
	std::cout << victim << " takes " << ((initiator == 0) ? (EPtr->STR + EPtr->STR_MOD) * 30 : (PPtr->STR + PPtr->STR_MOD) * 30) << " damage. " << victim << " has " << ((initiator == 0) ? PPtr->Current_Health : EPtr->Current_Health) << " health" << std::endl;
	
	return true;

}

bool FireBallAttack(Enemy* EPtr, Player_Character* PPtr, int initiator)
{
	std::string attacker = (initiator == 0) ? EPtr->C_Name : "You ";
	std::string victim = (initiator == 0) ? "You " : EPtr->C_Name;
	std::cout << attacker << " attack with a FireBall" << std::endl;
	deal_damage(EPtr, PPtr, initiator, (initiator == 0) ? (EPtr->STR + EPtr->STR_MOD) * 30 : (PPtr->STR + PPtr->STR_MOD) * 30);

	std::cout << victim << " takes " << ((initiator == 0) ? (EPtr->STR + EPtr->STR_MOD) * 30 : (PPtr->STR + PPtr->STR_MOD) * 30) << " damage. " << victim << " has " << ((initiator == 0) ? PPtr->Current_Health : EPtr->Current_Health) << " health" << std::endl;

	return true;

}

bool HealthDrain(Enemy* EPtr, Player_Character* PPtr, int initiator)
{
	if (initiator == 0)
	{
		int temp = PPtr->Current_Health * 10 / 100;
		EPtr->Current_Health += temp;
		PPtr->Current_Health -= temp;
		std::cout << EPtr->C_Name << " drains " << temp << " health from you. Your Health is now " << PPtr->Current_Health << std::endl;
		return true;
	}
	return false;
}

bool ConfusionRay(Enemy* EPtr, Player_Character* PPtr, int initiator)
{
	std::cout << "The Goblin Boss Uses the Confusion Ray on you. YOu miss your next turn.";
	PPtr->can_play = false;
	return true;
}

bool HeadButt(Enemy* EPtr, Player_Character* PPtr, int initiator)
{
	std::cout << "The Goblin Boss HHeadButts You" << std::endl;
	deal_damage(EPtr, PPtr, 0, (EPtr->STR + EPtr->STR_MOD) * 40);

	std::cout << "You take " << (EPtr->STR + EPtr->STR_MOD) * 40 << " damage. Your Health is now " << PPtr->Current_Health << std::endl;
	return true;
}

bool Sheild_Wall(Enemy* EPtr, Player_Character* PPtr, int initiator)
{
	EPtr->STR_MOD = -5;
	return true;
}

bool Warcry(Enemy* EPtr, Player_Character* PPtr, int initiator)
{
	PPtr->STR_MOD = +5;
	return true;
}

bool Poison_Arrow(Enemy* EPtr, Player_Character* PPtr, int initiator)
{
	std::cout << "You use a Poison Arrow" << std::endl;
	deal_damage(EPtr, PPtr, 1, (PPtr->STR + PPtr->STR_MOD));
	std::cout << EPtr->C_Name << " is poisoned and cannot play in the Next turn" << std::endl;
	EPtr->can_play = false;
	return true;
}

bool Regenerate(Enemy* EPtr, Player_Character* PPtr, int initiator)
{

	if (PPtr->HP == PPtr->Max_Health)
	{
		std::cout << "Cannot use Regenrate as your health is full" << std::endl;
		return false;
	}

	PPtr->HP += 50;

	if (PPtr->HP > PPtr->Max_Health)
	{
		PPtr->HP = PPtr->Max_Health;
	}
	return true;
}




void tableInit()
{
	table[0] = Flee;
	table[1] = Player_Heal;
	table[2] = Enemy_Heal;
	table[3] = Toxic_Sludge;
	table[4] = DaggerAttack;
	table[5] = ClawAttack;
	table[6] = SwordAttack;
	table[7] = FireBallAttack;
	table[8] = HealthDrain;
	table[9] = HeadButt;
	table[10] = Sheild_Wall;
	table[11] = Warcry;
	table[12] = Poison_Arrow;
	table[13] = Regenerate;

	//
}





	




#endif // !ATTACKS_H

