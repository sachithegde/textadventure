#ifndef CLASS_SPECIALISATION_H
#define CLASS_SPECIALISATION_H


#include <iostream>
#include "Base_Stat.h"

class Class_Specialisation : public Base_Stats
{
	public :
		int iUInput = -1;
        int Max_Health = 10 * HP;
        int Current_Health = Max_Health;

		void Choose_Class()
		{
            //Print Character Menu
			std::cout << "Choose your Class: " << std::endl;
            std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "Dexterity: The higher the dexterity, the easier it is to open chests" << std::endl;
            std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "Health Points: The Higher the HP, the more the player health" << std::endl;
            std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "Strength: The higher the strength, the more damage you do" << std::endl;
            std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "Agility: The higher the number, the more likely you are to attack first in combat." << std::endl;
            std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;


            std::cout
                << "1.) Assassin: High Dexterity and Speed/Low Health and Strength\n" 
                << "2.) Warrior: High Strength and Heath/Low Dexterity and Speed\n" 
                << "3.) Mage: High Strength and Health/Low Dexterity and Speed\n"
                << "4.) Ranger: High Health and Speed/Low Strength and Dexterity\n" 
                << std::endl;

            //User Input
            std::cin >> iUInput;
            std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;


            //Allocate Base Stats
            //Need to add the movesets

            switch (iUInput)
            {
                case 1: //Assassin
                {
                    C_Name = "ASSASSIN";
                    DEX = 8;
                    HP = 5;
                    STR = 1;
                    AGL = 9;
                    break;
                }
                case 2: //Warrior
                {
                    C_Name = "WARRIOR";
                    DEX = 5;
                    HP = 9;
                    STR = 9;
                    AGL = 4;
                    break;
                }
                case 3: //Mage
                {
                    C_Name = "MAGE";
                    DEX = 5;
                    HP = 8;
                    STR = 5;
                    AGL = 8;
                    break;
                }
                case 4: //Ranger
                {
                    C_Name = "RANGER";
                    DEX = 5;
                    HP = 8;
                    STR = 5;
                    AGL = 8;
                    break;
                }
            }
            Max_Health = 10 * HP;
            Current_Health = Max_Health;
            Allocate_SP_Points();

		}

        void Allocate_SP_Points()
        {
            int ex_pt; // Stores how many points a user wants to add to a stat
            std::cout << "You have chosen the " << C_Name << " class!" << std::endl;
            std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "You have 10 additional Skill points to allocate among the stats." << std::endl;
            std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "Your base stats are:" << std::endl;
            std::cout << "DEX: " << DEX << std::endl;
            std::cout << "HP: " << HP << std::endl;
            std::cout << "STR: " << STR << std::endl;
            std::cout << "AGL: " << AGL << std::endl;
            std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;

            Label_Dex: //Allocate Special Points to Dexterity
                {
                    std::cout << "How many Skill points do you want to add to DEX? Current DEX points: " << DEX << std::endl;
                    std::cin >> ex_pt;
                    std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
                    if (ex_pt > SP_Points)
                    {
                        std::cout << "The number you have entered exceeds total available Skill Points. Enter Again!" << std::endl;
                        std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
                        goto Label_Dex;
                    }
                    SP_Points -= ex_pt;
                    DEX += ex_pt;
                    std::cout << "Skill Points remaining: " << SP_Points << std::endl;
                    std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
                    std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;


                }
            if (SP_Points > 0)
            {
                Label_HP: // Allocate Special Points to HP
                    {
                        std::cout << "How many Skill points do you want to add to HP? Current HP points: " << HP << std::endl;
                        std::cin >> ex_pt;
                        std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
                        if (ex_pt > SP_Points)
                        {
                            std::cout << "The number you have entered exceeds total available Skill Points. Enter Again!" << std::endl;
                            std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
                            goto Label_HP;
                        }
                        SP_Points -= ex_pt;
                        HP += ex_pt;
                        std::cout << "Skill Points remaining: " << SP_Points << std::endl;
                        std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
                        std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
                    }
                    Max_Health = 10 * HP;
                    Current_Health = Max_Health;
            }
            else
            {
                std::cout << "You don't have any additional Skill Points left!" << std::endl;
                std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
                std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
                return;
            }

            if (SP_Points > 0)
            {
                Label_STR: // Allocate Special Points to Strength
                    {
                        std::cout << "How many Skill points do you want to add to STR? Current STR points: " << STR << std::endl;
                        std::cin >> ex_pt;
                        std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
                        if (ex_pt > SP_Points)
                        {
                            std::cout << "The number you have entered exceeds total available Skill Points. Enter Again!" << std::endl;
                            std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
                            goto Label_STR;
                        }
                        SP_Points -= ex_pt;
                        STR += ex_pt;
                        std::cout << "Skill Points remaining: " << SP_Points << std::endl;
                        std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
                        std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
                    }
            }
            else
            {
                std::cout << "You don't have any additional Skill Points left!" << std::endl;
                std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
                std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
                return;
            }
            if (SP_Points > 0)
            {
                Label_AGL: // Allocate Special POints to Agility
                    {
                        std::cout << "How many Skill points do you want to add to AGL? Current points: " << AGL << std::endl;
                        std::cin >> ex_pt;
                        std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
                        if (ex_pt > SP_Points)
                        {
                            std::cout << "The number you have entered exceeds total available Skill Points. Enter Again!" << std::endl;
                            std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
                            goto Label_AGL;
                        }
                        SP_Points -= ex_pt;
                        AGL += ex_pt;
                        std::cout << "Skill Points remaining: " << SP_Points << std::endl;
                        std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
                        std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
                    }
                    
            }
            else
            {
                std::cout << "You don't have any additional Skill Points left!" << std::endl;
                std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
                std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
                return;
            }

            
            
        }

        void Stats_Display()
        {
            std::cout << "Your final stats are:" << std::endl;
            std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "Class Name: " << C_Name << std::endl;
            std::cout << "DEX: " << DEX << std::endl;
            std::cout << "HP: " << HP << std::endl;
            std::cout << "STR: " << STR << std::endl;
            std::cout << "AGL:" << AGL << std::endl;
            std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "CHARACTER CREATED!" << std::endl;
            std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
        }

        
};

#endif // !CLASS_SPECIALISATION_H