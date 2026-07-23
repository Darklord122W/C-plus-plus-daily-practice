#include "Trust_account.h"
#include "Savings_Account.h"
Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account {name, balance,int_rate} {
}

// Deposit:
//      Amount supplied to deposit will be incremented by (amount * int_rate/100) 
//      and then the updated amount will be deposited
//
bool Trust_Account::deposit(double amount) {
    if(amount>=5000.0)
        amount+=50.0;
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount){
    if((withdraw_time<3)&&(amount<balance*0.2)){
        withdraw_time++;
        return Account::withdraw(amount);

    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}

