#include <iostream>
#include <thread>
#include <map>
#include "bank.h"
// #include "account.h"

using namespace std::literals::chrono_literals;

void client(Bank input)
{

    for (int i = 0; i < 3; i++)
    {
        int id = input.getRandomID();
        int choice = 1 + rand() % 3;
        double yeag = (double)(rand() % 10000 / 10);
        switch (choice)
        {
        case 1: // check balance
            input.showAccountDetails(id);
            break;
        case 2: // deposit
            input.database[id].deposit(yeag);
            std::cout << "\ndepositing " << yeag << " into account " << id << std::endl;
            break;
        case 3: // withdraw
            input.database[id].withdraw(yeag);
            std::cout << "\nwithdrawing " << yeag << " frim account " << id << std::endl;
            break;
        }
        std::this_thread::sleep_for(2s);
    }
}

int main()
{
    srand(time(0));
    Bank Nordea;
    for (int i = 0; i < 5; i++)
    {
        Nordea.addAccount();
    }
    client(Nordea);
}