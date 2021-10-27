#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

#include "header.h"



int main()
{
    launchGame();
    return 0;
}

//Met toutes les cases à 0
void InitZone(int** zone)
{
    for (int i = 0; i < ROW; i++)
    {
        zone[i] = (int*)malloc(COLUMN * sizeof(int));
    }
    for(int i = 0  ; i < ROW ; i += 1)
    {
        for(int j = 0  ; j < COLUMN ; j += 1)
        {
            zone[i][j] = Zone_libre;
        }
    }
}
void freeZone(int** zone)
{
    for (int i = 0; i < ROW; i++)
    {
        free(zone[i]);
    }
    free(zone);
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
  for(int i = 0  ; i < ROW ; i += 1)
    {
        for(int j = 0  ; j < COLUMN ; j += 1)
        {
            zone1[i][j] = Plante_zone_1;
            if(i == 2 & j == 2)
            {
                zone1[i][j] = 1;
            }
        }
    }


    printf("BIENVENUE DANS MALLOC WORLD !\n\n\n");
    do {
        printf("Que voulez-vous faire ?\n1=>Nouvelle partie\n2=>Continuer\n3=>Quitter\n");
        scanf("%d",&choice);
        if(choice)
            switch(choice)
            {
                case 1:
                    //generateZone(zone1,Zone_1);
                    itemStart(inventory);//Attribue les equipements de départ

                    while (game < 20){

                        displayZone(zone1,Zone_1);
                        printf("\n\nQue voulez-vous faire ?\n1=>Se deplacer\n2=>Regarder l'inventaire\n");
                        scanf("%d",&choice);
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

//Affiche le nombre de tour
void displayTurn(int* turn)
{
    printf("Tour %d\n",*(turn));
}

//Affiche la map
void displayZone (int **tab,int zone)
{
    if(zone == Zone_1)
    {
        printf("=============ZONE1=============\n");
        for(int i = 0 ; i < ROW ; i += 1)
        {

            printf("  %d  |  %d  |  %d  |  %d  |  %d  \n", tab[i][0], tab[i][1], tab[i][2], tab[i][3], tab[i][4]);
            //Ajustement de la map
            printf("-----+-----+-----+-----+-------\n");
        }
    }
}

//Genere une map aleatoire
void generateZone(int **tab, int zone)
{
    int i, j;
    srand(time(NULL));
    int portalRow = (rand() % (4 + 1 - 0) + 0);
    int portalColumn = (rand() % (4 + 1 - 0) + 0);
    int pnjRow = (rand() % (4 + 1 - 0) + 0);
    int pnjColumn = (rand() % (4 + 1 - 0) + 0);

    InitZone(tab);//Met toutes cases à zéro

    if(zone = Zone_1)
    {
        for (i = 0; i < ROW; i += 1)
        {
            for (j = 0; j < COLUMN; j += 1)
            {
                tab[i][j] = rand() % (5 + 1 - 3) + 3;//Remplissage de case aléatoire allant de 0 à 5

                if(tab[i][j] == 1 ||tab[i][j] == 2)
                {
                    continue;
                }
                if(i == 2 && j == 2)
                {
                    tab[i][j] = Joueur;


                }else if(i == pnjRow && j == pnjColumn)
                {
                    tab[i][j] = PNJ;


                } else if(i == portalRow && j == portalColumn)
                {
                    tab[i][j] = Portail_1_et_2;
                }
            }
        }
    } else if (zone = Zone_2)
    {

    }else if (zone = Zone_3)
    {

    }

}

//Traduit les enums des items en renvoyant leur equivalent en string
const char* getItemName(enum Item item)
{
    switch (item)
    {
        case Epee_bois: return "Epee en bois";
        case Pioche_bois: return "Pioche en bois";
        case Serpe_bois: return "Serpe en bois";
        case Hache_bois: return "Hache en bois";
        case Sapin: return "Sapin";
        case Pierre: return "Pierre";
        case Herbe: return "Herbe";
        case Epee_pierre: return "Epee en pierre";
        case Lance_pierre: return "Lance en pierre";
        case Marteau_pierre: return "Marteau en pierre";
        case Plastron_pierre: return "Plastron en pierre";
        case Pioche_pierre: return "Pioche en pierre";
        case Serpe_pierre: return "Serpe en pierre";
        case Hache_pierre: return "Hache en piere";
        case Potion_vie: return "Potion de vie";
        case Hetre: return "Hetre";
        case Fer: return "Fer";
        case Lavande: return "Lavande";
        case Epee_fer: return "Epee en fer";
        case Lance_fer: return "Lance en fer";
        case Marteau_fer: return "Marteau en fer";
        case Plastron_fer: return "Plastron en fer";
        case Pioche_fer: return "Pioche en fer";
        case Serpe_fer: return "Serpe en fer";
        case Hache_fer: return "Hache en fer";
        case Potion_vie_2: return "Potion de vie 2";
        case Chene: return "Chene";
        case Diamant: return "Diamant";
        case Chanvre: return "Chanvre";
        case Epee_diamant: return "Epee en diamant";
        case Lance_diamant: return "Lance en diamant";
        case Marteau_diamant: return "Marteau en diamant";
        case Plastron_diamant: return "Plastron en diamant";
        case Potion_vie_3: return "Potion de vie 3";
    }
}

//Traduit les enums des types des items en renvoyant leur equivalent en string
const char* getItemType(enum TypeItem type)
{
    switch (type)
    {
        case Equipement: return "Equipement";
        case Ressource: return "Ressource";
    }
}

//Equipement donné au début de la partie
void itemStart(InventoryPlayer* inventory)
{
    inventory[0].quantity = 1;
    inventory[0].name = Epee_bois;
    inventory[0].type = Equipement;
    inventory[0].durability = 10;
    inventory[0].maxDurability = 10;
    inventory[0].damage = 10;

    inventory[1].quantity = 1;
    inventory[1].name = Pioche_bois;
    inventory[1].type = Equipement;
    inventory[1].durability = 10;
    inventory[1].maxDurability = 10;
    inventory[1].damage = 0;

    inventory[2].quantity = 1;
    inventory[2].name = Serpe_bois;
    inventory[2].type = Equipement;
    inventory[2].durability = 10;
    inventory[2].maxDurability = 10;
    inventory[2].damage = 0;

    inventory[3].quantity = 1;
    inventory[3].name = Hache_bois;
    inventory[3].type = Equipement;
    inventory[3].durability = 10;
    inventory[3].maxDurability = 10;
    inventory[3].damage = 0;
}

//Regarder le contenu de l'inventaire
void viewInventory(InventoryPlayer* inventory)
{
    for(int i = 0 ; i < MAXSLOT ; i += 1)
    {
        if(inventory[i].name == 0)
        {
            continue;
        }
        printf("Emplacement : %d\n",i+1);
        printf("Quantite : %d\n",inventory[i].quantity);
        printf("Nom : %s\n",getItemName(inventory[i].name));
        printf("Type : %s\n", getItemType(inventory[i].type));

        if(inventory[i].damage > 0 && inventory[i].durability > 0)
        {
            printf("Degat : %d\nDurabilite : %d\n\n",inventory[i].damage, inventory[i].durability);

        }else if(inventory[i].durability > 0)
        {
            printf("Durabilite : %d\n\n",inventory[i].durability);

        }else
        {
            printf("\n\n");
        }
    }
}

//Verification de la presence d'un objet dans l'inventaire
int checkItem(InventoryPlayer* inventory, enum Item item)
{
    int result = 0;
    for(int i = 0 ; i < MAXSLOT && inventory[i].name > 0; i += 1)
    {
        if(inventory[i].name == item)
        {
            result = 1;
        }
    }

    return result;
}

//Reparer arme/outil
void repairTool(InventoryPlayer* inventory)
{
    int item[MAXSLOT] = {0};
    int usedItem = 0;
    int choice = 0;

    for(int i = 0 ; i < MAXSLOT ; i += 1)
    {
        //On verifie si un equipement possede une durabilite inferieur à son maximum (donc usé)
        if(inventory[i].type == Equipement && inventory[i].durability < inventory[i].maxDurability)
        {
            item[usedItem] = i;
            usedItem += 1;
        }
    }

    //Si on trouve une arme/outil usé(e)
    if(usedItem > 0)
    {
        printf("\nIl semblerait que vous avez besoin de mon expertise ! Lequel voulez-vous que je repare ?\n");
        for(int i = 0 ; i < usedItem ; i += 1)
        {
            printf("%d=>%s : Durabilite %d->%d \n", i+1, getItemName(inventory[item[i]].name),inventory[item[i]].durability, inventory[item[i]].maxDurability);
        }
        scanf("%d",&choice);
        switch(choice)
        {
            if (choice <= usedItem && choice > 0)
            {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                    if(choice <= usedItem)
                    {
                        inventory[item[choice-1]].durability = inventory[item[choice-1]].maxDurability;
                        printf("\nEt voila ! Votre %s est comme neuf !\n", getItemName(inventory[item[choice-1]].name));
                    }else
                    {
                        printf("Arretez de vous moquer de moi ! Si vous ne voulez rien reparer changeons de sujet !\n\n");
                    }

                    break;
            }
            default:
                printf("Arretez de vous moquer de moi ! Si vous ne voulez rien reparer changeons de sujet !\n\n");
                break;
        }
    }else
    {
        printf("\nVous n'avez rien a reparer, arretez de me faire perdre du temps !\n");
    }
}

//Se deplacer vers le pnj
void talkPNJ(InventoryPlayer* inventory)
{
    int choice;
    int end = 1;
    printf("\nSalutation camarade ! Que puis-je faire pour vous ?\n1=>Reparer equipement\n2=>Construire equipement\n3=>Gerer l'inventaire\n4=>Partir\n");
    scanf("%d",&choice);
    while(end == 1)
    {

        switch(choice)
        {
            case 1:
                repairTool(inventory);
                printf("\nBesoin d'autre chose ?\n1=>Reparer equipement\n2=>Construire equipement\n3=>Gerer l'inventaire\n4=>Partir\n");
                scanf("%d",&choice);
                break;
            case 2:
                printf("2");
                printf("\nBesoin d'autre chose ?\n1=>Reparer equipement\n2=>Construire equipement\n3=>Gerer l'inventaire\n4=>Partir\n");
                scanf("%d",&choice);
                break;
            case 3:
                printf("3");
                printf("\nBesoin d'autre chose ?\n1=>Reparer equipement\n2=>Construire equipement\n3=>Gerer l'inventaire\n4=>Partir\n");
                scanf("%d",&choice);
                break;
            case 4:
                printf("\nA bientot !\n\n");
                end = 0;
                break;
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
    printf("\nDans quelle direction voulez-vous aller ?\n1=>Haut\n2=>Bas\n3=>Gauche\n4=>Droite\n");
    scanf("%d",&direction);

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

//Suppression d'un objet dans l'inventaire
void deleteItem(InventoryPlayer* inventory, enum Item item)
{
    for(int i = 0 ; i < MAXSLOT ; i += 1)
    {
        if(inventory[i].name == item)
        {
            inventory[i].name = 0;
            inventory[i].type = 0;
            inventory[i].damage = 0;
            inventory[i].durability = 0;
            break;
        }
    }
}

//Brisage d'un outil/arme
void brokenTool(InventoryPlayer* inventory, enum Item item)
{
    printf("\nVotre %s s'est brisee !\n\n",getItemName(item));
    deleteItem(inventory, item);
}
//Ajout d'une plante dans l'inventaire
void addPlantInventory(InventoryPlayer* inventory, int zone)
{
    srand(time(NULL));
    int counter = 0;

    if(zone == Zone_1)
    {

        for(int i = 0 ; i < MAXSLOT ; i += 1)
        {
            printf("\nDurabilite : %d\n",inventory[2].durability);
            if(inventory[i].name == 0)//Si un emplacement est vide
            {
                inventory[i].quantity = inventory[i].quantity + rand() % (4 + 1 - 1) + 1;//Possibilité d'avoir entre 1 et 4 herbes
                inventory[i].name = Herbe;
                inventory[i].type = Ressource;

                for(i = 0 ; i < MAXSLOT ; i += 1)
                {
                    if(inventory[i].name == Serpe_bois)
                    {
                        inventory[i].durability -= 1;//Usure de 10% sur les plantes de zone 1

                        if(inventory[i].durability == 0)
                        {
                            brokenTool(inventory,Serpe_bois);//L'outil se casse
                        }
                    }
                }
                break;
            }else if(inventory[i].name == Herbe && inventory[i].quantity < 5)//Si le joueur possède déjà de l'herbe
            {

                inventory[i].quantity += rand() % (4 + 1 - 1) + 1;//Possibilité d'avoir entre 1 et 4 herbes

                if(inventory[i].quantity > 20)
                {
                    //On récupère les ressources au dessus de 20
                    while(inventory[i].quantity > 20)
                    {
                        inventory[i].quantity -= 1;
                        counter += 1;
                    }
                    for(i = 0 ; i < MAXSLOT ; i += 1)
                    {
                        if(inventory[i].name == 0)//Si un emplacement est vide
                        {
                            inventory[i].quantity += counter;//Met sur le nouvel emplacement le reste des ressources
                            inventory[i].name = Herbe;
                            inventory[i].type = Ressource;
                            break;
                        }
                    }
                }

                i = 0;//On refait le tour de l'inventaire
                for(i = 0 ; i < MAXSLOT ; i += 1)
                {
                    //Effet sur l'outil
                    if(inventory[i].name == Serpe_bois)
                    {
                        inventory[i].durability -= 1;//Usure de 10% sur les plantes de zone 1

                        if(inventory[i].durability == 0)
                        {
                            brokenTool(inventory,Serpe_bois);//L'outil se casse
                        }
                        break;
                    }
                }
                break;

            }else if(i == MAXSLOT-1)//On a parcouru tout l'inventaire
            {
                printf("\nVous n'avez plus de place dans votre inventaire !\n");
            }
        }
    }
}

//Ajout de bois dans l'inventaire
void addWoodInventory(InventoryPlayer* inventory, int zone)
{
    srand(time(NULL));
    int counter = 0;

    if(zone == Zone_1)
    {
        for(int i = 0 ; i < MAXSLOT ; i += 1)
        {
            if(inventory[i].name == 0)
            {
                inventory[i].quantity = inventory[i].quantity + rand() % (4 + 1 - 1) + 1;//Possibilité d'avoir entre 1 et 4 sapins
                inventory[i].name = Sapin;
                inventory[i].type = Ressource;
                for(i = 0 ; i < MAXSLOT ; i += 1)
                {
                    if(inventory[i].name == Hache_bois)
                    {
                        inventory[i].durability -= 1;
                        if(inventory[i].durability == 0)
                        {
                            printf("\nVotre %s s'est brisee !\n\n",getItemName(Hache_bois));
                            deleteItem(inventory, Hache_bois);
                        }
                    }
                }
                break;
            }else if(inventory[i].name == Sapin)//Si le joueur possède déjà des sapins
            {

                inventory[i].quantity += rand() % (4 + 1 - 1) + 1;//Possibilité d'avoir entre 1 et 4 sapins

                if(inventory[i].quantity > 20)
                {
                    //On récupère les ressources au dessus de 20
                    while(inventory[i].quantity > 20)
                    {
                        inventory[i].quantity -= 1;
                        counter += 1;
                    }

                    i = 0;//On refait le tour de l'inventaire
                    for(i = 0 ; i < MAXSLOT ; i += 1)
                    {
                        if(inventory[i].name == 0)//Si un emplacement est vide
                        {
                            inventory[i].quantity += counter;//Met à l'emplacement suivant le reste des ressources
                            inventory[i].name = Sapin;
                            inventory[i].type = Ressource;
                            break;
                        }
                    }
                }
                break;

            }else if(i == MAXSLOT-1)//On a parcouru tout l'inventaire
            {
                printf("\nVous n'avez plus de place dans votre inventaire !\n");
            }
        }
    }
}

//Ajout d'une pierre dans l'inventaire
void addStoneInventory(InventoryPlayer* inventory, int zone)
{
    srand(time(NULL));
    int counter = 0;

    if(zone == Zone_1)
    {
        for(int i = 0 ; i < MAXSLOT ; i += 1)
        {
            if(inventory[i].name == 0)
            {
                inventory[i].quantity = inventory[i].quantity + rand() % (4 + 1 - 1) + 1;//Possibilité d'avoir entre 1 et 4 pierres
                inventory[i].name = Pierre;
                inventory[i].type = Ressource;

                for(i = 0 ; i < MAXSLOT ; i += 1)
                {
                    if(inventory[i].name == Pioche_bois)
                    {
                        inventory[i].durability -= 1;
                        if(inventory[i].durability == 0)
                        {
                            printf("\nVotre %s s'est brisee !\n\n",getItemName(Pioche_bois));
                            deleteItem(inventory, Pioche_bois);
                        }
                    }
                }
            }else if(inventory[i].name == Pierre)//Si le joueur possède déjà des pierres
            {

                inventory[i].quantity += rand() % (4 + 1 - 1) + 1;//Possibilité d'avoir entre 1 et 4 pierres

                if(inventory[i].quantity > 20)
                {
                    //On récupère les ressources au dessus de 20
                    while(inventory[i].quantity > 20)
                    {
                        inventory[i].quantity -= 1;

                        counter += 1;
                    }

                    i = 0;//On refait le tour de l'inventaire
                    for(i = 0 ; i < MAXSLOT ; i += 1)
                    {
                        if(inventory[i].name == 0)//Si un emplacement est vide
                        {
                            inventory[i].quantity += counter;//Met à l'emplacement suivant le reste des ressources
                            inventory[i].name = Pierre;
                            inventory[i].type = Ressource;
                            break;
                        }
                    }
                }
                break;

            }else if(i == MAXSLOT-1)//On a parcouru tout l'inventaire
            {
                printf("\nVous n'avez plus de place dans votre inventaire !\n");
            }
        }
    }
}

//Echange de case
void swapCase(int* case1, int* case2){
    int *tmp;

    tmp = *case1;
    *case1 = *case2;
    *case2 = tmp;
}

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
