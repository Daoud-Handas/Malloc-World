//
// Created by daoud on 15/11/2021.
//

#include "../header.h"

//Utiliser une potion
void usePotion (Player* character, int potion)
{
    int diffHp = character->max_hp - character->current_hp;

    if(potion == Potion_vie)
    {
        if(diffHp >= 30)
        {
            character->current_hp += 30;
            if(character->inventory->name == 15)
            {

            }

        }else
        {
            character->current_hp += diffHp;
        }
    }
}

#ifndef MALLOC_WORLD_FIGHT_H
#define MALLOC_WORLD_FIGHT_H

#endif //MALLOC_WORLD_FIGHT_H
