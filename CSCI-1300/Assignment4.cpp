////Author: Xinyu Jiang
////Recitation: CSCI1300-210 TA:Xiaozhe Zhang
////
////Assignment 4
////
//
//#include <iostream>
//using namespace std;
///*
// *Algorithm description
// *   declare an int variable for index
// *   if the two string length are different return 0
// *   if the word are same in the same index
// *   matches+1, else mismatch+1
// *   return the result equal to
// *   (string length-mismatch)/string length
// */
//float  similarityScore(string str1, string str2){
//    int i=0;
//    int matches=0;
//    int misMatches=0;
//    float result;
//    
//    if(str1.length()!=str2.length()){
//        return 0;
//    }
//    //check if the two string are same length
//    else{
//        while(i<str1.length() && str1.length()==str2.length()){
//            if(str1[i]==str2[i]){
//                matches++;
//            }
//            //if they are the same matches++
//            if(str1[i]!=str2[i]){
//                misMatches++;
//            }
//            //if the are different misMatches++
//            i++;
//            
//        }
//        result=((str1.length()-misMatches)*1.0)/(str1.length());
//        return result;
//    }
//}
///*
// *Algorithm description
// *   declare i for index, and declare an int variable "count" to count
// *   call the similarityScore function to see if the score is over
// *   the minScore, if it is bigger than min Score
// *   count++, and return the count value
// */
//int countMatches(string str1,string str2,float minScore){
//    int i=0;
//    int count=0;
//    while(i<=str1.length()-str2.length()){
//        //i<=str1.length()-str2.length() because when you check the last
//        //substring, it may too short, so you just check the substring
//        //that length is the same with str2
//        if(similarityScore(str1.substr(i,str2.length()), str2)>=minScore){
//            count++;
//        }
//        i++;
//    }
//    return count;
//}
///*
// *Algorithm description
// *   initialize a variable i for index, and highest to store the highest
// *   similarity score, while i is small than str1's length
// *   initialize a variable x to store the highest score
// *   if the score is bigger than the highest
// *   give x value to highest
// */
//float findBestMatch(string str1,string seq){
//    int i=0;
//    float highest=0.0;
//    while(i<str1.length()){
//        float x= similarityScore(str1.substr(i,seq.length()), seq);
//        //initialize a variable x to store the similarity score
//        if(x>highest){
//            highest=x;
//            //if x is bigger than highest, give the x value to highest
//        }
//        i++;
//    }
//    return highest;
//}
///*
// *Algorithm description
// *   initialize three variable result1, result2, result3 to store the
// *   best match value, if result1 is the biggest, return 1
// *   if result2 is biggest, return 2
// *   if result3 is biggest, return 3
// *   else return 0
// */
//int findBestGenome(string str1, string str2,string str3,string seq){
//    float result1=findBestMatch(str1, seq);
//    float result2=findBestMatch(str2, seq);
//    float result3=findBestMatch(str3, seq);
//    if(result1>result2 &&result1>result3){
//        return 1;
//    }
//    if(result2>result1 &&result2>result3){
//        return 2;
//    }
//    if(result3>result1 &&result3>result2){
//        return 3;
//    }
//    
//    return 0;
//}
//
