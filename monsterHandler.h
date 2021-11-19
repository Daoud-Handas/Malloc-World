//
// Created by Kevin Cheng on 19/11/2021.
//

#ifndef MALLOC_WORLD_MONSTERHANDLER_H
#define MALLOC_WORLD_MONSTERHANDLER_H

#endif //MALLOC_WORLD_MONSTERHANDLER_H

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


//////////////////////////////////:

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

