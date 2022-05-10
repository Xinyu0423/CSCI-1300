//
//  Saving.cpp
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
 *  initialize variables
 *  intialize all the deposit array withdrawal array and transfer array to 0
 *  and all the index to 0
 *  set the file name to history.txt
 */
Service::Service(){
    for(int i=0;i<100;i++){
        depositArr[i]=0;
        withdrawalArr[i]=0;
        transferArr[i]=0;
        //intialize all elements of array to zero.
    }
    depositIndex=0;
    withdrawalIndex=0;
    transferIndex=0;
    totalMoney=0;
    fileName="history.txt";
    //intialize all variables
}

/*
 *Algorithm description
 *  destructor
 */
Service::~Service(){

}
/*
 *Algorithm description
 *  use cout to introduce the program
 */
void Service::mainPageIntroduction(){
    cout<<"Welcome to to the banking account system"<<endl;
    cout<<"You can check the balance of your account"<<endl;
    cout<<"You can save money to your account"<<endl;
    cout<<"You can deposit money from your bank account"<<endl;
    cout<<"You can transfer money to someone"<<endl;
    //use cout to print out information of the program
}
/*
 *Algorithm description
 *  ask the user what he/she want to do
 *  if the user enter an invalid thing
 *  use recursion to go back and restart again
 *  if the user type in -1, it will end the function(base)
 */
string Service::chooseService(){
    cout<<"Please enter service you want"<<endl;
    cout<<"Please enter 1 if you want to save money"<<endl;
    cout<<"Please enter 2 if you want to withdrawal money"<<endl;
    cout<<"Please enter 3 if you want to transfer money to other people"<<endl;
    cout<<"Please enter 4 if you want to check how much money in other currency"<<endl;
    cout<<"Please enter -1 if you want to quit"<<endl;
    cin>>choose;
    //ask the user for input
    if(choose=="-1"){
        cout<<"Thank you, you are now exit to the system"<<endl;
        return choose;
        //base of recursion
    }
    if(choose[0]>'4'||choose.length()!=1){
        cout<<"You enter a invalid number, please enter again"<<endl;
        chooseService();
        //check if enter valid input, if not use recursion to go back
        return choose;
    }
    
    while (choose!="-1") {
        if(choose=="1"){
            deposit(fileName);
            break;
            //if if the user enter 1, call deposit function
            //use break to go out the while loop
        }else if(choose=="2"){
            withdrawal(fileName);
            break;
            //if if the user enter 1, call withdrawal function
            //use break to go out the while loop
        }else if(choose=="3"){
            transfer(fileName);
            break;
            //if if the user enter 1, call transfer function
            //use break to go out the while loop
        }else if(choose=="4"){
            exchangeRate(totalMoney);
            break;
            //if if the user enter 1, call exchange rate function
            //use break to go out the while loop
        }
        
    }

    return choose;
    //return the user's choose
}
/*
 *Algorithm description
 *  This is to a function that use after the 
 *  deposit, withdrawal, transfer, exchange rate function
 *  It will ask the user if he want more service
 *  if the user enter invalid input, it will use
 *  recursion to restart the function
 *  if the user enter 2, the function will end(base)
 */
void Service::anotherService(){
    cout<<"Do you want to do another service?"<<endl;
    cout<<"Please enter 1 if you want to keep using this banking system"<<endl;
    cout<<"Or enter 2 to quit"<<endl;
    string temp;
    cin>>temp;
    if(temp[0]>'2'||temp.length()!=1){
        cout<<"You need to enter a invalid input, please try again"<<endl;
        cout<<"---------------(restarting)-------------"<<endl;
        anotherService();
        //recursion
        //check if user enter valid input
    }
    if(temp=="2"){
        cout<<"You have exited the bank system"<<endl;
        return;
        //base case
    }
    if(temp=="1"){
        chooseService();
        return;
    }

}
/*
 *Algorithm description
 *  This is the function for user to deposit money
 *  It will ask the user to enter a hundred-based amount money
 *  if the user enter an invalid amount of money, it will
 *  use recursion to restart the function
 *  after user enter valid amount of money, it will show 
 *  the money is successfully deposited and write the history in the txt file
 *  then it will ask the user if he/she want to deposit more money
 *  it will check user's input until the user enter valid input
 *  if the user choose to deposit more money, the function will be called again (recursion)
 *  or if the user want to quit the deposit system, it will call anotherService function
 *  and the function will return the total money in your bank account.
 */
