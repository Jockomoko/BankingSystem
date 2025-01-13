#ifndef BANK_H
#define BANK_H

#include "account.h"
#include <random>
#include <map>
#include <iostream>

typedef class Bank {
    private:
        std::map<int, BankAccount> database;
    
    public: 
        void addAccount();

        void showAccountDetails();

        int generateAccountID();
} Bank;

#endif