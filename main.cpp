#include <iostream>
#include "BankSystem.h"

using namespace std;

int main()
{
    BankSystem bank;
    bank.loadFromFile();

    int choice;

    do
    {
        choice = bank.mainScreen();

        switch (choice)
        {
        case 1:
            choice = bank.createAccount();
            break;

        case 2:
            choice = bank.deposit();
            break;

        case 3:
            choice = bank.withdraw();
            break;

        case 4:
            choice = bank.displayAccount();
            break;

        case 5:
            choice = bank.showAllAccounts();
            break;
        }

    } while (choice != 6 && choice != 2);

    bank.saveToFile();

    return 0;
}