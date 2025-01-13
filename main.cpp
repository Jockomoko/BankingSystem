#include <iostream>
#include <thread>
#include <map>
#include "bank.h"
#include "account.h"

using namespace std::literals::chrono_literals;

void client(Bank input)
{
    int id = input.getRandomID();
    int choice = 1 + rand() % 3;

    for (int i = 0; i < 3; i++)
    {
        switch (choice)
        {
        case 1: // check balance
            input.showAccountDetails(id);
            break;
        case 2: // deposit
            double yeag = (double)(rand() % 10000 / 10);
            input.database[id].deposit(yeag);
            std::cout << "\ndepositing " << yeag << " into account " << id << std::endl;
            break;
        case 3: // withdraw
            double yeag = (double)(rand() % 10000 / 10);
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


}