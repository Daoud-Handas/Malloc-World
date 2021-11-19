//
// Created by daoud on 15/11/2021.
//

#include "../header.h"


//Se deplacer vers le pnj
void talkPNJ(InventoryPlayer* inventory)
{
    int choice;
    int end = 1;
    printf("\nSalutation camarade ! Que puis-je faire pour vous ?\n1=>Reparer equipement\n2=>Construire equipement\n3=>Gerer l'inventaire\n4=>Partir\n");
    choice = getIntegerOnly();
    while(end == 1)
    {

        switch(choice)
        {
            case 1:
                repairTool(inventory);
                printf("\nBesoin d'autre chose ?\n1=>Reparer equipement\n2=>Construire equipement\n3=>Gerer l'inventaire\n4=>Partir\n");
                choice = getIntegerOnly();
                break;
            case 2:
                printf("\nBientot disponible !\n");
                printf("\nBesoin d'autre chose ?\n1=>Reparer equipement\n2=>Construire equipement\n3=>Gerer l'inventaire\n4=>Partir\n");
                choice = getIntegerOnly();
                break;
            case 3:
                inventoryPnj(inventory);
                printf("\nBesoin d'autre chose ?\n1=>Reparer equipement\n2=>Construire equipement\n3=>Gerer l'inventaire\n4=>Partir\n");
                choice = getIntegerOnly();
                break;
            case 4:
                printf("\nA bientot !\n\n");
                end = 0;
                break;

            default:
                printf("\nSortez de ma boutique !\n\n");
                end = 0;
        }

    }

}


//Deplacement vers le haut
void moveTop(int** zone, InventoryPlayer* inventory, int* turn)
{
    for(int i = 0 ; i < ROW ; i += 1)
    {
        for(int j = 0 ; j < COLUMN ; j += 1)
        {

            if(zone[i][j] == Joueur)//On localise l'emplacement du joueur
            {
                if(i > 0)//On empeche de depasser la limite de la map vers le haut
                {
                    switch (zone[i-1][j])
                    {
                        case Case_infranchissable:
                            printf("\nDeplacement impossible !\n");
                            displayTurn(turn);
                            break;

                        case Zone_libre: //En cas de déplacement vers une case libre
                            swapCase(&zone[i][j],&zone[i-1][j]);
                            *(turn) += 1;
                            displayTurn(turn);
                            break;

                        case Plante_zone_1://En cas de rencontre d'une plante de la zone 1

                            if(checkItem(inventory, Serpe_bois) == 1)
                            {
                                addPlantInventory(inventory,Zone_1);
                                zone[i-1][j] = Zone_libre;
                                *(turn) += 1;
                                displayTurn(turn);
                            }else
                            {
                                printf("\nVous n'avez pas l'equipement necessaire pour passer !\n\n");
                                displayTurn(turn);
                            }
                            break;

                        case Bois_zone_1:
                            if(checkItem(inventory, Hache_bois) == 1)
                            {
                                addWoodInventory(inventory,Zone_1);
                                zone[i-1][j] = Zone_libre;
                                *(turn) += 1;
                                displayTurn(turn);
                            }else
                            {
                                printf("\nVous n'avez pas l'equipement necessaire pour passer !\n\n");
                                displayTurn(turn);
                            }
                            break;

                        case Rocher_zone_1:
                            if(checkItem(inventory, Pioche_bois) == 1)
                            {
                                addStoneInventory(inventory,Zone_1);
                                zone[i-1][j] = Zone_libre;
                                *(turn) += 1;
                                displayTurn(turn);
                            }else
                            {
                                printf("\nVous n'avez pas l'equipement necessaire pour passer !\n\n");
                                displayTurn(turn);
                            }
                            break;

                        case PNJ:
                            talkPNJ(inventory);
                            *(turn) += 1;
                            displayTurn(turn);
                            break;

                        case Portail_1_et_2:
                            //Si le joueur a le niveau requis
                            generateZone(zone, Zone_2);

                            //Si on se déplace dans une case qui n'existe pas
                        default:
                            printf("\nDeplacement impossible !\n");
                            displayTurn(turn);
                    }
                }else
                {
                    printf("\nDeplacement impossible !\n");
                    displayTurn(turn);
                }
            }
        }
    }
}


