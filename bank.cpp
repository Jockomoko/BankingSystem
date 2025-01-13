#include "bank.h"
#include "account.h"


void Bank::addAccount()
{
    int accountID = generateAccountID();

    while (Bank::database.find(accountID) != database.end())
    {
        accountID = generateAccountID();
    }
    
}

void Bank::showAccountDetails()
{

}

int Bank::generateAccountID()
{
    srand(time(0));

    return 1 + rand() % 999;
}