#include <stdio.h>
#include "../include/career.h"

void test_select_career() {
	char *career_names[] = { "Freelancer", "Business Owner", "Real Estate Mogul", "Investor", "Crypto Bro", "Scammer" };
	printf("*---- Manual Test ----*, choose Career type(1-6):\n");
	display_career_options();
	CareerType career = select_career();
	printf("Career selected: %s\n", career_names[career]);
}

int main() {
	printf("Running career tests...\n\n");
	test_select_career();
	return 0;
}