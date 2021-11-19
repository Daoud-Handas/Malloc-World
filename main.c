#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "header.h"
#include <time.h>

 Monster monstersZ1[10];
 Monster monstersZ2[10];
 Monster monstersZ3[10];

void generateMonster(Monster monsters[], int i);

int main(){
    srand ( time(NULL) );
    printf("Hello \n");
    generateMonster(monstersZ1,1);
    generateMonster(monstersZ2,2);
    generateMonster(monstersZ3,3);

    printf("NAME %s  \n", monstersZ1[0].name );
    printf("Number %d \n", monstersZ1[0].number );
    printf("HP %d \n", monstersZ1[2].hp);
    printf("XP %d \n", monstersZ1[2].xp);
    printf("DAMAGE %d \n", monstersZ1[2].damage);


}
//int main()
//{
//    int** zone1 = (int**)malloc(ROW * sizeof(int*));
//    int game = 1;
//    int choice = 0;
//    int turn = 1;
//    InventoryPlayer inventory[MAXSLOT];
//
//    for (int i = 0; i < ROW; i++)
//    {
//        zone1[i] = (int*)malloc(COLUMN * sizeof(int));
//    }
//    for(int i = 0  ; i < ROW ; i += 1)
//    {
//        for(int j = 0  ; j < COLUMN ; j += 1)
//        {
//            zone1[i][j] = 0;
//            if(i == 2 & j == 2)
//            {
//                zone1[i][j] = 1;
//            }
//        }
//    }
//
//    printf("BIENVENUE DANS MALLOC WORLD !\n\n\n");
//    do {
//        printf("Que voulez-vous faire ?\n1=>Nouvelle partie\n2=>Continuer\n3=>Quitter\n");
//        scanf("%d",&choice);
//        if(choice)
//        switch(choice)
//        {
//            case 1:
//
//
//
//                //generateZone(zone1);
//                itemStart(inventory);
//                displayZone(zone1);
//                displayTurn(&turn);
//                while (game < 10){
//                    printf("Que voulez-vous faire ?\n1=>Se deplacer\n2=>Regarder l'inventaire\n3=>Combattre\n");
//                    scanf("%d",&choice);
//                    switch(choice){
//                        case 1:
//                            movePlayer(zone1,inventory);
//                            displayTurn(&turn);
//                        case 2:
//                            viewInventory(inventory);
//                        case 3:
//                            playerFight();
//                    }
//
//                    game += 1;
//                }
//                break;
//            case 2:
//                printf("Pas disponible !\n\n\n");
//                break;
//            case 3:
//                printf("A bientot !");
//                game = 0;
//                break;
//            default:
//                printf("Les instructions sont claires pourtant, recommmence !\n");
//                break;
//        }
//    }while(game == 1);
//
//
//    for (int i = 0; i < ROW; i++)
//        free(zone1[i]);
//
//    free(zone1);
//    return 0;
//}



void generateMonster(Monster monsters[], int zone) {
    int randomHp = 0;
    int randomXp = 0;
    int randomDamage = 0;
    static const char *monsterNamesZ1[] = {
            "Phantomtalon",
            "Razorpod",
            "Rottingmirage",
            "Banesnare",
            "Coffinwings",
            "Rotwings",
            "Metalchild",
            "Tombclaw",
            "Emberstrike",
            "Bowelserpent",
    };
    static const char *monsterNamesZ2[] = {
            "Toxinsword",
            "Grieveface",
            "Flamemask",
            "Stenchmorph",
            "Stonemutant",
            "Blazebody",
            "Aurapod",
            "Gallmouth",
            "Vortexfiend",
            "Horrorwoman",
    };
    static const char *monsterNamesZ3[] = {
            "Rustmask",
            "Dustcat",
            "Grimefigure",
            "Shadowcat",
            "Mournwing",
            "Decayboy",
            "Warphag",
            "Dustling",
            "Murklich",
            "Chaosstrike",
    };
    switch (zone) {
        case 1:
            for(int i=0; i < 10; i++){
                randomHp = (rand() % (5 + 1 - 2)) + 2;
                randomXp = (rand() % (4 + 1 - 1)) + 1;
                randomDamage = (rand() % (3 + 1 - 1)) + 1;
                monsters[i].hp = randomHp;
                monsters[i].xp = randomXp;
                monsters[i].damage = randomDamage;
                strcpy(monsters[i].name, monsterNamesZ1[i]);
                monsters[i].number = i+12;


            }

            break;
        case 2:
            for(int i=0; i < 10; i++) {
                randomHp = (rand() % (7 + 1 - 4)) + 4;
                randomXp = (rand() % (6 + 1 - 3)) + 3;
                randomDamage = (rand() % (6 + 1 - 3)) + 3;
                monsters[i].hp = randomHp;
                monsters[i].xp = randomXp;
                monsters[i].damage = randomDamage;
                strcpy(monsters->name, monsterNamesZ2[i]);
                monsters[i].number = i+22;

            }
            break;
        case 3:
            for(int i=0; i < 10; i++) {
                randomHp = (rand() % (15 + 1 - 8)) + 8;
                randomXp = (rand() % (20 + 1 - 7)) + 7;
                randomDamage = (rand() % (9 + 1 - 6)) + 6;
                monsters[i].hp = randomHp;
                monsters[i].xp = randomXp;
                monsters[i].damage = randomDamage;
                strcpy(monsters->name, monsterNamesZ3[i]);
                monsters[i].number = i+32;

            }
            strcpy(monsters[10].name, "Onizuka");
            monsters[10].damage = 15;
            monsters[10].xp = 15;
            monsters[10].hp = 15;
            monsters[10].number = 99;
            break;
        default: break;

    }
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
    inventory[2].durability = 10;
    inventory[2].damage = 0;

    inventory[3].name = Hache_bois;
    inventory[3].type = Equipement;
    inventory[3].durability = 10;
    inventory[3].damage = 0;
}

