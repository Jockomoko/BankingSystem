#include "bank.h"
#include "account.h"
#include <mutex>

/**
 * @brief Function that generates a unique accountID and creates a new account with
 * sid ID and places it in the account container
 */
void Bank::addAccount()
{
    std::lock_guard<std::mutex> lock(bankMutex);
    int accountID = generateAccountID();

    while (Bank::database.find(accountID) != database.end())
    {
        accountID = generateAccountID();
    }
    Bank::database.emplace(accountID, BankAccount(accountID, 5000.0));
    Bank::accountIDs.push_back(accountID);
    std::cout << "Account Id: " << accountID << " has been added to the Database with balance: " << Bank::database[accountID].getBalance() << std::endl;
}

/**
 * @brief Funtion for generating a random ID between 1 + 1000
 * 
 * @return int 
 */
int Bank::generateAccountID()
{
    return 1 + rand() % 999;
}

/**
 * @brief Function that fetch a random accountID from the existing accounts
 * 
 * @return int 
 */
int Bank::getRandomID()
{
    int c = rand() % accountIDs.size();
    return accountIDs[c];
}

std::vector<int> Bank::getAllAccountIds()
{
    return accountIDs;
}