//
//  History.cpp
//  CSCI-1300
//
//  Created by 蒋新宇 on 2017/11/8.
//  Copyright © 2017年 XInyu JIang. All rights reserved.
//

#include "Service.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
/*
 *Algorithm description
 *  constructor
 *  intialize the fileName
 */
History::History(){
    fileName="history.txt";
}

/*
 *Algorithm description
 *  destructor
 */
History::~History(){
    
}
/*
 *Algorithm description
 *  use ifstream to read the history file 
 *  and print out the history
 */
void History::readHistory(string x){
    x=fileName;
    ifstream inputFile(x);
    string temp;
    //use ifstream to read the file
    while(!inputFile.eof()){
        getline(inputFile,temp);
        cout<<temp<<endl;
        //print out the history
    }
}
/*
 *Algorithm description
 *  getter that get the file name
 */
string History::getFileName(){
    return fileName;
    //return the file name
}
/*
 *Algorithm description
 *  setter that set the file name
 */
void History::setFileName(string x){
    fileName=x;
    //set the file name
}
/*
 *Algorithm description
 *  use for loop to get the total amout of
 *  deposit and return the total
 */
int Service::getTotalDepositing(){
    int totalDeposit=0;
    for(int i=0;i<depositIndex;i++){
        totalDeposit=totalDeposit+depositArr[i];
        //get each deposit and add it together
    }
    return totalDeposit;
    
}
/*
 *Algorithm description
 *  use for loop to get the total amout of
 *  withdrawal and return the total
 */
int Service::getTotalWithdrawal(){
    int totalWithdrawal=0;
    for(int i=0;i<withdrawalIndex;i++){
        totalWithdrawal=totalWithdrawal+withdrawalArr[i];
        //get each withdrawal and add it together
    }
    return totalWithdrawal;
}
/*
 *Algorithm description
 *  use for loop to get the total amout of
 *  transfer and return the total
 */
int Service::getTotalTransfer(){
    int totalTransfer=0;
    for(int i=0;i<transferIndex;i++){
        totalTransfer=totalTransfer+transferArr[i];
        //get each transfer and add it together
    }
    return totalTransfer;
}
