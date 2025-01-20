#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef class BankAccount
{
private:
    double balance = 0.0;
    int accountNumber;

public:
    BankAccount() : accountNumber(0) {}
    BankAccount(int &input) : accountNumber(input) {}
    int getNumber();

    void deposit(int input);

    void withdraw(int input);

    double getBalance();

} BankAccount;

#endif