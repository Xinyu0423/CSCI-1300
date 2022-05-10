
//  problemTemp.cpp
//  CSCI-1300

//  Created by 蒋新宇 on 2017/9/21.
//  Copyright © 2017年 XInyu JIang. All rights reserved.


#include <iostream>
using namespace std;

string input;
void menu(void){
    cout<<"Which story would you like to play? Enter the number of thestory (1, 2, or 3) or type q to quit: "<<endl;
    cin>>input;
    while(input!="q"){
        if(input!="1"||input!="2"||input!="3"){
            cout<<"Valid choice not selected."<<endl;
            menu();
        }
    }
}
void story1(void){
    if(input=="1"){
        cout<<"Enter a plural noun: ";
        string pluralNoun;
        cin>> pluralNoun;
        cout<<"Enter an occupation: ";
        string occpuation;
        cin>>occpuation;
        cout<<"Enter an animal name: ";
        string animalName;
        cin>>animalName;
        cout<<"Enter a place: ";
        string place;
        cin>>place;
        
        cout<<"In the book War of the "<<pluralNoun<< " , the main character is an anonymous"<<occpuation<< " who records the arrival of the "<<animalName<<" s in "<<place<<" .";
    }
    
}
int main(){
    story1();
}
