#ifndef BANK_H
#define BANK_H

#include "account.h"
#include <random>
#include <map>
#include <iostream>

typedef class Bank
{
private:
    std::vector<int> accountIDs;

public:
    std::map<int, BankAccount> database;

    void addAccount();

    void showAccountDetails(int id);

    int generateAccountID();

    int getRandomID();
} Bank;

#endif