#include <iostream>
#include <sstream>
#include "BankSystem.h"

using namespace std;

BankSystem::BankSystem()
{
    nextAccNum = 100;
    idx = 1;
}

BankAccount* BankSystem::findAccount(int accNum)
{
    for (auto &acc : accounts)
    {
        if (acc.getAcc() == accNum)
        {
            return &acc;
        }
    }
    return nullptr;
}

void BankSystem::saveToFile()
{
    std::ofstream file("accounts.txt");

    for (auto &acc : accounts)
    {
        file << acc.getAcc() << ","
             << acc.getName() << ","
             << acc.getBalance() << "\n";
    }
}

void BankSystem::loadFromFile()
{
    std::ifstream file("accounts.txt");

    int accNum;
    int balance;
    std::string name;

    while (file.good())
    {
        std::string line;
        getline(file, line);

        if (line.empty())
            continue;

        std::stringstream ss(line);

        std::string temp;

        getline(ss, temp, ',');
        accNum = stoi(temp);

        getline(ss, name, ',');

        getline(ss, temp, ',');
        balance = stoi(temp);

        accounts.emplace_back(accNum, name, balance);

        if (accNum >= nextAccNum)
            nextAccNum = accNum + 1;
    }
}

int BankSystem::mainScreen(){
    cout << "Welcome Back!\n\n";

    cout << "What would you like to do today?\n";
    cout << 
        "1 Create Account\n"
        "2 Deposit\n"
        "3 Withdraw\n"
        "4 Display Account\n"
        "5 Show Total Accounts\n"
        "6 Exit\n\n";

    cout << "Choose your option(1-6): ";
    int choice;
    cin >> choice;

    if(choice >=1 && choice <=6){
        return choice;
    }else{
        bool input = false;
        do{
            cout << "\nPlease choose between 1 and 6 inclusive\n";
            
            cout << "Choose your option(1-6): ";
            cin >> choice;
            if(choice >=1 && choice <=6){
                input = true;
            }

        }while(input == false);
        return choice;
    }

}

int BankSystem::exitMenu(){

    int choice;

    cout << "\n1 Main Menu\n";
    cout << "2 Exit\n\n";
    cout << "Choose your option(1-2): ";
    cin >> choice;

    if(choice < 1 || choice > 2){
        do{
            cout << "\nPlease choose 1 or 2\n";
            cout << "Choose your option(1-2): ";\
            cin >> choice;
        }while(choice != 1 && choice != 2);
    }
    if(choice != 2){
        system("cls");
    }
    return choice;
}

int BankSystem::createAccount()
{
    string name;
    int balance,choice;

    system("cls");
    cout << "1 Create Account\n\n";
    cout << "Enter name: ";

    cin.ignore();
    getline(cin, name);

    cout << "Enter initial balance: ";
    cin >> balance;

    accounts.emplace_back(nextAccNum++, name, balance);

    cout << "Account created successfully!\n";

    choice = exitMenu();
    
    return choice;
}

int BankSystem::deposit()
{
    int accNum, amount,choice;
    system("cls");

    cout << "2 Deposit\n\n";
    cout << "Enter account number: ";

    cin >> accNum;

    BankAccount* acc = findAccount(accNum);

    if (acc)
    {
        cout << "Enter amount: ";
        cin >> amount;
        acc->deposit(amount);
    }
    else
    {
        cout << "Account not found!\n";
    }
    choice = exitMenu();
    return choice;

}

int BankSystem::withdraw()
{
    int accNum, amount,choice;

    system("cls");

    cout << "3 Withdraw\n\n";
    cout << "Enter account number: ";

    cin >> accNum;

    BankAccount* acc = findAccount(accNum);

    if (acc)
    {
        cout << "Enter amount: ";
        cin >> amount;
        acc->withdraw(amount);
    }
    else
    {
        cout << "Account not found!\n";
    }
    choice = exitMenu();
    return choice;
}

int BankSystem::displayAccount()
{
    int accNum,choice;
    system("cls");
    cout << "Enter account number: ";
    cin >> accNum;

    BankAccount* acc = findAccount(accNum);

    if (acc)
    {
        system("cls");
        acc->display();
    }
    else
    {
        cout << "Account not found!\n";
    }
    choice = exitMenu();
    return choice;
}

int BankSystem::showAllAccounts()
{
    int choice;
    system("cls");
    BankAccount::showTotalAccounts();

    int i = 1;

    for (auto &acc : accounts)
    {
        cout << i++ << "." << endl;
        acc.display();
    }

    choice = exitMenu();
    return choice;
}