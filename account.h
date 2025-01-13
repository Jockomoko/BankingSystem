#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef class BankAccount {
    private:
        double balance;
        int accountNumber;

    public:
        BankAccount (int input)
        {
            input = accountNumber;
        };

        int getNumber ();

        void deposit (int input);

        void withdraw (int input);

        double getBalance ();

} BankAccount;

#endif