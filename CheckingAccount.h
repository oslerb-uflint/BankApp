//
// Created by osler on 10/27/2026.
//

#ifndef BANKAPP_CHECKINGACCOUNT_H
#define BANKAPP_CHECKINGACCOUNT_H
#include "BankAccount.h"
#include <string>
#include <iostream>
using namespace std;


class CheckingAccount: public BankAccount {
    private:
        double m_overdraftLimit;

    public:
        CheckingAccount(const string &accHolder, const string &accNum, double balance, double overdraftLimit):BankAccount(accHolder,accNum, balance) {
            m_overdraftLimit = overdraftLimit;
        };
        ~CheckingAccount() {
            cout<<"Checking Account Destroyed"<<endl;
        };

        bool withdraw(double amount) {
            if (amount <= m_balance + m_overdraftLimit) {
                if (amount>m_balance) {
                    m_overdraftLimit += (m_balance-amount);
                }
                m_balance -= amount;

                return true;
            }
            if (amount <= m_overdraftLimit && m_balance <0) {
                m_overdraftLimit -= amount;
                m_balance -= amount;
                return true;
            }
            return false;
        };

        void display() {
            BankAccount::display();
            std::cout << "Overdraft Limit: $" << m_overdraftLimit << std::endl;
        }

};


#endif //BANKAPP_CHECKINGACCOUNT_H