//Deplacement vers le bas
void moveBottom(int** zone, InventoryPlayer* inventory, int* turn)
{
    for(int i = 0 ; i < ROW ; i += 1)
    {
        for(int j = 0 ; j < COLUMN ; j += 1)
        {

            if(zone[i][j] == Joueur)//On localise l'emplacement du joueur
            {
                if(i < ROW-1)//On empeche de depasser la limite de la map vers le bas
                {
                    switch (zone[i+1][j])
                    {
                        case Case_infranchissable:
                            printf("Deplacement impossible !\n");
                            displayTurn(turn);
                            break;

                        case Zone_libre: //En cas de déplacement vers une case libre
                            swapCase(&zone[i][j],&zone[i+1][j]);
                            *(turn) += 1;
                            displayTurn(turn);
                            i = ROW;
                            j = COLUMN;
                            break;

                        case Plante_zone_1://En cas de rencontre d'une plante de la zone 1

                            if(checkItem(inventory, Serpe_bois) == 1)
                            {
                                addPlantInventory(inventory,Zone_1);
                                zone[i+1][j] = Zone_libre;
                                *(turn) += 1;
                                displayTurn(turn);
                                i = ROW;
                                j = COLUMN;
                                break;
                            }else
                            {
                                printf("\nVous n'avez pas l'equipement necessaire pour passer !\n\n");
                                break;
                            }

                        case Bois_zone_1:
                            if(checkItem(inventory, Hache_bois) == 1)
                            {
                                addWoodInventory(inventory,Zone_1);
                                zone[i+1][j] = Zone_libre;
                                *(turn) += 1;
                                displayTurn(turn);
                                i = ROW;
                                j = COLUMN;
                                break;

                            }else
                            {
                                printf("\nVous n'avez pas l'equipement necessaire pour passer !\n\n");
                                displayTurn(turn);
                                break;
                            }

                        case Rocher_zone_1:
                            if(checkItem(inventory, Pioche_bois) == 1)
                            {
                                addStoneInventory(inventory,Zone_1);
                                zone[i+1][j] = Zone_libre;
                                *(turn) += 1;
                                displayTurn(turn);
                                i = ROW;
                                j = COLUMN;
                                break;
                            }else
                            {
                                printf("\nVous n'avez pas l'equipement necessaire pour passer !\n\n");
                                displayTurn(turn);
                                break;
                            }

                        case PNJ:
                            talkPNJ(inventory);
                            *(turn) += 1;
                            displayTurn(turn);
                            break;

                        case Portail_1_et_2:
                            //Si le joueur a le niveau requis
                            generateZone(zone, Zone_2);
                            break;

                        default:
                            printf("Deplacement impossible !\n");
                            displayTurn(turn);
                    }
                }else
                {
                    printf("Deplacement impossible !\n");
                    displayTurn(turn);
                }
            }
        }
    }
}


//Deplacement vers la gauche
void moveLeft(int** zone, InventoryPlayer* inventory, int* turn)
{
    for(int i = 0 ; i < ROW ; i += 1)
    {
        for(int j = 0 ; j < COLUMN ; j += 1)
        {

            if(zone[i][j] == Joueur)//On localise l'emplacement du joueur
            {
                if(j > 0)//On empeche de depasser la limite de la map vers la gauche
                {
                    switch (zone[i][j-1])
                    {
                        case Case_infranchissable:
                            printf("Deplacement impossible !\n");
                            displayTurn(turn);
                            break;

                        case Zone_libre: //En cas de déplacement vers une case libre
                            swapCase(&zone[i][j],&zone[i][j-1]);
                            *(turn) += 1;
                            displayTurn(turn);
                            break;

                        case Plante_zone_1://En cas de rencontre d'une plante de la zone 1

                            if(checkItem(inventory, Serpe_bois) == 1)
                            {
                                addPlantInventory(inventory,Zone_1);
                                zone[i][j-1] = Zone_libre;
                                *(turn) += 1;
                                displayTurn(turn);
                            }else
                            {
                                printf("\nVous n'avez pas l'equipement necessaire pour passer !\n\n");
                                displayTurn(turn);
                            }
                            break;

                        case Bois_zone_1:
                            if(checkItem(inventory, Hache_bois) == 1)
                            {
                                addWoodInventory(inventory,Zone_1);
                                zone[i][j-1] = Zone_libre;
                                *(turn) += 1;
                                displayTurn(turn);
                            }else
                            {
                                printf("\nVous n'avez pas l'equipement necessaire pour passer !\n\n");
                                displayTurn(turn);
                            }
                            break;

                        case Rocher_zone_1:
                            if(checkItem(inventory, Pioche_bois) == 1)
                            {
                                addStoneInventory(inventory,Zone_1);
                                zone[i][j-1] = Zone_libre;
                                *(turn) += 1;
                                displayTurn(turn);
                            }else
                            {
                                printf("\nVous n'avez pas l'equipement necessaire pour passer !\n\n");
                                displayTurn(turn);
                            }
                            break;

                        case PNJ:
                            talkPNJ(inventory);
                            *(turn) += 1;
                            displayTurn(turn);
                            break;

                        case Portail_1_et_2:
                            //Si le joueur a le niveau requis
                            generateZone(zone, Zone_2);

                        default:
                            printf("Deplacement impossible !\n");
                            displayTurn(turn);
                    }
                }else
                {
                    printf("Deplacement impossible !\n");
                    displayTurn(turn);
                }
            }
        }
    }
}