void viewInventory(InventoryPlayer inventory[])
{
    for(int i = 0 ; inventory[i].durability > 10 ; i += 1)
    {
        printf("Emplacement : %d\n",i+1);
        printf("Nom : %s\n",getItemName(inventory[i].name));
        printf("Type : %s\n", getItemType(inventory[i].type));
        printf("Degat : %d\nDurabilite : %d\n\n",inventory[i].damage, inventory[i].durability);
    }
}

int checkItem(InventoryPlayer inventory[], enum Item item)
{
    for(int i = 0 ; i < MAXSLOT; i += 1)
    {
        if(inventory->name == item)
        {
            return 1;
        }else
        {
            return 0;
        }
    }
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
                            case Zone_libre:
                                swapCase(&zone[i][j],&zone[i-1][j]);
                                displayZone(zone);
                                break;
                            case Plante_zone_1:
                                if(checkItem(inventory, Serpe_bois) == 1)
                                {

                                }

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





void choosenMonster(){
    // check le level de la map,
    //printf("Monstre rencontré :", name, hp, xp);
}

void chooseWeapon(){
}

void choosePotion(){
    printf("Sélectionnez la potion que vous souhaitez boire :\n1 - Potion de vie |\n2 - Potion de vie ||\n3 - Potion de vie |||\n");
    int choice;
    scanf("%d", choice);
    switch(choice){
        case 1:
            ;
        case 2:
            ;
        case 3:
            ;
        default:
            printf("Erreur : Veuillez sélectionner :\n1 - Potion de vie |\n2 - Potion de vie ||\n3 - Potion de vie |||\n");
    }
}


//------------------------------------------------------------------------------------------------------------------------------------


void choseRun(){
}

void levelUp(Player *player) {
    switch (player -> level) {
        case  2: player->max_hp = LIFE + level_2; player ->current_hp = player->max_hp; player->xp = 0; player->level+= 1;break;
        case  3: player->max_hp = LIFE + level_3; player ->current_hp = player->max_hp;player->xp = 0; player->level+= 1;break;
        case  4: player->max_hp = LIFE + level_4; player ->current_hp = player->max_hp;player->xp = 0; player->level+= 1;break;
        case  5: player->max_hp = LIFE + level_5; player ->current_hp = player->max_hp;player->xp = 0; player->level+= 1;break;
        case  6: player->max_hp = LIFE + level_6; player ->current_hp = player->max_hp;player->xp = 0; player->level+= 1;break;
        case  7: player->max_hp = LIFE + level_7; player ->current_hp = player->max_hp;player->xp = 0; player->level+= 1;break;
        case  8: player->max_hp = LIFE + level_8; player ->current_hp = player->max_hp;player->xp = 0; player->level+= 1;break;
        case  9: player->max_hp = LIFE + level_9; player ->current_hp = player->max_hp;player->xp = 0; player->level+= 1;break;
        case  10: player->max_hp = LIFE + level_10; player ->current_hp = player->max_hp;break;
        default: break;
    }

}

void weaponDurability(){
}

//if player die : game --> stop and player retry at the beginning
//if monster die : player win xp and position == 0
void resultFight(){
}

//Choix debut du tour : potion / attaquer / fuir
void beginFight(Player* character){
    int choice;
    printf("Veuillez choisir votre action :\n1 - Attaquer\n2 - Potion\n3 - Fuire\n");
    scanf("%d",choice);
    switch (choice) {
        case 1:
            printf("Vous avez choisi d'attaquer.\n");
            //---> attackMonster();
        case 2:
            printf("Vous avez choisi de vous régénérer.\n");
            //---> choosePotion();
        case 3:
            printf("Vous avez choisi de fuir le combat.");
            //---> choseRun();}
}
levelUp(character);
}

//Initialisation du combat : Le joueur à la possibilité de choisir son arme de combat avant de commencer le premier tour.
// SI ET SEULEMENT SI, IL POSSEDE PLUSIEURS ARMES
void chooseFirstWeapon(){
    printf("Veuillez sélectionner une arme principale de combat.");
    chooseWeapon();
}

//Fonction principal du combat
void playerFight(Player* character) {
    printf("Début du combat.\n");
    chooseFirstWeapon();
    choosenMonster();
//    while(choosenMonster(life == 0)){
//        printf("test");
//    }
}
