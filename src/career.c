#include <stdio.h>
#include "career.h"

void display_career_options() {
    printf("\nChoose your career:\n");
    printf("1. Freelancer 🖥️\n");
    printf("2. Business Owner 🏢\n");
    printf("3. Real Estate Mogul 🏗️\n");
    printf("4. Investor 📈\n");
    printf("5. Crypto Bro 🪙\n");
    printf("6. Scammer 🕵️‍♂️\n");
}

CareerType select_career() {
    int choice;
    CareerType selected_career;

    while (1) {
        printf("Enter choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid input! Please enter a number between 1 and 6.\n");
            while (getchar() != '\n');
            continue;
        }
        switch (choice) {
            case 1: selected_career = FREELANCER; break;
            case 2: selected_career = BUSINESS_OWNER; break;
            case 3: selected_career = REAL_ESTATE_MOGUL; break;
            case 4: selected_career = INVESTOR; break;
            case 5: selected_career = CRYPTO_BRO; break;
            case 6: selected_career = SCAMMER; break;
            default:
                printf("❌ Invalid choice! Please enter a number between 1 and 6.\n");
                continue;
        }
        break;
    }
    return selected_career;
}

void initialize_career_stats(CareerType career, double *money, double *income, double *investments, double *side_hustle, int *suspicion) {
    switch (career) {
        case FREELANCER:
            *money = 25000;
            *income = 40000;
            *investments = 0;
            *side_hustle = 0;
            *suspicion = 5;
            break;
        case BUSINESS_OWNER:
            *money = 100000;
            *income = 80000;
            *investments = 200000;
            *side_hustle = 0;
            *suspicion = 15;
            break;
        case REAL_ESTATE_MOGUL:
            *money = 500000;
            *income = 50000;
            *investments = 300000;
            *side_hustle = 0;
            *suspicion = 25;
            break;
        case INVESTOR:
            *money = 200000;
            *income = 100000;
            *investments = 500000;
            *side_hustle = 0;
            *suspicion = 30;
            break;
        case CRYPTO_BRO:
            *money = 10000;
            *income = 0;
            *investments = 100000;
            *side_hustle = 0;
            *suspicion = 40;
            break;
        case SCAMMER:
            *money = 5000;
            *income = 0;
            *investments = 0;
            *side_hustle = 50000;
            *suspicion = 50;
            break;
    }
}
