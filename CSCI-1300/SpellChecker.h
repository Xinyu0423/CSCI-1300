//
//  SpellChecker.hpp
//  CSCI-1300
//
//  Created by 蒋新宇 on 2017/10/30.
//  Copyright © 2017年 XInyu JIang. All rights reserved.
//

#ifndef SpellChecker_h
#define SpellChecker_h
#include <iostream>
#include <stdio.h>
using namespace std;
class SpellChecker{
public:
    string language;
    
    SpellChecker();
    //first constructor
    ~SpellChecker();
    //destructor
    SpellChecker(string);
    //second constructor
    SpellChecker(string, string, string);
    //third constructor;
    bool readValidWords(string filename);
    bool readCorrectedWords(string filename);
    bool setStartMarker(char begin);
    bool setEndMarker(char end);
    char getStartMarker();
    char getEndMarker();
    string lowerNoPunctuation(string,string);
    string repair(string sentence);
    string firstFileName;
    string secondFileName;
    string correctWords[10000];
    string incorrectWords[10000][2];
    int index=0;
    
private:
    char startChar;
    char endChar;

};

#endif /* SpellChecker_hpp */
