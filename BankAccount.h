#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount
{
private:
    int accNum;
    std::string name;
    int balance;

public:
    static int totalAcc;

    BankAccount(int accNum, std::string name, int balance);

    void deposit(int amount);
    void withdraw(int amount);
    void display() const;
    int getAcc();
    std::string getName();
    int getBalance();
    static void showTotalAccounts();
};

#endif