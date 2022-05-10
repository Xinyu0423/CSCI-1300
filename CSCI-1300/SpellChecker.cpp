//
//  SpellChecker.cpp
//  CSCI-1300
//
//  Created by 蒋新宇 on 2017/10/30.
//  Copyright © 2017年 XInyu JIang. All rights reserved.
//

#include "SpellChecker.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
/*
 *Algorithm description
 *  first constructor
 */
SpellChecker::SpellChecker(){
}
//first constructor

/*
 *Algorithm description
 *  second constructor
 */
SpellChecker::SpellChecker(string str){
    language=str;
}
//second consturctor

/*
 *Algorithm description
 *destructor
 */
SpellChecker::~SpellChecker(){
}
//destructor

/*Algorithm description
 *  third consturctor
 *  intialize variables
 */
SpellChecker::SpellChecker(string str1,string str2,string str3){
    language=str1;
    firstFileName=str2;
    secondFileName=str3;
    readValidWords(str2);
    readCorrectedWords(str3);
}
//third  constructor

/*
 *Algorithm description
 *  use first file name that intialized in .h file
 *  set them equal to each other and open the file
 *  if cannot open it, return false
 *  use get line to get each word
 *  and add it to array
 *  then close the file
 */
bool SpellChecker::readValidWords(string str){
    firstFileName=str;
    int arrIndex=0;
    ifstream inputFile;
    inputFile.open(str);
    if(inputFile.fail()){
        return false;
    }
    //check if the file open correctly
    while(!inputFile.eof()){
        string temp;
        getline(inputFile,temp);
        correctWords[arrIndex]=temp;
        arrIndex++;
        //if it opens correctly
        //use getline to get the word and put it to the correctWords array
    }
    inputFile.close();
    //close the file
    return true;
}
/*Algorithm description
 *  use ifstream to open the file
 *  if the file cannot open return false
 *  use getline to get the whole line
 *  use stringstream to get each word
 *  if it is incorrect add to incorrect part of the 2d array
 *  if it is correct addit to correct part of the 2d array
 *  close the file
 */
bool SpellChecker::readCorrectedWords(string filename){
    bool flag=true;
    secondFileName=filename;
    ifstream inputFile;
    inputFile.open(secondFileName.c_str());
    //open the file
    if(inputFile.fail()){
        flag=false;
        return flag;
    }
    //check if the file opens sucessfully
    
    while(!inputFile.eof()){
        string temp;
        getline(inputFile,temp);
        //get the whole line
        stringstream s;
        s<< temp;
        string temp2;
        getline(s,temp2,'\t');
        //use stringstream to get first words
        if(temp2!=""){
            //check if temp2 is empty
            incorrectWords[index][0]=temp2;
            //add it to the wrong part of 2d array
            getline(s,temp2);
            //get the second word
            incorrectWords[index][1]=temp2;
            //add it to the right part of 2d array
            index++;
        }
    }
    inputFile.close();
    //close the file
    return flag;
}
/*Algorithm description
 *  set star charcater
 *  return true
 */
bool SpellChecker::setStartMarker(char start){
    startChar=start;
    //set the start char
    return true;
}

/*Algorithm description
 *  set end character
 *  return true
 */
bool SpellChecker::setEndMarker(char end){
    endChar=end;
    //set the end char
    return true;
}

/*Algorithm description
 *  get start character
 *  return it
 */

char SpellChecker::getStartMarker(){
    //get the start marker
    return startChar;
}
/*
 *Algorithm description
 *get the end character
 *return it
 */
char SpellChecker::getEndMarker(){
    //get the end marker
    return endChar;
}
/*
 *Algorithm description
 *  use while loop to check every character of the word
 *  if it is upper case change it to lower
 *  use stringstream to get each word
 *  use for loop to check if the front character of the word is a puncation
 *  if it is erase it
 *  use for loop to check if the end charater of the word is a puncation
 *  if it is remove it
 */
string SpellChecker:: lowerNoPunctuation(string str, string punch) {
    string tempPunch=".,:!?";
    punch=tempPunch;
    int i=0;
    while(i<str.length()){
        if(str[i]>='A'&&str[i]<='Z'){
            //check if it is upper case
            //if it is upper case change it to lower case
            str[i]=tolower(str[i]);
        }
        i++;
    }
    stringstream s;
    s<< str;
    string temp;
    string wholeSen="";
    while(getline(s, temp, ' ')){
        //get each word use string stream
        for(int j=0;j<temp.length();j++){
            for(int k=0;k<punch.length();k++){
                if(temp[0]==punch[k]){
                    temp.erase(0,1);
                    //check if the first word is a puncuation
                    //if it is earse it
                }
                    }
            for(int l=0;l<=punch.length();l++){
                if(temp[temp.length()-1]==punch[l]){
                    temp.erase(temp.length()-1,1);
                    l=0;
                    //check if the end word is a puncuation
                    //if it is erase it
                    //keep check it until there is no puncuation
                }
            }
        }
        wholeSen=wholeSen+temp+" ";
        //add it to the whole sentence
    }
    return wholeSen;
}
/*
 *Algorithm description
 *  use for loop to check how many word in sentence
 *  intialize a bool variable set it to false
 *  change it to ture if you find the word in 2d or valid array
 *  if it is in the 2d array find the correct form and add it to sentence
 *  if it is the 1d array add it to sentence
 *  if cannot find it add start character and end character to it
 */
string SpellChecker::repair(string sentence){
    sentence=lowerNoPunctuation(sentence, ".,:!?");
    //use the lowerNoPunctuation to delete puncuations and change to lower case
    string wholeSentence="";
    int countSpace=0;
    for(int i = 0;i < sentence.length() ;i++){
        if(sentence[i] == ' '){
            countSpace++;
        }
    }
    //count how many spaces is there so that count+1 is the word
        for(int j = 0;j < countSpace+1; j++){
            string temp;
            stringstream s;
            bool flag=false;
            s << sentence;
            getline(s, temp, ' ');
            //get each word use stringstream
            sentence.erase(0, sentence.find(' ')+1);
            //erase the front after each time of the loop
        for(int i = 0; i<10000 ;i++){
            if(incorrectWords[i][0] == temp){
                flag=true;
                //change flag=true means you find it
                temp=incorrectWords[i][1];
                //change the word to correct form
                wholeSentence=wholeSentence+temp+" ";
                //add it to whole sentence
                break;
                //out the loop
            }else if(correctWords[i] == temp){
                //if the word is correct
                //add it to whole sentence
                wholeSentence=wholeSentence+temp+" ";
                flag=true;
                break;
            }
            
        }
            if(flag==false){
                wholeSentence=wholeSentence+startChar+temp+endChar+" ";
            }
            //if cannot find it,add start character and end character to it
    }

    return wholeSentence;
    
}

