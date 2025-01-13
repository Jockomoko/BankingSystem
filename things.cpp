#include <iostream>
#include <map>
#if !defined(THINGS_H)
#define THINGS_H

typedef class BankAccount {
    private:
        double balance;
        int accountNumber;

    public:
        BankAccount (int input)
        {
            input = accountNumber;
        };

        int getNumber ()
        {
            return accountNumber;
        };

        void deposit (int input);

        void withdraw (int input);

        int getBalance ();

} BankAccount;

typedef class Bank {
    private:
        std::map<int, BankAccount> database;
    
    public: 
        void addAccount();

        void showAccountDetails();
        
} Bank;


#endif // THINGS_H