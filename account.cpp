#include "account.h"

int BankAccount::getNumber ()
{
    return accountNumber;
};

void BankAccount::deposit (int input)
{
    balance =+ input;
}

void BankAccount::withdraw (int input)
{
    balance =- input;
}

double BankAccount::getBalance ()
{
    return balance;
}