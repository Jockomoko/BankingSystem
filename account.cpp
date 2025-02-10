#include "account.h"
#include <iostream>

int BankAccount::getNumber()
{
    return accountNumber;
}

/**
 * @brief Function for depositing money to an account
 * 
 * @param input Amount to be deposited
 */
void BankAccount::deposit(double input)
{
    balance += input;
    addTotalDeposit(input);
}

/**
 * @brief Function for withdrawing money from an account
 * 
 * @param input Amount to be withdrawn
 */
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
        balance -= input;

        addTotalWithdraw(input);

        std::cout << "Withdrew " << input << 
                     "\nNew balance: " << balance << std::endl;   
    }
}

/**
 * @brief Functino for logging total deposit amount for a specific account
 * 
 * @param deposit Deposit amount
 */
void BankAccount::addTotalDeposit(double deposit)
{
    totalDeposit =+ deposit;
}

/**
 * @brief Function for logging total withdraw amount for a specific account
 * 
 * @param withdraw Withdraw amount
 */
void BankAccount::addTotalWithdraw(double withdraw)
{
    totalWithdraw =+ withdraw;
}

/**
 * @brief Printing the total amount of deposit and withdraw and final balance
 * 
 */
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
