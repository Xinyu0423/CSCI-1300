////
////  problem1.cpp
////  CSCI-1300
////
////  Created by 蒋新宇 on 2017/9/21.
////  Copyright © 2017年 XInyu JIang. All rights reserved.
////
//
//#include <iostream>
//using namespace std;
//
//void story1(void){
//    cout<<"Enter a plural noun: ";
//    string pluralNoun;
//    cin>> pluralNoun;
//    cout<<"Enter an occupation: ";
//    string occpuation;
//    cin>>occpuation;
//    cout<<"Enter an animal name: ";
//    string animalName;
//    cin>>animalName;
//    cout<<"Enter a place: ";
//    string place;
//    cin>>place;
//    
//    cout<<"In the book War of the "<<pluralNoun<< ", the main character is an anonymous "<<occpuation<< " who records the arrival of the "<<animalName<<" s in "<<place<<"."<<endl<<endl;
//    
//}
//void story2(void){
//    string name;
//    cout<<"Enter a name:"<<endl;
//    cin>>name;
//    string country;
//    cout<<"Enter a state/country:"<<endl;
//    cin>>country;
//    cout<<name<<", I've got a feeling we're not in "<<country<<" anymore."<<endl<<endl;
//    
//}
//void story3(void){
//    string firstName;
//    cout<<"Enter a first name: ";
//    cin>>firstName;
//    string relative;
//    cout<<"Enter a relative: ";
//    cin>>relative;
//    string verb;
//    cout<<"Enter a verb: ";
//    cin>>verb;
//    cout<<"Hello. My name is "<<firstName<<". You killed my "<<relative<<". Prepare to "<<verb<<"."<<endl<<endl;
//}
//void menu(void){
//    string input;
//    cout<<"Which story would you like to play? Enter the number of the story (1, 2, or 3) or type q to quit: "<<endl;
//    cin>>input;
//    if(input=="q"){
//        cout<<"Good bye"<<endl;
//        return;
//    }
//    if(input!="q"){
//        if(input!="1"&&input!="2"&&input!="3"){
//            cout<<"Valid choice not selected."<<endl;
//        }
//        if(input=="1"){
//            story1();
//            menu();
//        
