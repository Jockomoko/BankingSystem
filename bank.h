#ifndef BANK_H
#define BANK_H

#include "account.h"
#include <random>
#include <map>
#include <vector>
#include <iostream>
#include <mutex>

class Bank
{
private:
    std::mutex bankMutex;
    std::vector<int> accountIDs;

public:
    std::map<int, BankAccount> database;

    void addAccount();

    // void showAccountDetails(int id);

    int generateAccountID();

    int getRandomID();

    std::vector<int> getAllAccountIds();
};

#endif