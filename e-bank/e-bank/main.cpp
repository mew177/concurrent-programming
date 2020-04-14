//
//  main.cpp
//  e-bank
//
//  Created by Wu, Meng Ju on 2020/4/14.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include "Account.hpp"
#include <iostream>
#include <string>
#include <thread>
#include <vector>
using namespace std;

void work(const vector<vector<int>>& works, Account* account) {
    using namespace literals::chrono_literals;
    for (vector<int> work : works) {
        if (work[0] == 1) {
            account->withdraw(work[1]);
        } else {
            account->save(work[1]);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    Account acc1(10000, 12345, "Alen");
    vector<vector<int>> works1 = {
        {1, 1111},
        {1, 6000},
        {2, 1000},
        {1, 3000},
        {1, 2500},
        {1, 4500},
        {2, 500 },
        {2, 1500},
        {1, 3000}
    };
    
    vector<vector<int>> works2 = {
        {1, 2222},
        {1, 4000},
        {2, 1000},
        {1, 500},
        {1, 500},
        {1, 4500},
        {2, 5000},
        {2, 1500},
        {1, 8000}
    };
    
    cout << "===================================" << endl;
    cout << "Pending..." << endl;
    thread worker1(work, works1, &acc1);
    thread worker2(work, works2, &acc1);
    
    worker1.join();
    worker2.join();
    
    cout << endl;
    cout << "Finish!!!" << endl;
    
    return 0;
}
