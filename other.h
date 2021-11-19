//
// Created by daoud on 15/11/2021.
//

#include "header.h"

//Ne récupère que les nombres lors d'une saisie
int getIntegerOnly()
{
    int num = 0;
    int ch;

    do {
        ch = getch();

        //Code ASCII 0 à 9
        if (ch >= 48 && ch <= 57)
        {
            // Conversion en nombre
            num = num * 10 + (ch - 48);
        }

        // 13 est le retour à la ligne, on break à ce moment là pour ne pas le prendre en compte
        if (ch == 13)
            break;
    } while (1);

    return (num);
}

//Lance l'incroyable aventure de Malloc World
void launchGame()
{

    int** zone1 = (int**)malloc(ROW * sizeof(int*));
    int game = 1;
    int choice = 0;
    int turn = 1;
    InventoryPlayer inventory[MAXSLOT] = {0,1,0,0,0};


    for (int i = 0; i < ROW; i++)
    {
        zone1[i] = (int*)malloc(COLUMN * sizeof(int));
    }
    /*for(int i = 0  ; i < ROW ; i += 1)
      {
          for(int j = 0  ; j < COLUMN ; j += 1)
          {
              zone1[i][j] = Plante_zone_1;
              if(i == 2 & j == 2)
              {
                  zone1[i][j] = 1;
              }
          }
      }*/


    printf("BIENVENUE DANS MALLOC WORLD !\n\n\n");
    do {
        printf("Que voulez-vous faire ?\n1=>Nouvelle partie\n2=>Continuer\n3=>Quitter\n");
        choice = getIntegerOnly();
        if(choice)
            switch(choice)
            {
                case 1:
                    generateZone(zone1,Zone_1);
                    itemStart(inventory);//Attribue les equipements de départ

                    while (game < 20){

                        displayZone(zone1,Zone_1);
                        printf("\n\nQue voulez-vous faire ?\n1=>Se deplacer\n2=>Regarder l'inventaire\n");
                        choice = getIntegerOnly();
                        if(choice == 1)
                        {
                            movePlayer(zone1,inventory,&turn);

                        } else if (choice == 2)
                        {
                            viewInventory(inventory);
                        }
                        game += 1;
                    }
                    break;
                case 2:
                    printf("Pas disponible !\n\n\n");
                    break;
                case 3:
                    printf("A bientot !");
                    game = 0;
                    break;
                default:
                    printf("Les instructions sont claires pourtant, recommmence !\n");
                    break;
            }
    }while(game == 1);

    freeZone(zone1);
}


#ifndef MALLOC_WORLD_OTHER_H
#define MALLOC_WORLD_OTHER_H

#endif //MALLOC_WORLD_OTHER_H

