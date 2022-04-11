#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H

#include "Class_Specialisation.h"

class Player_Character : public Class_Specialisation
{
    public:

        int Player_keys = 0;

        
        int Max_Damage = 3 * STR;

        int Max_Potion_Reserve = 5;
        int Current_Potion_Reserve = 3;

        int lvl = 1;
        int xp = 0;
        int xp_to_nxt_lvl = 10;

        

       

        void Level_Up()
        {
            static int i = 20;
            if (lvl == 10)
            {
                std::cout << "YOU HAVE REACHED THE MAXIMUM LEVEL CAP!" << std::endl;
            }
            else if (lvl < 10)
            {
                if (xp >= xp_to_nxt_lvl)
                {
                    ++lvl;
                    while (i <= 100)
                    {
                        xp_to_nxt_lvl += i;
                        i++;
                        break;
                    }
                    std::cout << "YOU LEVELLED UP! YOU ARE NOW LVL " << lvl << std::endl;
                    std::cout << "DEX : " << DEX << "->" << DEX + 2 << std::endl;
                    std::cout << "HP : " << HP << "->" << HP + 2 << std::endl;
                    std::cout << "STR : " << STR << "->" << STR + 2 << std::endl;
                    std::cout << "AGL : " << AGL << "->" << AGL + 2 << std::endl;
                    DEX += 2;
                    HP += 2;
                    STR += 2;
                    AGL += 2;
                }
            }
        }
};

#endif // !PLAYER_CHARACTER_H