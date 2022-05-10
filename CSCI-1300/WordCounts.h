//
//  WordCounts.hpp
//  CSCI-1300
//
//  Created by 蒋新宇 on 2017/11/3.
//  Copyright © 2017年 XInyu JIang. All rights reserved.
//

#ifndef WordCounts_h
#define WordCounts_h
#include <stdio.h>
#include <iostream>
using namespace std;
class WordCounts{
public:
    WordCounts();
    ~WordCounts();
    void tallyWords(string);
    int getTally (string);
    void resetTally();
    int mostTimes(string[], int[], int);
    string lowerNoPunctuation(string,string);
    string words[10000];
    int isUnique(string);
    int wordsIndex;
    int count[10000];
    int countIndex;
    
};

    


#endif /* WordCounts_hpp */
