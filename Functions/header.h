/*  header.h
 *
 * Created by Daoud on 09/10/2021.
 *
 * Contain all struct and prototype
 */

#ifndef C_MAIN_H
#define C_MAIN_H

//Ligne et Colonne
#define ROW 5
#define COLUMN 5
#define MAXSLOT 10

//Code de tous les elements de la map
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
    //Monstres = 12 a 98
    Boss = 99
};

//Toutes les zones du jeu
enum Zone{
    Zone_1 = 1,
    Zone_2 = 2,
    Zone_3 = 3
};

//Code de tous les objets du jeu
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
    Chene = 27,
    Diamant = 28,
    Chanvre = 29,
    Epee_diamant = 30,
    Lance_diamant = 31,
    Marteau_diamant = 32,
    Plastron_diamant = 33,

    Potion_vie = 15,
    Potion_vie_2 = 26,
    Potion_vie_3 = 34
};

//Les types d'objet du jeu
enum TypeItem
{
    Equipement = 1,
    Ressource = 2
};

//Les directions pour les déplacement du joueur
enum Direction{
    Top = 1,
    Bottom = 2,
    Right = 3,
    Left = 4
};

//Inventaire
typedef struct {
    int name;
    int quantity;
    int type;
    int durability;
    int maxDurability;
    int damage;
}InventoryPlayer;

//Coffre PNJ
typedef struct {
    int name;
    int quantity;
    int type;
    int durability;
    int maxDurability;
    int damage;
    int* next; //Slot infini
}Chest;

//Personnage principal
typedef struct{
    int xp;
    int level;
    int current_hp;
    int max_hp;
    InventoryPlayer * inventory;
    InventoryPlayer  weapon;


}Player;

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

typedef struct{
    int number;
    char name[25];
    int hp;
    int xp;
    int damage;
}Monster;



//Prototypes
int getIntegerOnly();
void launchGame();
void freeZone(int**);
void usePotion(Player*,int);

void addItemToInventory(InventoryPlayer*, int);
void generateZone(int**, int);

void displayInventory();
void displayTurn(int*);
void displayZone (int**, int);
void moveTop(int**, InventoryPlayer*, int*);
void movePlayer(int**, InventoryPlayer*, int*);
void swapCase(int*, int*);
void viewInventory(InventoryPlayer*);
void itemStart(InventoryPlayer*);

void addPlantInventory(InventoryPlayer*, int);
void addWoodInventory(InventoryPlayer*, int);
void addStoneInventory(InventoryPlayer*, int);
void talkPNJ(InventoryPlayer* inventory);

int checkItem(InventoryPlayer*, enum Item);
void inventoryPnj(InventoryPlayer*);
void craftPnj(InventoryPlayer*);
void brokenTool(InventoryPlayer*, enum Item);
void repairTool(InventoryPlayer*);
void deleteItem(InventoryPlayer*, enum Item);
InventoryPlayer getItemFromInventory (InventoryPlayer* inventory, int index );
void selectWeapon(Player *player);
void selectPotion(Player *player);
void removeElementFromInventory(Player* player, int index);
void monsterAttackPlayer(Player* player, Monster *monster);
#endif //C_HEADER_H
