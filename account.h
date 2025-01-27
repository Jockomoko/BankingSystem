#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef class BankAccount
{
private:
    double balance = 0.0;
    int accountNumber;
    double totalDeposit = 0.0;
    double totalWithdraw = 0.0;

public:
    BankAccount() : accountNumber(0), balance(0.0) {}
    BankAccount(int &input, double balance) : accountNumber(input), balance(balance) {}

    void deposit(double input);

    void withdraw(double input);

    void setTotalDeposit(double deposit);
    void setTotalWithdraw(double withdraw);

    double getBalance();

    void printAccountResults();

    int getNumber();
} BankAccount;

#endif