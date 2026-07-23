#include "Checking_account.h"




Checking_Account::Checking_Account(std::string name, double amount)
    : Account {name, amount} {
}


bool Checking_Account::withdraw(double amount){
    amount+=1.5;
    return Account::withdraw(amount);
}
std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Checking_account: " << account.name << ": " << account.balance <<" ]";
    return os;
}
