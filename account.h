#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef class BankAccount
{
private:
    double balance = 0.0;
    int accountNumber;

public:
    BankAccount() : accountNumber(0), balance(0.0) {}
    BankAccount(int &input, double balance) : accountNumber(input), balance(balance) {}
    int getNumber();

    void deposit(int input);

    void withdraw(int input);

    double getBalance();

} BankAccount;

#endif