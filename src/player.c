#include <stdio.h>
#include <string.h>
#include "player.h"
#include "career.h"

void initialize_player(Player *p, const char *name, CareerType career) {
    strncpy(p->name, name, 50);
    p->career = career;
    p->years_played = 0;
    p->fines = 0;
    initialize_career_stats(career, &p->money, &p->income, &p->investments, &p->side_hustle, &p->suspicion);
}

void print_player_info(const Player *p) {
    char *career_names[] = { "Freelancer", "Business Owner", "Real Estate Mogul", "Investor", "Crypto Bro", "Scammer" };
    
    printf("\n📊 Player Info:\n");
    printf("Name: %s\n", p->name);
    printf("Career: %s\n", career_names[p->career]);
    printf("Money: $%.2f\n", p->money);
    printf("Base Salary: $%.2f\n", p->income);
    printf("Suspicion Level: %d%%\n", p->suspicion);
}
