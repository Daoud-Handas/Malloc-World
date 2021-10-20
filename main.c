#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

#include "main.h"



int main()
{
    int** zone1 = (int**)malloc(ROW * sizeof(int*));
    int game = 1;
    int choice = 0;
    int turn = 1;
    InventoryPlayer inventory[MAXSLOT] = {0,0,0,0};

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
                //generateZone(zone1);
                itemStart(inventory);
                displayZone(zone1);
                displayTurn(&turn);
                while (game < 10){
                    printf("\n\nQue voulez-vous faire ?\n1=>Se deplacer\n2=>Regarder l'inventaire\n");
                    scanf("%d",&choice);
                    if(choice == 1)
                    {
                        movePlayer(zone1,inventory);
                        displayTurn(&turn);
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


    for (int i = 0; i < ROW; i++)
        free(zone1[i]);

    free(zone1);
    return 0;
}
void displayTurn(int* turn)
{
    printf("Tour %d\n",*turn);
    *turn += 1;
}

void displayZone (int **tab)
{
    for(int i = 0 ; i < ROW ; i += 1)
    {
        printf(" %d | %d | %d | %d | %d \n", *(*(tab+i)), *(*(tab+i)+1), *(*(tab+i)+2), *(*(tab+i)+3), *(*(tab+i)+4));
        printf("---+---+---+---+---\n");
    }
}

void generateZone(int **tab)
{
    int i, j;
    int counterPlayer = 0;
    srand(time(NULL));

    for (i = 0; i < ROW; i += 1)
    {

        for (j = 0; j < COLUMN; j += 1)
        {
            if(counterPlayer == 0)
            {
                if (j % 4 == 0 && j != 0)
                {

                    tab[i][j] = rand() % (11 + 1 - 0) + 0; //*(tab[i]+j) == tab[i][j]
                    tab[i][j] == 1 ? counterPlayer += 1 : 1;//Empeche d'avoir 2 joueurs (1) dans la carte

                } else
                {
                    tab[i][j]  = rand() % (11 + 1 - 0) + 0;

                    tab[i][j] == 1 ? counterPlayer += 1 : 1;
                }
            } else {
                if (j % 4 == 0 && j != 0)
                {
                    tab[i][j] = rand() % (11 + 1 - 2) + 2;

                } else
                {
                    tab[i][j] = rand() % (11 + 1 - 2) + 2;
                }
            }
        }
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
    inventory[0].name = Epee_bois;
    inventory[0].type = Equipement;
    inventory[0].durability = 10;
    inventory[0].damage = 10;

    inventory[1].name = Pioche_bois;
    inventory[1].type = Equipement;
    inventory[1].durability = 10;
    inventory[1].damage = 0;

    inventory[2].name = Serpe_bois;
    inventory[2].type = Equipement;
    inventory[2].durability = 1;
    inventory[2].damage = 0;

    inventory[3].name = Hache_bois;
    inventory[3].type = Equipement;
    inventory[3].durability = 10;
    inventory[3].damage = 0;
}

void viewInventory(InventoryPlayer* inventory)
{
    for(int i = 0 ; i < MAXSLOT ; i += 1)
    {
        if(inventory[i].name == 0)
        {
            continue;
        }
        printf("Emplacement : %d\n",i+1);
        printf("Nom : %s\n",getItemName(inventory[i].name));
        printf("Type : %s\n", getItemType(inventory[i].type));
        printf("Degat : %d\nDurabilite : %d\n\n",inventory[i].damage, inventory[i].durability);
    }
}

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

void movePlayer(int** zone, InventoryPlayer* inventory)
{
    int direction;
    printf("Dans quelle direction voulez-vous aller ?(Haut = 1 | Bas = 2 | Gauche = 3 | Droite = 4)\n");
    scanf("%d",&direction);
    if(direction == Top)
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
                                printf("Deplacement impossible !\n");
                                break;

                            case Zone_libre: //En cas de déplacement vers une case libre
                                swapCase(&zone[i][j],&zone[i-1][j]);
                                displayZone(zone);
                                break;

                            case Plante_zone_1://En cas de rencontre d'une plante de la zone 1

                                if(checkItem(inventory, Serpe_bois) == 1)
                                {
                                    addPlantInventory(inventory,Zone_1);
                                    zone[i-1][j] = Zone_libre;
                                    displayZone(zone);
                                }
                                break;

                            case Bois_zone_1:
                                if(checkItem(inventory, Hache_bois) == 1)
                                {
                                    addWoodInventory(inventory,Zone_1);
                                    zone[i-1][j] = Zone_libre;
                                    displayZone(zone);
                                }
                                break;

                            case Rocher_zone_1:
                                if(checkItem(inventory, Pioche_bois) == 1)
                                {
                                    addStoneInventory(inventory,Zone_1);
                                    zone[i-1][j] = Zone_libre;
                                    displayZone(zone);
                                }else
                                {
                                    printf("\nVous n'avez pas l'equiment necessaire pour passer !\n\n");
                                    displayZone(zone);
                                }
                                break;

                            default:
                                printf("Deplacement impossible !\n");
                        }
                    }else
                    {
                        printf("Deplacement impossible !\n");
                    }
                }
            }
        }
    }
}
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


void addPlantInventory(InventoryPlayer* inventory, int zone)
{
    if(zone == Zone_1)
    {
        for(int i = 0 ; i < MAXSLOT ; i += 1)
        {
            if(inventory[i].name == 0)
            {
                inventory[i].name = Herbe;
                inventory[i].type = Ressource;
                for(int i = 0 ; i < MAXSLOT ; i += 1)
                {
                    if(inventory[i].name == Serpe_bois)
                    {
                        inventory[i].durability -= 1;
                        if(inventory[i].durability == 0)
                        {
                            printf("\nVotre %s s'est brisee !\n\n",getItemName(Serpe_bois));
                            deleteItem(inventory, Serpe_bois);
                        }
                    }
                }
                break;
            }
        }
    }
}

void addWoodInventory(InventoryPlayer* inventory, int zone)
{
    if(zone == Zone_1)
    {
        for(int i = 0 ; i < MAXSLOT ; i += 1)
        {
            if(inventory[i].name == 0)
            {
                inventory[i].name = Sapin;
                inventory[i].type = Ressource;
                break;
            }
        }
    }
}

void addStoneInventory(InventoryPlayer* inventory, int zone)
{
    if(zone == Zone_1)
    {
        for(int i = 0 ; i < MAXSLOT ; i += 1)
        {
            if(inventory[i].name == 0)
            {
                inventory[i].name = Pierre;
                inventory[i].type = Ressource;
                break;
            }
        }
    }
}

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
