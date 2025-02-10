#ifndef ACCOUNT_H
#define ACCOUNT_H

class BankAccount
{
private:
    double balance = 0.0;
    int accountNumber;
    double totalDeposit = 0.0;
    double totalWithdraw = 0.0;

public:
    BankAccount() : accountNumber(0), balance(5000.0) {}
    BankAccount(int input, double balance) : accountNumber(input), balance(balance) {}

    void deposit(double input);

    void withdraw(double input);

    void addTotalDeposit(double deposit);
    void addTotalWithdraw(double withdraw);

    double getBalance();

    void printAccountResults();

    int getNumber();
};

#endif