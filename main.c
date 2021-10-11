#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "header.h"

void displayzone(int** tab, int row, int column)
{
/*    if(column == NULL)
    {
        for(int i = 0 ; i < row ; i++)
        {
            printf("%d\n",tab[i]);
        }
    } else if (row != NULL && column != NULL & tab != NULL)
    {
        for (int i = 0; i < row; i++)
        {
            for(int j = 0 ; j < column ; j++)
            {
                printf("%d\n",tab[i][j]);
            }
        }
    }*/

    int i, j;
    int counter = 0;
    srand(time(NULL));

    for (i = 1 ; i < row + 1 ; i += 1)
    {
        for (j = 1 ; j < column + 1; j += 1)
        {

            if (counter == 1)
            {
                if (j-1 % 5 == 0)
                    printf("%d\n", rand() % (11 + 1 - 2) + 2);
                else
                {
                    printf("%d |", rand() % (11 + 1 - 2) + 2);
                    //printf("ok");
                }
            } else {

                if (j-1 % 5 == 0){
                    tab[i][j] = rand() % (11 + 1 - 2) + 2;
                    printf("%d\n", tab[i][j]);
                }

                else
                {
                    tab[i][j] = rand() % (11 + 1 - 2) + 2;
                    printf("%d |", tab[i][j]);
                }
            }
        }
    }
}

int main()
{
    MainCharactere me;
    int zone1[ROW][COLUMN];
    me.max_hp = 100;
    me.current_hp = 10;
    displayzone(&zone1,ROW, COLUMN);//zone1 rempli avec des nb aleatoires

    usePotion(&me, 15);
    printf("HP : %d\n", me.current_hp);
    return 0;
}
/*void zone1(int* zone1, int row, int column)
{
    srand(time(NULL));

    for (int i = 0; i < row; i++)
    {
        for(int j = 0 ; j < column ; j++)
        {
            zone1 = rand() % 11;
        }
    }
}*/

/*/Ajouter un objet dans l'inventaire
void addItemToInventory(Inventory* inventory, int item)
{
    while(inventory->next != 0)
    {
        inventory = inventory->next;

}*//*

//Afficher l'inventaire du joueur
void displayInventory()
{
    Inventory* slot = malloc(sizeof(Inventory));

    while(slot->next != 0)
    {
        printf("Name : %d\tType: %s\tInfo: %s\n",Epee_bois,"Arme", "Durabilite 10 | Degat 10 ");
        slot = slot->next;
    }
    free(slot);
}*/

//Utiliser une potion
void usePotion (MainCharactere* character, int potion)
{
    int diffHp = character->max_hp - character->current_hp;

    if(potion == Potion_vie)
    {
        if(diffHp >=30)
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