int Service::deposit(string x){
    x=fileName;
    string anotherTemp;
    cout<<"You are now in the deposit system"<<endl;
    cout<<"Please enter hundred-based money you want to save"<<endl;
    cout<<"For example, 1100 or 300"<<endl;
    string temp;
    cin>>temp;
    if(temp[0]>'9'||stoi(temp)%100!=0){
        cout<<"You enter a invalid number, please try again"<<endl;
        cout<<"--------------------(restarting)----------------"<<endl;
        deposit(x);
        //check if input if hundred-base
        //if not use recursion to go back to the function
    }
    if(stoi(temp)%100==0){
        cout<<"You are now deposited "<<temp<<" amount money to your bank account"<<endl;
        depositArr[depositIndex]=stoi(temp);
        depositIndex++;
        //save it to deposit array
        ofstream outputFile(x,ios::app);
        outputFile<<"You deposited "<<temp<<" amount money to your bank account\n";
        outputFile.close();
        //save it to the txt file, and close the file
        //because the function use recursion, it has to close the file
        //to make it in right order

        totalMoney=totalMoney+stoi(temp);
        //add the save to total money.
        cout<<"Do you want deposit more money?"<<endl;
        cout<<"Please enter 1 if you want to deposit more money"<<endl;
        cout<<"Or enter 2 to quit the deposit system"<<endl;
        cin>>anotherTemp;
        //ask if user want save more money
        if(anotherTemp[0]>'2'||anotherTemp.length()!=1){
            cout<<"You need to enter a invalid input, go back to the saving system"<<endl;
            cout<<"---------------(restarting)-------------"<<endl;
            deposit(x);
            //check if the input valid
        }
        if(anotherTemp=="1"){
            cout<<"-------------You are doing another saving.------------"<<endl;
            deposit(x);
            //another saving
        }
        if(anotherTemp=="2"){
            cout<<"You have exited the saving system"<<endl;
            cout<<"-----------------------------------"<<endl;
            anotherService();
            return totalMoney;
            //exit the saving function and call another service function
        }
    }
    return totalMoney;
    //return total amount of money
}
/*
 *Algorithm description
 *  This is the function for user to withdrawal money
 *  It will ask the user to enter a hundred-based amount money user want to withdrawal
 *  if the user enter an invalid amount of money, it will
 *  use recursion to restart the function
 *  after user enter valid amount of money, it will check if user's
 *  account have enough moeny to withdrawal, if not it will show
 *  the user do not have enough money, and call anotherService function
 *  if the user have enough money,
 *  the money is successfully withdrawal and write the history in the txt file
 *  then it will ask the user if he/she want to withdrawal more money
 *  it will check user's input until the user enter valid input
 *  if the user choose to withdrawal more money, the function will be called again (recursion)
 *  or if the user want to quit the withdrawal system, it will call anotherService function
 *  and the function will return the total money in your bank account.
 */
int Service::withdrawal(string x){
    x=fileName;
    string temp;
    string anotherTemp;
    cout<<"You are now in the withdrawal money from you account"<<endl;
    cout<<"Please enter how much money you want to withdrawal"<<endl;
    cout<<"Please enter hundred-based amount money"<<endl;
    cin>>temp;
    if(temp[0]>'9'||stoi(temp)%100!=0){
        cout<<"You enter a invalid number, please try again"<<endl;
        cout<<"------------------------(restarting)--------------------------"<<endl;
        withdrawal(x);
        //check if input if hundred-base
        //if not use recursion to go back to the function

    }
    if(stoi(temp)%100==0){
        if(stoi(temp)>totalMoney){
            cout<<"Sorry, you don't have enough money to withdrawal"<<endl;
            cout<<"Please save more money to withdrawal"<<endl;
            anotherService();
            return totalMoney;
            //check if the user have enough money to withdrawal
            //if not, end the function and call another service function
        }
        cout<<"You have withdrawaled "<<temp<<" amount money from your bank account"<<endl;
        withdrawalArr[withdrawalIndex]=stoi(temp);
        withdrawalIndex++;
        //add it to the array
        ofstream outputFile(x,ios::app);
        outputFile<<"You withdrawaled "<<temp<<" amount money from your bank account\n";
        outputFile.close();
        totalMoney=totalMoney-stoi(temp);
        //renew the total amount of money
        cout<<"Do you want withdrawal more money?"<<endl;
        cout<<"Please enter 1 if you want to withdrawal more money"<<endl;
        cout<<"Or enter 2 to quit the withdrawal system"<<endl;
        cin>>anotherTemp;
        if(anotherTemp[0]>'2'||anotherTemp.length()!=1){
            cout<<"You need to enter a invalid input, go back to the withdrawal system"<<endl;
            cout<<"---------------(restarting)-------------"<<endl;
            withdrawal(x);
            //check if the input valid
        }
        if(anotherTemp=="1"){
            cout<<"-------------You are doing another withdrawaling.------------"<<endl;
            withdrawal(x);
            //recursion
        }
        if(anotherTemp=="2"){
            cout<<"You have exited the withdrawal system"<<endl;
            cout<<"-----------------------------------"<<endl;
            anotherService();
            return totalMoney;
            //exit the withdrawal function and call anotherService
        }
    }
    return totalMoney;
    //return the total amount of money in bank account
}
/*
 *Algorithm description
 *  This is the function for user to transfer money
 *  it will ask the name that user want to transfer to
 *  It will ask the user to enter a hundred-based amount money to transfer
 *  if the user enter an invalid amount of money, it will
 *  use recursion to restart the function (recursion)
 *  after user enter valid amount of money, it will check if user's
 *  account have enough moeny to transfer, if not it will show
 *  the user do not have enough money, and call anotherService function
 *  if the user have enough money,
 *  the money is successfully transfer and write the history in the txt file
 *  then it will ask the user if he/she want to transfer more money
 *  it will check user's input until the user enter valid input
 *  if the user choose to transfer more money, the function will be called again (recursion)
 *  or if the user want to quit the transfer system, it will call anotherService function
 *  and the function will return the total money in your bank account.
 */
