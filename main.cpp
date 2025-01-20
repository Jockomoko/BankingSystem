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
    std::lock_guard<std::mutex> lock(mtx);
    for (int i = 0; i < 3; i++)
    {
        srand(time(0));
        int id = input.getRandomID();
        int choice = 1 + rand() % 3;
        double yeag = (double)(rand() % 10000 / 10);
        std::cout << "Thread " << std::this_thread::get_id() << ": ";
        switch (choice)
        {
        case 1: // check balance
            std::cout << "Account " << id << " has a balance of: " << input.database[id].getBalance() << std::endl;
            break;
        case 2: // deposit
            input.database[id].deposit(yeag);
            std::cout << "\ndepositing " << yeag << " into account " << id << std::endl;
            break;
        case 3: // withdraw
            input.database[id].withdraw(yeag);
            std::cout << "\nwithdrawing " << yeag << " from account " << id << std::endl;
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