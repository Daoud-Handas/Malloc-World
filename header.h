/*  header.h
 *
 * Created by Daoud on 09/10/2021.
 *
 * Contain all struct and prototype
 */

#ifndef C_HEADER_H
#define C_HEADER_H

//Code de tous les elements du jeu
enum map{
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

enum player{
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
    Hêtre = 16,
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
    Mance_diamant = 31,
    Marteau_diamant = 32,
    Plastron_diamant = 33,
    Potion_vie_3 = 34
};

//Inventaire
typedef struct{
    int name;
    int type;
    int info;
    struct inventory *next;
}inventory;


//Personnage principal
struct mainCaractere{
    int xp;
    int level;
    int current_hp;
    int max_hp;
    inventory* inventory;
};


void usePotion(struct mainCaractere*,int);
#endif //C_HEADER_H