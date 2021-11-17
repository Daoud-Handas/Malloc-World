/*  header.h
 *
 * Created by Daoud on 09/10/2021.
 *
 * Contain all struct and prototype
 */

#ifndef C_HEADER_H
#define C_HEADER_H

//Ligne et Colonne
#define ROW 5
#define COLUMN 5
#define MAXSLOT 10
#define LIFE 100

//Code de tous les elements du jeu
enum Map{
    Portail_2_et_3 = -3,
    Portail_1_et_2 = -2,
    Case_infranchissable = -1,
    Zone_libre = 0,
    Joueur = 1,
    PNJ = 2,
    Plante_zone_1 = 3,
    Rocher_zone_1 = 4,
    Bois_zone_1 = 5,
    Plante_zone_2 = 6,
    Rocher_zone_2 = 7,
    Bois_zone_2 = 8,
    Plante_zone_3 = 9,
    Rocher_zone_3 = 10,
    Bois_zone_3 = 11,
    //Monstres = 12 à 98
    Boss = 99
};

enum Level{
    level_1 = 10,
    level_2 = 20,
    level_3= 30,
    level_4 = 40,
    level_5= 50,
    level_6= 50,
    level_7= 50,
    level_8 = 75,
    level_9 = 75,
    level_10= 0,
};



enum MonsterNameZ1{
    Phantomtalon,
    Razorpod,
    Rottingmirage,
    Banesnare,
    Coffinwings,
    Rotwings,
    Metalchild,
    Tombclaw,
    Emberstrike,
    Bowelserpent,
};

enum MonsterNameZ2{
    Toxinsword,
    Grieveface,
    Flamemask,
    Stenchmorph,
    Stonemutant,
    Blazebody,
    Aurapod,
    Gallmouth,
    Vortexfiend,
    Horrorwoman,
};

enum MonsterNameZ3{
    Rustmask,
    Dustcat,
    Grimefigure,
    Shadowcat,
    Mournwing,
    Decayboy,
    Warphag,
    Dustling,
    Murklich,
    Chaosstrike,
};



enum Item{
    Epee_bois = 1,
    Pioche_bois = 2,
    Serpe_bois = 3,
    Hache_bois = 4,
    Sapin = 5,
    Pierre = 6,
    Herbe = 7,
    Epee_pierre = 8,
    Lance_pierre = 9,
    Marteau_pierre = 10,
    Plastron_pierre = 11,
    Pioche_pierre = 12,
    Serpe_pierre = 13,
    Hache_pierre = 14,
    Potion_vie = 15,
    Hetre = 16,
    Fer = 17,
    Lavande = 18,
    Epee_fer = 19,
    Lance_fer = 20,
    Marteau_fer = 21,
    Plastron_fer = 22,
    Pioche_fer = 23,
    Serpe_fer = 24,
    Hache_fer = 25,
    Potion_vie_2 = 26,
    Chene = 27,
    Diamant = 28,
    Chanvre = 29,
    Epee_diamant = 30,
    Lance_diamant = 31,
    Marteau_diamant = 32,
    Plastron_diamant = 33,
    Potion_vie_3 = 34
};

enum TypeItem
{
    Equipement = 1,
    Ressource = 2
};

enum Direction{
    Top = 1,
    Bottom = 2,
    Left = 3,
    Right = 4
};

typedef struct{
    int number;
    char name[25];
    int hp;
    int xp;
    int damage;
}Monster;

//struct Monster t { 12, "Ezequiel", 2, 2};

//Inventaire
typedef struct{
    int name;
    int type;
    int durability;
    int damage;
}InventoryPlayer;
//Voir pour la liste des armes, selection arme début de combat

//Personnage principal
typedef struct{
    int xp;
    int level;
    int current_hp;
    int max_hp;
    InventoryPlayer * inventory;
}Player;


//Prototypes
void usePotion(Player*,int);

void addItemToInventory(InventoryPlayer*, int);
void generateZone(int**);
void displayInventory();
void displayTurn(int*);
void displayZone (int**);
void movePlayer(int**, InventoryPlayer*);
void swapCase(int*, int*);
void viewInventory(InventoryPlayer[]);
void itemStart(InventoryPlayer*);
void playerFight();
void levelUp();
void beginFight();
#endif //C_HEADER_H