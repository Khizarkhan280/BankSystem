# Bank System (C++ OOP Project)

A simple **Bank Management System** built using **C++ and Object-Oriented Programming** concepts.
This project simulates basic banking operations such as creating accounts, depositing money, withdrawing money, and displaying account details.

## Features

* Create new bank accounts
* Deposit money into an account
* Withdraw money from an account
* Display account information
* Show all accounts in the system
* Save and load account data using file handling

## Concepts Used

This project demonstrates the following C++ concepts:

* Classes and Objects
* Encapsulation
* Constructors
* Static Members
* Vectors (STL)
* File Handling (`fstream`)
* Modular Project Structure (`.h` and `.cpp` files)

## Project Structure

```
BankSystem
│
├── BankAccount.h
├── BankAccount.cpp
│
├── BankSystem.h
├── BankSystem.cpp
│
├── main.cpp
│
├── accounts.txt
│
└── README.md
```

## How to Compile and Run

Using **g++ compiler**:

```
g++ main.cpp BankAccount.cpp BankSystem.cpp -o bank
./bank
```

## Example Operations

```
1 Create Account
2 Deposit
3 Withdraw
4 Display Account
5 Show Total Accounts
6 Exit
```

## Future Improvements

Possible features that can be added:

* Account deletion
* Transaction history
* Password protected accounts
* Interest calculation
* GUI version

## Author

Muhammad Khizar Khan

---

This project was created for learning **C++ Object-Oriented Programming and basic system design**.