//Deplacement vers la droite
void moveRight(int** zone, InventoryPlayer* inventory, int* turn)
{
    for(int i = 0 ; i < ROW ; i += 1)
    {
        for(int j = 0 ; j < COLUMN ; j += 1)
        {

            if(zone[i][j] == Joueur)//On localise l'emplacement du joueur
            {
                if(j < COLUMN-1)//On empeche de depasser la limite de la map vers la droite
                {
                    switch (zone[i][j+1])
                    {
                        case Case_infranchissable:
                            printf("Deplacement impossible !\n");
                            displayTurn(turn);
                            break;

                        case Zone_libre: //En cas de déplacement vers une case libre
                            swapCase(&zone[i][j],&zone[i][j+1]);
                            *(turn) += 1;
                            displayTurn(turn);
                            j = COLUMN;
                            break;

                        case Plante_zone_1://En cas de rencontre d'une plante de la zone 1

                            if(checkItem(inventory, Serpe_bois) == 1)
                            {
                                addPlantInventory(inventory,Zone_1);
                                zone[i][j+1] = Zone_libre;
                                *(turn) += 1;
                                displayTurn(turn);
                                j = COLUMN;
                            }else
                            {
                                printf("\nVous n'avez pas l'equipement necessaire pour passer !\n\n");
                                displayTurn(turn);
                            }
                            break;

                        case Bois_zone_1:
                            if(checkItem(inventory, Hache_bois) == 1)
                            {
                                addWoodInventory(inventory,Zone_1);
                                zone[i][j+1] = Zone_libre;
                                zone[i][j+1] = Zone_libre;
                                *(turn) += 1;
                                displayTurn(turn);
                                j = COLUMN;
                            }else
                            {
                                printf("\nVous n'avez pas l'equipement necessaire pour passer !\n\n");
                                displayTurn(turn);
                            }
                            break;

                        case Rocher_zone_1:
                            if(checkItem(inventory, Pioche_bois) == 1)
                            {
                                addStoneInventory(inventory,Zone_1);
                                zone[i][j+1] = Zone_libre;
                                *(turn) += 1;
                                displayTurn(turn);
                                j = COLUMN;
                            }else
                            {
                                printf("\nVous n'avez pas l'equipement necessaire pour passer !\n\n");
                                displayTurn(turn);
                            }
                            break;

                        case PNJ:
                            talkPNJ(inventory);
                            *(turn) += 1;
                            displayTurn(turn);
                            break;

                        case Portail_1_et_2:
                            //Si le joueur a le niveau requis
                            generateZone(zone, Zone_2);
                            break;

                        default:
                            printf("Deplacement impossible !\n");
                            displayTurn(turn);
                    }
                }else
                {
                    printf("Deplacement impossible !\n");
                    displayTurn(turn);
                }
            }
        }
    }
}


//Deplacement du joueur
void movePlayer(int** zone, InventoryPlayer* inventory, int* turn)
{
    int direction = 0;
    printf("\nDans quelle direction voulez-vous aller ?\n1=>Haut\n2=>Bas\n3=>Droite\n4=>Gauche\n");
    direction = getIntegerOnly();

    if(direction == Top)//Deplacement vers le haut
    {
        moveTop(zone, inventory, turn);

    } else if(direction == Bottom)//Deplacement vers le bad
    {
        moveBottom(zone, inventory, turn);

    } else if(direction == Left)//Deplacement vers la gauche
    {
        moveLeft(zone, inventory, turn);

    } else if(direction == Right)//Deplacement vers la droite
    {
        moveRight(zone, inventory, turn);
    }
}

#ifndef MALLOC_WORLD_MAP_H
#define MALLOC_WORLD_MAP_H

#endif //MALLOC_WORLD_MAP_H