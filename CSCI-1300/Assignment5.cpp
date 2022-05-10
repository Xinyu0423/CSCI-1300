//
//  Assignment5.cpp
//  CSCI-1300
//
//  Created by 蒋新宇 on 2017/10/5.
//  Copyright © 2017年 XInyu JIang. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

float sumArray(float arr[], int size){
    float sum=0.0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    return sum;
}
int search(int arr[],int size,int target){
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}
float calculateDifference(int arr1[],int arr2[],int size){
    float sum=0.0;
    for(int i=0;i<size;i++){
        if(arr1[i]!=arr2[i]){
            sum+=pow(1.0*(arr1[i]-arr2[i]), 2);
        }
    }
    return sum;
}
void sortArray(float arr[],int size){
    float temp=0.0;
    int index;
    for(int i=0;i<size;i++){
        index=i;
        for(int j=0;j<size;j++){
            if(arr[index]<arr[j]){
                index=j;
                float swapTemp;
                swapTemp=arr[i];
                arr[i]=arr[index];
                arr[index]=swapTemp;
            }
        }
        
    }
    //    for(int i=0;i<size;i++){
    //        cout<<"sort: "<<arr[i]<<endl;
    //    }
}
void copyArray(float arr1[],int size,float arr2[]){
    for(int i=0;i<size;i++){
        float temp=arr1[i];
        arr2[i]=temp;
    }
}
void convert(int arr1[],string arr2[],int size){
    string str0="Haven’t read it";
    string str1="Hated it";
    string str2="Didn’t like it";
    string str3="Ok. neither hot nor cold about it";
    string str4="Liked it!";
    string str5="Really liked it!";
    for(int i=0;i<size;i++){
        if(arr1[i]==0){
            arr2[i]=str0;
        }else if(arr1[i]==-5){
            arr2[i]=str1;
        }else if(arr1[i]==-3){
            arr2[i]=str2;
        }else if(arr1[i]==1){
            arr2[i]=str3;
        }else if(arr1[i]==3){
            arr2[i]=str4;
        }
        if(arr1[i]==5){
            arr2[i]=str5;
        }
    }
    //    for(int i=0;i<size;i++){
    //        cout<<arr2[i]<<endl;
    //    }
}
float findMedian(float arr[],int size){
    //    int countBigger=0;
    //    int countSmaller=0;
    //    for(int i=0;i<size;i++){
    //        for(int j=0;j<size;j++){
    //            if(arr[i]<arr[j]){
    //                countSmaller++;
    //            }
    //            if(arr[i]>arr[j]){
    //                countBigger++;
    //            }
    //            if(countBigger==countSmaller){
    //                return arr[i];
    //            }
    //        }
    //    }
    float tempArray[size];
    for(int i=0;i<size;i++){
        float temp=arr[i];
        tempArray[i]=temp;
    }
    //    for(int i=0;i<size;i++){
    //        cout<<"Unsorted "<<tempArray[i]<<endl;
    //    }
    sortArray(tempArray, size);
    //    for(int i=0;i<size;i++){
    //        cout<<"sorted: "<<tempArray[i]<<endl;
    //    }
    if(size%2==1){
        return tempArray[(size/2)];
    }else{
        float median=((tempArray[(size/2)-1]+tempArray[size/2]))/2;
        //cout<<"median"<<median<<endl;
        return median;
    }
}
//int main(){
//    float a[]={1.1,1.2,1.3};
//    cout<<sumArray(a, 3)<<endl;
//    int b[]={3,4,5,6,7,8};
//    cout<<search(b,6,7)<<endl;
//    int c[]={1,2,3,4,5};
//    int d[]={1,2,3,8,10};
//    cout<<calculateDifference(c,d,5)<<endl;
//    float e[]={6.1,8.2,3.3,5.4,4.5};
//    sortArray(e, 5);
//    float f[]={1.1,1.2,1.3,1.4,1.5};
//    float g[]={0.9,0.8,0.7,0.6,0.5};
//    copyArray(f, 5, g);
//    int h[]={0,3,5,-3,-5};
//    string i[]={"","","","",""};
//    convert(h,i, 5);
//    float j[]={9.6,3.4,5.6,11.4,2.8};
//    cout<<findMedian(j, 5)<<endl;
//    float k[]={9.6,3.4,5.6,11.4,2.8,7.6};
//    cout<<findMedian(k, 6)<<endl;
//}
//
