#include <stdio.h>

// uvedeni konstant
#define INTEREST_RATE 3.0
#define TAX_RATE 15.0
#define MIN_AMOUNT 100
#define MAX_AMOUNT 100000
#define YEAR 2026

// mesice
enum { Jan = 1, Feb, Mar, April, May, Jun, Jul, Aug, Sept, Oct, Nov, Dec };

// nacteni hodnot min-max od uzivatele
unsigned int getInput(const char *label) {
    unsigned int value;
    int valid;

    do {
        printf("Enter %s (%d - %d): ", label, MIN_AMOUNT, MAX_AMOUNT);
        valid = scanf("%u", &value);

        while (getchar() != '\n');

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
int isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// funkce zjisteni dnu v danem mesici
int getDaysInMonth(int month) {
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
double calculateTax(double interest) {
    return interest * TAX_RATE / 100.0;
}

// funkce vypoctu mesicni sazby
double calculateMonthlyInterest(double amount) {
    return (amount * INTEREST_RATE / 100.0) / 12.0;
}

// vypsani dat do konzole
void printHeader(unsigned int startBalance) {
    printf("Savings account (%d) - Interest rate: %.2f %% annually\n", YEAR, INTEREST_RATE);
    printf("Starting balance: %u CZK\n", startBalance);
    printf("-----------------------------------------------------------------------------\n");
    printf("Date        Start        Deposit     Interest    Tax        End\n");
    printf("-----------------------------------------------------------------------------\n");
}

// vypocet pro vsech 12 mesicu a vypise prehled
void generateStatement(unsigned int startBalance, unsigned int monthlyDeposit) {
    double start = startBalance;
    double end = 0;

    printHeader(startBalance);

    for (int month = Jan; month <= Dec; month++) {

        double base = start + monthlyDeposit;
        double interest = calculateMonthlyInterest(base);
        double tax = calculateTax(interest);
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

// hlavni funkce na zahajeni vypoctu
int main() {
    unsigned int startBalance = getInput("starting balance");
    unsigned int monthlyDeposit = getInput("monthly deposit");

    generateStatement(startBalance, monthlyDeposit);
    return 0;
}
