//
//  TestReicition7.cpp
//  CSCI-1300
//
//  Created by 蒋新宇 on 2017/10/11.
//  Copyright © 2017年 XInyu JIang. All rights reserved.
//

#include <iostream>
using namespace std;
int Chop(string str, string arr[], int size){
    int arrIndex=-1;
    int count=1;
    string tempStr=str;
    int loopIndex=0;
    for(int i=0;i<tempStr.length();i++){
        loopIndex++;
        if(tempStr[loopIndex]==' '){
            arrIndex=arrIndex+1;
            arr[arrIndex]=tempStr.substr(0,loopIndex);
            //cout<<"substring "<<arr[arrIndex]<<endl;
            tempStr.erase(0,loopIndex+1);
            count++;
            loopIndex=0;
        }
        
    }
    //cout<<"left string:"<<tempStr;
    arr[arrIndex+1]=tempStr;
    //if(arr[arrIndex+2]==""){
    //  delete arr[arrIndex+2];
    //  }
    
    if(str==""){
        return 0;
    }
    return count;
}
//int main(){
//    string testcase = "ABCD EFG";
//    string my_array[]={};
//    int tc4 = Chop(testcase, my_array, sizeof(my_array)/sizeof(string));
//    for (int i=0 ; i < 10 && i < tc4 ; i++)
//        cout << my_array[i] << endl;
//    cout << "Function returned value: " << tc4 << endl;
//}
