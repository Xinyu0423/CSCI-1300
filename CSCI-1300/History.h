//
//  History.hpp
//  CSCI-1300
//
//  Created by 蒋新宇 on 2017/11/8.
//  Copyright © 2017年 XInyu JIang. All rights reserved.
//

#ifndef History_h
#define History_h

#include <stdio.h>
#include "Service.h"
#include <fstream>
#include <iostream>
using namespace std;
class History{
public:
    History();
    ~History();
    string fileName;
    void readHistory(string);
    string getFileName();
    void setFileName(string);
    
};
#endif /* History_hpp */