int Service::transfer(string x){
    x=fileName;
    string temp;
    string anotherTemp;
    string name;
    cout<<"You are now in the transer system"<<endl;
    cout<<"Please enter the name you want to tansfer to"<<endl;
    cin>>name;
    cout<<"Please enter the amount money tou want to transfer in hundred-base"<<endl;
    cout<<"For example, you can enter 100 or 1300"<<endl;
    cin>>temp;
    //ask user the name and amount money he/she want to transfer
    if(temp[0]>'9'||stoi(temp)%100!=0){
        cout<<"You enter a invalid number, please try again"<<endl;
        cout<<"----------------------(restarting)-----------------------------"<<endl;
        deposit(x);
        //check if the input valid
    }
    if(stoi(temp)%100==0){
        if(stoi(temp)>totalMoney){
            cout<<"Sorry, you don't have enough money to transfer"<<endl;
            cout<<"Please save more money to transfer"<<endl;
            return totalMoney;
            //check if the user have enough money to transfer
        }
        cout<<"You have transfered "<<temp<<" amount money to "<<name<<"."<<endl;
        transferArr[transferIndex]=stoi(temp);
        transferIndex++;
        //save it to the array
        ofstream outputFile(x,ios::app);
        outputFile<<"You transfered "<<temp<<" amount money to "<<name<<".\n";
        outputFile.close();
        //write it to the file
        totalMoney=totalMoney-stoi(temp);
        //renew the total amount of money
        cout<<"Do you want transfer more money?"<<endl;
        cout<<"Please enter 1 if you want to transfer more money"<<endl;
        cout<<"Or enter 2 to quit the transfing system"<<endl;
        cin>>anotherTemp;
        if(anotherTemp[0]>'2'||anotherTemp.length()!=1){
            cout<<"You need to enter a invalid input, go back to the "<<endl;
            cout<<"---------------(restarting)-------------"<<endl;
            transfer(x);
        }
        if(anotherTemp=="1"){
            cout<<"-------------You are doing another transfering.------------"<<endl;
            transfer(x);
        }
        if(anotherTemp=="2"){
            cout<<"You have exited the transfer system"<<endl;
            cout<<"-----------------------------------"<<endl;
            anotherService();
            //exit the function, and call another service
            return totalMoney;
        }
    }

    return totalMoney;
    //return the total amount of money
}
/*
 *Algorithm description
 *  print out the total amount money in the bank account
 */
void Service::accountInfo(){
    cout<<"The total money in your account is "<<totalMoney<<endl;
    //print how much money in your bank account
}
/*
 *Algorithm description
 *  This function will use the total amount money in your bank account
 *  and get the exchange rate from a txt file
 *  it will use stringstream to get the name and exchange rate
 *  and mutiply by the totoal amount of bank account
 *  to get the money in different country
 *  then it will call another service function.
 */
void Service::exchangeRate(int x){
    x=totalMoney;
    ifstream inputFile("exChangeRate.txt");
    //open the exchangeRate.txt file
    string temp;
    string country;
    string rate;
    while(getline(inputFile,temp)){
        //get each line
        stringstream s;
        s<<temp;
        getline(s, country, ',');
        getline(s, rate, ',');
        //use stringstream to seperate the country and money
        float tempTotal=totalMoney*stof(rate);
        //get the amount of money in that country's exchange rate
        cout<< "The US money to "<<country<<" money is "<<tempTotal<<endl;
    }
    cout<<"--------------------------------------------------------"<<endl;
    anotherService();
    return;
    //call another service function and end this function
}
/*
 *Algorithm description
 *  This function will return total amount money in your bank account
 */
int Service::getTotalMoney(){
    return totalMoney;
    //get the amount of money in bank account
}
