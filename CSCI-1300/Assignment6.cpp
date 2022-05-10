//Author: Xinyu Jiang
//Recitation: CSCI1300-210 TA:Xiaozhe Zhang
//
//Assignment 6
//


#include <iostream>
#include <fstream>
/**
 *Algorithm description
 *   initialize 3 variable line count and sum
 *   while opens the file fail, return -1
 *   else, use count to count how many character in the line and sum it together
 *   divide to get the average
 */
using namespace std;
float avgCharsPerLine(string fileName){
    ifstream inputFile(fileName);
    
    int line=0;
    int count=0;
    int sum=0;
    if(inputFile.fail()){
        
        return -1.0;
    }else{
        while(!inputFile.eof()){
            string temp;
            getline(inputFile,temp);
            //get the line
            count=temp.length();
            //get how many characters
            sum=sum+count;
            //sum the character
            line++;
        }
    }
    float avg=(sum*1.0)/line;
    //*1.0 to cast from int to float
    inputFile.close();
    return avg;
    
}
/**
 *Algorithm description
 *   initialize two variable line and row
 *   if the file cannot open, return -1
 *   else skip the first line, initialize a variable temp to store the line
 *   fill the array with numbers seperate by ','
 *   return line-1
 */
int  fillArray(string fileName, float arr[][5]){
    ifstream inputFile(fileName);
    int line=0;
    int row=0;
    if(inputFile.fail()){
        return -1;
    }
    else{
        while(!inputFile.eof()){
            string temp;
            getline(inputFile,temp);
            if(line!=0){
                //skip the first line
                arr[row][0]=stof(temp.substr(0,temp.find(',')));
                temp.erase(0,temp.find(',')+1);
                //substring and erase it and save it to array
                arr[row][1]=stof(temp.substr(0,temp.find(',')));
                temp.erase(0,temp.find(',')+1);
                arr[row][2]=stof(temp.substr(0,temp.find(',')));
                temp.erase(0,temp.find(',')+1);
                arr[row][3]=stof(temp.substr(0,temp.find(',')));
                temp.erase(0,temp.find(',')+1);
                arr[row][4]=stof(temp.substr(0,temp.length()));
                row++;
            }
            line++;
        }
    }
    inputFile.close();
    return line-1;
}
/**
 *Algorithm description
 *   if the file cannot open return -1
 *   else, skip the first line and put every thing into the array
 *   get the row first and get the the first column and get the second column
 *   then add it together.
 */
float  arrayStats(string fileName, float arr[][5]){
    ifstream inputFile(fileName);
    int row=0;
    int line=0;
    double sum=0.0;
    double avg= 0.0;
    if(inputFile.fail()){
        return -1;
    }
    while(!inputFile.eof()){
        string temp;
        getline(inputFile,temp);
        if(line!=0){
            arr[line][0]=stof(temp.substr(0,temp.find(',')));
            temp.erase(0,temp.find(',')+1);
            arr[line][1]=stof(temp.substr(0,temp.find(',')));
            temp.erase(0,temp.find(',')+1);
            arr[line][2]=stof(temp.substr(0,temp.find(',')));
            temp.erase(0,temp.find(',')+1);
            arr[line][3]=stof(temp.substr(0,temp.find(',')));
            temp.erase(0,temp.find(',')+1);
            arr[line][4]=stof(temp.substr(0,temp.length()));
            if(line%2==0){
                sum=arr[line][0]+arr[line][1]+arr[line][2]+arr[line][3]+arr[line][4];
                //get the row
                avg=avg+sum/5;
            }
        }
        line++;
    }
    int i= 1;
    float sumCol=0.0;
    float avgCol=0.0;
    while(i<line){
        sumCol=arr[i][1]+sumCol;
        i++;
    }
    avgCol=sumCol/(line-1);
    //get the average of first column
    int j=1;
    float secondColSum=0.0;
    float secondColAvg=0.0;
    while(j<line){
        secondColSum=arr[j][3]+secondColSum;
        j++;
    }
    secondColAvg=secondColSum/(line-1);
    //get the average of first column
    float totalAvg=0.0;
    totalAvg=avg+avgCol+secondColAvg;
    //add together
    inputFile.close();
    return totalAvg;
}
/*void addBookRatings(string fileName, string arr[], int arr2[][50]){
 ifstream inputFile(fileName);
 int line=0;
 int j=0;
 int arrIndex=0;
 while(!inputFile.eof()){
 string temp;
 int id;
 int rate;
 string name;
 getline(inputFile,temp);
 if(line!=0){
 name=temp.substr(0,temp.find(','));
 temp.erase(0,temp.find(',')+1);
 //arr[j]=name;
 id=stoi(temp.substr(0,temp.find(',')));
 temp.erase(0,temp.find(',')+1);
 rate=stoi(temp.substr(0,temp.length()));
 for(int i=0;i<100;i++){
 if(arr[j].empty()){
 if(name==arr[j]){
 break;
 }else{
 arr[j]=name;
 cout<<arr[j]<<endl;
 break;
 }
 }
 j++;
 }
 line++;
 }
 }
 }
 */
/*int main(){
    float avg=avgCharsPerLine("problem1.txt");
    cout<<avg<<endl;
    
    float problem2[5][5];
    int line=fillArray("problem2.txt", problem2);
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            cout<<"array"<<"["<<i<<"]"<<"["<<j<<"]="<<problem2[i][j]<<endl;
        }
    }
    float problem3Arr[5][5];
    float problem3=arrayStats("problem3.txt", problem3Arr);
    cout<<"problem3 result: "<<problem3<<endl;
    //string name[20];
    //int bookName[20][50];
    //addBookRatings("problem4.txt",name,bookName);
    
    
}*/
