/*
@https://www.hackerrank.com/challenges/richie-rich

Sandy likes palindromes. A palindrome is a word, phrase, number, or other 
sequence of characters which reads the same backward as it does forward. 
For example, madam is a palindrome.

On her 7th birthday, Sandy's uncle, Richie Rich, offered her an -digit check which she 
refused because the number was not a palindrome. Richie then challenged Sandy to 
make the number palindromic by changing no more than k digits. Sandy can only change  
digit at a time, and cannot add digits to (or remove digits from) the number.

Given k and an n-digit number, help Sandy determine the largest possible number she can 
make by changing<=k digits.

Note: Treat the integers as numeric strings. Leading zeros are permitted and can't be ignored 
(So 0011 is not a palindrome, 0110 is a valid palindrome). A digit can be modified more than once.

Input Format

The first line contains two space-separated integers,  (the number of digits in the number) and  
(the maximum number of digits that can be altered), respectively. 
The second line contains an -digit string of numbers that Sandy must attempt to make palindromic.

Constraints
0<=n<=10^5;
0<=k<=10^5;
Each character i in the number is an integer where 0<=i<=9.

Output Format

Print a single line with the largest number that can be made by changing no more than k digits; 
if this is not possible, print -1.
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
        
    for(int i=0;i<middleIdx;++i){
        if(number[i]!=number[n-i-1]){            
            ++diffNum;
        }            
    }
    if(diffNum>k){
        cout << "-1" << endl;
        return 0;
    }
    for(int i=0;i<middleIdx;++i){
       if(k<1) break;           
       if(number[i]!=number[n-i-1]){
           if( number[i]<'9' && number[n-i-1]<'9' && (k-diffNum)>0){
               setNine(number[i],number[n-i-1]);               
               k=k-2;
               --diffNum;
           }else{
               setMax(number[i],number[n-i-1]);
               --k;
               --diffNum;
           }
         continue;
       }
       if(number[i]<'9' && (k-diffNum)>1){            
          setNine(number[i],number[n-i-1]);
          k=k-2;
           
        }      
    }
    if(k>0 && n%2==1){
        number[middleIdx]='9';
    }
    
    cout <<  (diffNum>0? "-1" :number) << endl;  
    return 0;
}
