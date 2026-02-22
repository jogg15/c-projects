#include <stdio.h>

#define INTEREST_RATE 3.0
#define TAX_RATE 15.0
#define MIN_AMOUNT 100
#define MAX_AMOUNT 100000
#define YEAR 2026

enum { Jan = 1, Feb, Mar, April, May, Jun, Jul, Aug, Sept, Oct, Nov, Dec };

// nacteni hodnot min-max od uzivatele
unsigned int getInput(const char *label) {
    unsigned int value;

    do {
        printf("Enter %s (%d - %d): ", label, MIN_AMOUNT, MAX_AMOUNT);
        const int valid = scanf("%u", &value);

        while (getchar() != '\n') {}

        if (valid != 1) {
            printf("Invalid input. [100-100000]\n");
            value = 0;
        } else if (value < MIN_AMOUNT || value > MAX_AMOUNT) {
            printf("Value out of range [100-100000].\n");
        }

    } while (value < MIN_AMOUNT || value > MAX_AMOUNT);

    return value;
}

// funkce kontroly prestupneho roku
int isLeapYear(const int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// funkce zjisteni dnu v danem mesici
int getDaysInMonth(const int month) {
    switch (month) {
        case Jan: case Mar: case May: case Jul:
        case Aug: case Oct: case Dec:
            return 31;
        case April: case Jun: case Sept: case Nov:
            return 30;
        case Feb:
            return isLeapYear(YEAR) ? 29 : 28;
        default:
            return -1;
    }
}

// funkce vypoctu dani
double calculateTax(const double interest) {
    return interest * TAX_RATE / 100.0;
}

// funkce vypoctu mesicni sazby
double calculateMonthlyInterest(const double amount) {
    return (amount * INTEREST_RATE / 100.0) / 12.0;
}

void printHeader(const unsigned int startBalance) {
    printf("Savings account (%d) - Interest rate: %.2f %% annually\n", YEAR, INTEREST_RATE);
    printf("Starting balance: %u CZK\n", startBalance);
    printf("-----------------------------------------------------------------------------\n");
    printf("Date        Start        Deposit     Interest    Tax        End\n");
    printf("-----------------------------------------------------------------------------\n");
}

// vypocet pro vsech 12 mesicu a vypise prehled
void generateStatement(const unsigned int startBalance, const unsigned int monthlyDeposit) {
    double start = startBalance;
    double end = 0;

    printHeader(startBalance);

    for (int month = Jan; month <= Dec; month++) {

        const double base = start + monthlyDeposit;
        const double interest = calculateMonthlyInterest(base);
        const double tax = calculateTax(interest);
        end = base + interest - tax;

        printf("%02d.%02d.%d  %10.2f  %8u  %10.2f  %8.2f  %10.2f\n",
               getDaysInMonth(month), month, YEAR,
               start,
               monthlyDeposit,
               interest,
               tax,
               end);

        start = end;
    }

    printf("-----------------------------------------------------------------------------\n");
    printf("End of year balance: %.2f CZK\n", end);
    printf("Total saved: %.2f CZK\n", end - startBalance);
}

int main() {
    const unsigned int startBalance = getInput("starting balance");
    const unsigned int monthlyDeposit = getInput("monthly deposit");

    generateStatement(startBalance, monthlyDeposit);
    return 0;
}
