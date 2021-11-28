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
    //Monstres = 12 � 98
    Boss = 99
};

enum Zone{
    Zone_1 = 1,
    Zone_2 = 2,
    Zone_3 = 3
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

//Inventaire
typedef struct {
    int name;
    int type;
    int durability;
    int damage;
}InventoryPlayer;


//Personnage principal.
typedef struct{
    int xp;
    int level;
    int current_hp;
    int max_hp;
    InventoryPlayer * inventory;
    InventoryPlayer weapon;

}Player;


//Prototypes
void usePotion(Player*,int);

void addItemToInventory(InventoryPlayer*, int);
void generateZone(int**);

void displayInventory();
void displayTurn(int*);
void displayZone (int**, int);

void movePlayer(int**, InventoryPlayer*, int*);
void swapCase(int*, int*);
void viewInventory(InventoryPlayer*);
void itemStart(InventoryPlayer*);

void addPlantInventory(InventoryPlayer*, int);
void addWoodInventory(InventoryPlayer*, int);
void addStoneInventory(InventoryPlayer*, int);

int checkItem(InventoryPlayer*, enum Item);
void deleteItem(InventoryPlayer*, enum Item);
#endif //C_HEADER_H
