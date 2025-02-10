#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "career.h"

void game_loop(Player *p);

int main() {
    srand(time(NULL));

    char name[50];
    printf("Enter your name: ");
    scanf("%49s", name);

    display_career_options();
    CareerType career = select_career();

    Player p;
    initialize_player(&p, name, career);
    print_player_info(&p);

    return 0;
}

