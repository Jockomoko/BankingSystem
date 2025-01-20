#include "account.h"
#include <iostream>

int BankAccount::getNumber()
{
    return accountNumber;
};

void BankAccount::deposit(int input)
{
    balance = +input;
}

void BankAccount::withdraw(int input)
{
    if(input > balance || balance == 0.0)
    {
        std::cout << "Tried to withdraw " << input << 
                     "\nInsufficiant funds" << 
                     "\nBalance: " << balance << std::endl;
    }
    else
    {
        balance = -input;

        std::cout << "Withdrew " << input << 
                     "\nNew balance: " << balance << std::endl;   
    }
}

double BankAccount::getBalance()
{
    return balance;
}
