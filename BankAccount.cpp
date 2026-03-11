#include <iostream>
#include "BankAccount.h"

using namespace std;

int BankAccount ::totalAcc = 0;

BankAccount::BankAccount(int accNum, string name, int balance) : accNum(accNum), name(name)
{
    if (balance >= 0)
        this->balance = balance;
    else
        this->balance = 0;

    totalAcc++;
}

std::string BankAccount::getName()
{
    return name;
}

int BankAccount::getBalance()
{
    return balance;
}

void BankAccount::deposit(int amount)
{
    if (amount > 0)
    {
        balance += amount;
        cout << "Amount deposited Successfully!\n\n";
    }
    else
    {
        cout << "Invalid Amount!\n\n";
    }
}

void BankAccount::withdraw(int amount)
{
    if (amount > 0 && amount <= balance)
    {
        balance -= amount;
        cout << "Amount withdrawal Successfully!\n\n";
    }
    else
    {
        cout << "Invalid Amount!\n\n";
    }
}

void BankAccount::display() const
{
    cout << "   Account: " << accNum << endl;
    cout << "   Name: " << name << endl;
    cout << "   Balance: " << balance << endl
         << endl;
}

int BankAccount::getAcc()
{
    return accNum;
}

void BankAccount::showTotalAccounts()
{
    cout << "Total Accounts: " << totalAcc << "\n\n";
}
