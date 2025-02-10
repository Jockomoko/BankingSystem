#include <iostream>
#include <thread>
#include <map>
#include "bank.h"
#include <mutex>
#include <chrono>
#include <condition_variable>
// #include "account.h"

using namespace std::literals::chrono_literals;
std::mutex mtx;
std::condition_variable cv;
bool ready = false;
bool processed = false;
std::string data;

void client(Bank &input)
{
    std::unique_lock lk(mtx);
    cv.wait(lk, []{return ready;});
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
        //std::lock_guard<std::mutex> lock(mtx);
        srand(time(0));
        int id = input.getRandomID();
        int choice = 1 + rand() % 3;
        double yeag = 0; 
        
        yeag = (double)((rand() % 10000) / 10);
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
    lk.unlock();
    cv.notify_one();
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
        data = "Example data: ";
        {
            std::lock_guard lk(mtx);
            ready = true;
            std::cout << "\nMain sign ready!\n";
            cv.notify_one();
        }
        {
            std::unique_lock lk(mtx);
            cv.wait(lk, []{return processed;});
        }
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