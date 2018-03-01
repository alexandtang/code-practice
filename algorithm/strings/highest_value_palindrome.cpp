/*
@https://www.hackerrank.com/challenges/richie-rich

Palindromes are strings that read the same from the left or right, for example madam or 0110.

You will be given a string representation of a number and a maximum number of changes you can make. 
Alter the string, one digit at a time, to create the string representation of the largest number 
possible given the limit to the number of changes. The length of the string may not be altered, so 
you must consider 0's left of all higher digits in your tests. For example 0110 is valid, 0011 is not.

Given a string representing the starting number and a maximum number of changes allowed, create the 
largest palindromic string of digits possible or the string -1 if it's impossible to create a palindrome
under the contstraints.

Input Format

The first line contains two space-separated integers,  n(the number of digits in the number) and  
k(the maximum number of changes allowed), respectively. 
The second line contains an n-digit string of numbers that you are to attempt to make palindromic.

Print a single line with the largest number that can be made by changing no more than k digits; 
if this is not possible, print -1.

Sample Input 0
4 1
3943

Sample Output 0
3993

Sample Input 1
6 3
092282

Sample Output 1
992299
*/

#include <string>
#include <iostream>

using namespace std;

void setMax(char& a, char& b){
   if(a>b) b=a;
   else a=b;
}

void setNine(char&a, char&b){    
   a='9';
   b='9';         
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    string number;
    cin >> number;
    int diffNum=0;
    n = number.size();
    int middleIdx = n/2;
    if(n==1){
        cout << (k>0?"9":number) <<endl;
        return 0;
    }
    //Count the number of different pairs in the digits
    for(int i=0;i<middleIdx;++i){
        if(number[i]!=number[n-i-1]){            
            ++diffNum;
        }            
    }
   // Print -1 if making palindrome is impossible
    if(diffNum>k){
        cout << "-1" << endl;
        return 0;
    }
   
    for(int i=0;i<middleIdx;++i){
       // Run out of changing quota
       if(k<1) break;     
       if(number[i]!=number[n-i-1]){
           // if both of the digits is not 9 and the quota is sufficient,
           // change both digits to 9;
           // Else, change the smaller digit to the bigger digit
           if( number[i]<'9' && number[n-i-1]<'9' && (k-diffNum)>0){
               setNine(number[i],number[n-i-1]);               
               k=k-2;
               --diffNum;
           }else{
               setMax(number[i],number[n-i-1]);
               --k;
               --diffNum;
           }
       }else if(number[i]<'9' && (k-diffNum)>1){            
          setNine(number[i],number[n-i-1]);
          k=k-2;
       }      
    }
    // If there's still quota, set the middle digit to 9 
    if(k>0 && n%2==1){
        number[middleIdx]='9';
    }
    
    cout <<  (diffNum>0? "-1" :number) << endl;  
    return 0;
}
