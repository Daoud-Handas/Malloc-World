//
// Created by daoud on 15/11/2021.
//

#include "header.h"

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
//Select Elem from inventory
 InventoryPlayer getItemFromInventory (InventoryPlayer* inventory, int index ){
    for(int i = 0 ; i < MAXSLOT ; i += 1)
    {
        if(i == index ){

            return  inventory[i];;
        }

    }



};


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
        printf("==========Emplacement %d==========\n",i+1);
        printf("|          Quantite : %d          \n",inventory[i].quantity);
        printf("|          Nom : %s          \n",getItemName(inventory[i].name));
        printf("|          Type : %s          \n", getItemType(inventory[i].type));

        if(inventory[i].damage > 0 && inventory[i].durability > 0)
        {
            printf("|          Degat : %d          \n|          Durabilite : %d          \n\n",inventory[i].damage, inventory[i].durability);

        }else if(inventory[i].durability > 0)
        {
            printf("|          Durabilite : %d          \n\n",inventory[i].durability);

        }else
        {
            printf("\n\n");
        }
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


//Brisage d'un outil/arme
void brokenTool(InventoryPlayer* inventory, enum Item item)
{
    printf("\nVotre %s s'est brisee !\n\n",getItemName(item));
    deleteItem(inventory, item);
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
        printf("\nIl semblerait que vous avez besoin de mon expertise ! Lequel de vos equipements voulez-vous que je repare ?\n");
        for(int i = 0 ; i < usedItem ; i += 1)
        {
            printf("%d=>%s : Durabilite %d->%d \n", i+1, getItemName(inventory[item[i]].name),inventory[item[i]].durability, inventory[item[i]].maxDurability);
        }
        choice = getIntegerOnly();
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
            }else if(inventory[i].name == Herbe && inventory[i].quantity < 20)//Si le joueur possède déjà de l'herbe
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
            }else if(inventory[i].name == Sapin && inventory[i].quantity < 20)//Si le joueur possède déjà du sapin
            {

                inventory[i].quantity += rand() % (4 + 1 - 1) + 1;//Possibilité d'avoir entre 1 et 4 sapin

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
                            inventory[i].name = Sapin;
                            inventory[i].type = Ressource;
                            break;
                        }
                    }
                }

                i = 0;//On refait le tour de l'inventaire
                for(i = 0 ; i < MAXSLOT ; i += 1)
                {
                    //Effet sur l'outil
                    if(inventory[i].name == Hache_bois)
                    {
                        inventory[i].durability -= 1;//Usure de 10% sur les bois de zone 1

                        if(inventory[i].durability == 0)
                        {
                            brokenTool(inventory,Hache_bois);//L'outil se casse
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
            }else if(inventory[i].name == Pierre && inventory[i].quantity < 20)//Si le joueur possède déjà des pierres
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
                    for(i = 0 ; i < MAXSLOT ; i += 1)
                    {
                        if(inventory[i].name == 0)//Si un emplacement est vide
                        {
                            inventory[i].quantity += counter;//Met sur le nouvel emplacement le reste des ressources
                            inventory[i].name = Pierre;
                            inventory[i].type = Ressource;
                            break;
                        }
                    }
                }

                i = 0;//On refait le tour de l'inventaire
                for(i = 0 ; i < MAXSLOT ; i += 1)
                {
                    //Effet sur l'outil
                    if(inventory[i].name == Pioche_bois)
                    {
                        inventory[i].durability -= 1;//Usure de 10% sur les pierres de zone 1

                        if(inventory[i].durability == 0)
                        {
                            brokenTool(inventory,Pioche_bois);//L'outil se casse
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


//Gestion du coffre
void inventoryPnj(InventoryPlayer* inventory)
{
    int choice = 0;

    printf("Vous voulez acceder a votre coffre ? Tres bien, que voulez-vous faire ?\n1=>Deposer objet\n2=>Retirer objet\n\n");
    choice = getIntegerOnly();

    switch (choice)
    {
        case 1:
            /*printf("Tres bien, que voulez-vous deposer dans le coffre ?\n");
            viewInventory(inventory);*/
            printf("Le coffre est en reparation, revenez plus tard !\n");

            break;

        case 2:
            //printf("Très bien, que voulez-vous retirer du coffre ?\n");
            printf("Le coffre est en reparation, revenez plus tard !\n");
    }
}

//Crafting
void craftPnj(InventoryPlayer* inventoryPlayer)
{

}

void removeElementFromInventory(Player player, int index){
    for(int i = index; i < MAXSLOT - 1; i++) player.inventory[i] = player.inventory[i + 1];
};


#ifndef MALLOC_WORLD_MAP_H
#define MALLOC_WORLD_MAP_H

#endif //MALLOC_WORLD_MAP_H
