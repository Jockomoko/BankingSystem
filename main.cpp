/**
 * @file main.cpp
 * @author Group Stockholm 2
 * @brief Banking system with simulated user activity
 * @version 0.1
 * @date 2025-02-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <thread>
#include <map>
#include "bank.h"
#include "account.h"
#include <mutex>
#include <chrono>

using namespace std::literals::chrono_literals;
std::mutex mtx;
bool processed = false;
std::string data;
/**
 * @brief main thread operation for simulating account activity
 * 
 * @param input Input desired Bank object
 */
void client(Bank& input)
{
    std::lock_guard lk(mtx);
    
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
        srand(time(0));
        int id = input.getRandomID();
        int choice = 1 + rand() % 3;
        double amount = 0; 
        
        amount = (double)((rand() % 10000) / 10);

        std::cout << "\n-===-Account " << id << "-===-\n";
        switch (choice)
        {
        case 1: // check balance
            std::cout << "Checking balance: " << input.database[id].getBalance() << std::endl;
            break;
        case 2: // deposit
            input.database[id].deposit(amount);
            std::cout << "Depositing " << amount <<
                         "\nNew balance: " << input.database[id].getBalance() << std::endl;
            break;
        case 3: // withdraw
            input.database[id].withdraw(amount);
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
        threads.emplace_back(client, std::ref(Nordea));
    }
    for (auto &thread : threads)
    {
        thread.join();
    }

    for(int id : Nordea.getAllAccountIds())
    {
        Nordea.database[id].printAccountResults();
    }
}