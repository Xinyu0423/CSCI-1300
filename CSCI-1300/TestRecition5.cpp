////
////  TestRecition5.cpp
////  CSCI-1300
////
////  Created by 蒋新宇 on 2017/9/28.
////  Copyright © 2017年 XInyu JIang. All rights reserved.
////
//
//#include <iostream>
//using namespace std;
//string lowerNoPunctuation(string str, string punch) {
//    //Your code here
//    int i=0;
//    while(i<str.length()){
//        if(str[i]>='A'&&str[i]<='Z'){
//            str[i]=tolower(str[i]);
//        }
//        i++;
//    }
//    
//    return str;
//}
//
//int countWord(string sentence, string matchWord)
//{
//    string punctuation = ".,!$*&^%${}:-";
//    //Your code here
//    string newStr=lowerNoPunctuation(sentence,punctuation);
//    int i=0;
//    int count=0;
//    int k=0;
//    while(i<newStr.length()){
//        if(newStr.substr(i,matchWord.length())==matchWord){
//            count++;
//            if(newStr.substr(i,matchWord.length())==newStr.substr(i+matchWord.length(),matchWord.length())){
//                newStr.replace(i, matchWord.length(), " ");
//                count=count-4;
//                }
//
//        }
//        i++;
//    }
//    return count;
//}
//
//void countWords(string str1,string str2){
//    int i=0;
//    int j=0;
//    int k=0;
//    string newStr=lowerNoPunctuation(str1,";");
//    string temp;
//    int count=0;
//    int tempI=0;
//    int tempLength=0;
//    cout<<str2<<" ";
//    string change=lowerNoPunctuation(str2, ";");
//    while(i<newStr.length()){
//        if(newStr[i]==';'){
//            tempLength=i-tempLength+1;
//            temp=newStr.substr(tempI,tempLength);
//            count=countWord(temp, change);
//            //cout<<temp<<endl;
//            cout<<count<<" ";
//            tempI=i;
//        }
//        i++;
//    }
//}
//
////int main(){
////    countWords("Cybersecurity is an emerging field!;;Is isis isiis is si;","Is");
////    return 0;
////}
