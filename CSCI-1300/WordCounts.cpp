//
//  WordCounts.cpp
//  CSCI-1300
//
//  Created by 蒋新宇 on 2017/11/3.
//  Copyright © 2017年 XInyu JIang. All rights reserved.
//

#include "WordCounts.h"
#include <iostream>
#include <sstream>
using namespace std;
/*
 *Algorithm description
 *constructor
 *intialize variables
 */
WordCounts::WordCounts(){
    wordsIndex=0;
    countIndex=0;
}
//constructor
//intialize variables

/*
 *Algorithm description
 *destructor
 */
WordCounts::~WordCounts(){
}
//destructor

/*
 *Algorithm description
 *  use while loop to get every character of the string
 *  check if it is upper case, if it is change to lower case
 *  check if the front of each words is puncation
 *  if it is remove it
 *  check if the end of each words is a character
 *  if it is remove it
 */
string WordCounts::lowerNoPunctuation(string str, string punch){
    string tempPunch=".,:!?";
    punch=tempPunch;
    int i=0;
    while(i<str.length()){
        if(str[i]>='A'&&str[i]<='Z'){
            str[i]=tolower(str[i]);
        }
        i++;
    }
    //change the string to low case
    stringstream s;
    s<< str;
    string temp;
    string wholeSen="";
    while(getline(s, temp, ' ')){
        //use string stream to get each words
        for(int j=0;j<temp.length();j++){
            for(int k=0;k<punch.length();k++){
                if(temp[0]==punch[k]){
                    temp.erase(0,1);
                    //earse puncation at the front
                }
            }
            for(int l=0;l<=punch.length();l++){
                if(temp[temp.length()-1]==punch[l]){
                    temp.erase(temp.length()-1,1);
                    l=0;
                    //erase the end puncation at the end
                }
            }
        }
        wholeSen=wholeSen+temp+" ";
        //add each word to whole sentence
    }
    return wholeSen;
}
/*Algorithm description
 *use for loop to check every elements in array
 *  if find the same think in array
 *  return the index of the array
 *  if not find it
 *  return -1
 */
int WordCounts::isUnique(string str){
    for(int i=0;i<10000;i++){
        if(str==words[i]){
            //if find it return the index
            return i;
        }
    }
    return -1;
    //if not find it return -1
}
/*
 *Algorithm description
 *  use lowerNoPunctuation function to change everything in low case and remove puncations
 *  if the isUnique returns -1 add it to array and set count to 1
 *  if it is not find the index of the word and add 1 to count
 */
void WordCounts::tallyWords(string sentence){
    sentence=lowerNoPunctuation(sentence, ".,:!?");
    stringstream s;
    s<< sentence;
    string temp;
    while(getline(s, temp , ' ')){
        //use string stream to get each words
        if(isUnique(temp)==-1){
            //if cannot find it in the array
            //add the word to array
            words[wordsIndex]=temp;
            count[wordsIndex]=1;
            wordsIndex++;
            
        }else if(isUnique(temp)!=-1){
            count[isUnique(temp)]=count[isUnique(temp)]+1;
            //if find it in the array
            //use the index that return
            //add 1 to the value of the array
        }
    }
}
/*
 *Algorithm description
 *use for loop to find the word
 *if find it get the index and return the count that have the same index
 */
int WordCounts::getTally(string word){
    for(int i=0;i<sizeof(word);i++){
        if(words[i]==word){
            //check if the word is in the array
            //if it is in the array
            //use the index to find the count
            return count[i];
        }
    }
    return 0;
}
/*
 *Algorithm description
 *use for loop to reset count array to 0
 */
void WordCounts::resetTally(){
    for(int i=0;i<wordsIndex;i++){
        count[i]=0;
        //reset all count to 0
    }
}
/*
 *Algorithm description
 *intialize a bool variable flag
 *use bubble sort to sort the count array
 *the same time sort the word array use the same index
 *add it to word array and count array
 */
int WordCounts::mostTimes(string topWords[],int topCcount[], int n){
    //string tempString;
    bool sorted = false;
    while(!sorted) {
        //while it is not sorted
        //sort the array
        sorted = true;
        for(int idx = 0; idx < wordsIndex-1; idx++) {
            if(count[idx] < count[idx+1]) {
                //check if the front is smaller than the next
                //if it is swap both count and words
                int tempInt = count[idx];
                count[idx]=count[idx+1];
                count[idx+1]=tempInt;
                
                //swap the integer
                string tempString=words[idx];
                words[idx]=words[idx+1];
                words[idx+1]=tempString;
                //swap the word

                
            }
        }
    }

    
    for (int i = 0; i < n && i < wordsIndex; i++) {
        topWords[i] = words[i];
        topCcount[i] = count[i];
        //add word array and count array
    }
    
    if(wordsIndex < n) {
        return wordsIndex;
    }
    //return n;
    
    return wordsIndex;

}
