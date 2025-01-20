#include <iostream>
#include <thread>
#include <map>
#include "bank.h"
#include <mutex>
#include <chrono>
// #include "account.h"

using namespace std::literals::chrono_literals;
std::mutex mtx;

void client(Bank input)
{
    
    for (int i = 0; i < 3; i++)
    {
        std::lock_guard<std::mutex> lock(mtx);
        srand(time(0));
        int id = input.getRandomID();
        int choice = 1 + rand() % 3;
        double yeag = (double)((rand() % 10000) / 10);
        //std::cout << "\nThread " << std::this_thread::get_id() << ": \n" << std::endl;
        std::cout << "\n-===-Account " << id << "-===-\n";
        switch (choice)
        {
        case 1: // check balance
            std::cout << "Checking balance: " << input.database[id].getBalance() << std::endl;
            break;
        case 2: // deposit
            input.database[id].deposit(yeag);
            std::cout << "Depositing " << yeag <<
                         "\nNew balance: " << input.database[id].getBalance() << std::endl;
            break;
        case 3: // withdraw
            input.database[id].withdraw(yeag);
            break;
        }
        std::this_thread::sleep_for(2s);
    }
}

int main()
{
    Bank Nordea;
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; i++)
    {
        Nordea.addAccount();
    }

    for (int i = 0; i < 5; i++)
    {
        threads.emplace_back(client, Nordea);
    };
    for (auto &thread : threads)
    {
        thread.join();
    }
}