//
// Created by daoud on 15/11/2021.
//

#include "../header.h"

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


//Echange de case
void swapCase(int* case1, int* case2){
    int *tmp;

    tmp = *case1;
    *case1 = *case2;
    *case2 = tmp;
}


//Libère la mémoire allouée de la map
void freeZone(int** zone)
{
    for (int i = 0; i < ROW; i++)
    {
        free(zone[i]);
    }
    free(zone);
}

#ifndef MALLOC_WORLD_MAP_H
#define MALLOC_WORLD_MAP_H

#endif //MALLOC_WORLD_MAP_H