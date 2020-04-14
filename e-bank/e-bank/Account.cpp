//
//  Account.cpp
//  e-bank
//
//  Created by Wu, Meng Ju on 2020/4/14.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include "Account.hpp"
#include <iostream>
#include <string>
#include <thread>
using namespace std;

Account::Account(int amount, int id, string name):
balance(amount), id(id), name(name)
{
    cout << "===================================" << endl;
    cout << "[Action] Account Created" << endl;
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Balance: " << balance << endl;
}

Account::~Account()
{
    cout << "===================================" << endl;
    cout << "[Action] Account Destroyed" << endl;
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
}

/*
 *  withdraw money from account
 */
bool Account::withdraw(int amount)
{
    using namespace literals::chrono_literals;
    while (isLocked()) {
        this_thread::sleep_for(0.1s);
    }
    
    lock();
    
    bool success = true;
    if (checkBalance(amount)) {
        balance -= amount;
    } else {
        amount = 0;
        success = false;
    }
    
    // log
    cout << "===================================" << endl;
    if (success) {
        cout << "[Action] Account Withdraw (Success)" << endl;
    } else {
        cout << "[Action] Account Withdraw (Failed)" << endl;
    }
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Amount " << amount << endl;
    cout << "Remain: " << balance << endl;
    
    unlock();
    this_thread::sleep_for(0.1s);
    return success;
};

bool Account::isLocked() {
    return locked;
};

/*
 *  check if current balance is able to do the action
 */
bool Account::checkBalance(int amount)
{
    
    if (amount <= balance) {
        return true;
    } else {
        return false;
    }
};

/*
 *  save money into account
 */
void Account::save(int amount)
{
    // save action do not need to lock status
    balance += amount;
    // log
    cout << "===================================" << endl;
    cout << "[Action] Account Saved (Success)" << endl;
    cout << "Name:\t" << name << endl;
    cout << "ID:\t" << id << endl;
    cout << "Amount\t" << amount << endl;
    cout << "Remain:\t" << balance << endl;
};

// lock the check balance action
void Account::lock()
{
    locked = true;
};

// unlock the check balance action
void Account::unlock()
{
    locked = false;
};

