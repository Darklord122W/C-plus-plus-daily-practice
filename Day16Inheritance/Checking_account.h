#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include "Account.h"
#include "Checking_account.h"

class Checking_Account: public Account {
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);
protected:
private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
public:
    Checking_Account(std::string name=def_name,double amount=def_balance);    
    bool withdraw(double amount);
    // Inherits the Account::withdraw methods
};











#endif