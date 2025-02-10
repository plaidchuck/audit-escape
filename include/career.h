#ifndef CAREER_H
#define CAREER_H

typedef enum {
	FREELANCER,
	BUSINESS_OWNER,
	REAL_ESTATE_MOGUL,
	INVESTOR,
	CRYPTO_BRO,
	SCAMMER
} CareerType;

void display_career_options();
CareerType select_career();
void initialize_career_stats(CareerType career, double *money,
							double *income, double *investments,
							double *side_hustle, int *suspicion);

#endif