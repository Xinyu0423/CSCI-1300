//
//  BankingMain.cpp
//  CSCI-1300
//
//  Created by 蒋新宇 on 2017/11/15.
//  Copyright © 2017年 XInyu JIang. All rights reserved.
//

#include <iostream>
#include "Service.h"
#include "History.h"
using namespace std;
int main(){
    Service testService;
    testService.chooseService();
    testService.accountInfo();
    cout<<"-------------------History---------------------"<<endl;
    History testHistory;
    testHistory.readHistory(testHistory.getFileName());
    cout<<"The total amout of money you deposit is "<<testService.getTotalDepositing()<<endl;
    cout<<"The total amount of money you withdrawal is "<<testService.getTotalWithdrawal()<<endl;
    cout<<"The total amount of money you transfer is "<<testService.getTotalTransfer()<<endl;
    
}
