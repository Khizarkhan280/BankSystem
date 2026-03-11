#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include <vector>
#include "BankAccount.h"
#include <fstream>

class BankSystem
{
private:
    std::vector<BankAccount> accounts;
    int nextAccNum;
    int idx;

    BankAccount* findAccount(int accNum);

public:
    BankSystem();
    int mainScreen();
    int exitMenu();
    int createAccount();
    int deposit();
    int withdraw();
    int displayAccount();
    int showAllAccounts();
    void saveToFile();
    void loadFromFile();
};

#endif