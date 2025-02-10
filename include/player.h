#ifndef PLAYER_H
#define PLAYER_H

#include "career.h"

typedef struct {
	char name[50]; // Max 49 char name
	CareerType career; // Enum 6 careers
	double money; // Total money
	double income; // Base salary earned each round
	double investments; // Stocks/ Real estate money
	double side_hustle; // Illegal earnings
	double fines; // IRS penalties
	int suspicion; // 0-100 Suspicion score
	int years_played; // How many turns survived
} Player;

void initialize_player(Player *p, const char *name, const CareerType career);
void print_player_info(const Player *p);
void update_income(Player *p);


#endif