//
//  Saving.hpp
//  CSCI-1300
//
//  Created by 蒋新宇 on 2017/11/8.
//  Copyright © 2017年 XInyu JIang. All rights reserved.
//

#ifndef Service_h
#define Service_h

#include <stdio.h>
#include <iostream>
#include "History.h"
using namespace std;
class Service{
public:
    Service();
    ~Service();
    void mainPageIntroduction();
    string chooseService();
    void accountInfo();
    int deposit(string);
    int withdrawal(string);
    int transfer(string);
    void anotherService();
    int getTotalDepositing();
    int getTotalWithdrawal();
    int getTotalTransfer();
    void exchangeRate(int);
    int getTotalMoney();
    string fileName;
    int totalMoney;
    string choose;
    int depositArr[100];
    int withdrawalArr[100];
    int transferArr[100];
    int depositIndex;
    int withdrawalIndex;
    int transferIndex;
    
    
};

#endif /* Saving_ */
