#include "bank.h"
#include "account.h"

void Bank::addAccount()
{
    int accountID = generateAccountID();

    while (Bank::database.find(accountID) != database.end())
    {
        accountID = generateAccountID();
    }
    Bank::database.insert({accountID, BankAccount(accountID)});
    Bank::accountIDs.push_back(accountID);
    std::cout << "Accoint Id: " << accountID << " has been added to the Database" << std::endl;
}


void Bank::showAccountDetails(int id)
{
    if (Bank::database.find(id) != database.end())
    {
        std::cout << "Couldnt finde the ID" << std::endl;
    }
    else
    {
        std::cout << "Kontrollerar saldo för konto " << id << ": " << Bank::database.at(id).getBalance() << std::endl;
    }
}

int Bank::generateAccountID()
{

    return 1 + rand() % 999;
}

int Bank::getRandomID() 
{
    int c = rand() % accountIDs.size();
    return accountIDs[c];
}