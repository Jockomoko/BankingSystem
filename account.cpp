#include "account.h"
#include <iostream>

int BankAccount::getNumber()
{
    return accountNumber;
}

void BankAccount::deposit(double input)
{
    balance =+ input;
    setTotalDeposit(input);
}

void BankAccount::withdraw(double input)
{
    if(input > balance)
    {
        std::cout << "Tried to withdraw " << input << 
                     "\nInsufficiant funds" << 
                     "\nBalance: " << balance << std::endl;
    }
    else
    {
        balance =- input;

        setTotalWithdraw(input);

        std::cout << "Withdrew " << input << 
                     "\nNew balance: " << balance << std::endl;   
    }
}

void BankAccount::setTotalDeposit(double deposit)
{
    totalDeposit =+ deposit;
}

void BankAccount::setTotalWithdraw(double withdraw)
{
    totalWithdraw =+ withdraw;
}

void BankAccount::printAccountResults()
{
    std::cout << "\n-===-Account #" << accountNumber << "-===-" << std::endl;
    std::cout << "Total withdraws: " << totalWithdraw << std::endl;
    std::cout << "Total deposits: " << totalDeposit << std::endl;
    std::cout << "Final balance: " << balance << std::endl;
    std::cout << std::endl;
}

double BankAccount::getBalance()
{
    return balance;
}
