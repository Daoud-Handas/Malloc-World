#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"
int main() {
    struct mainCaractere me;

    return 0;
}
void usePotion (struct mainCaractere* character, int potion){
    if(potion == Potion_vie)
    {
        character->hp += 30;
    }
}


