//
//  Account.hpp
//  e-bank
//
//  Created by Wu, Meng Ju on 2020/4/14.
//  Copyright © 2020 Pitt. All rights reserved.
//

#ifndef Account_hpp
#define Account_hpp

#include <stdio.h>
#include <string>

class Account {
private:
    int balance;
    int id;
    std::string name;
    bool locked = false;
    
public:
    
    Account(int, int, std::string);
    ~Account();
    
    void assign(int, int); // assign action
    bool withdraw(int); // withdraw money from account
    bool checkBalance(int); // check if current balance is able to do the action
    void save(int); // save money into account
    void lock(); // lock the check balance action
    void unlock(); // unlock the check balance action
    bool isLocked(); // check whether the lock is on or not
};

#endif /* Account_hpp */
