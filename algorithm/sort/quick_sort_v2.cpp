#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int &a,int &b){
    int tmp = a;
    a=b;
    b=tmp;
}

void printVec(vector<int> &vec){
    for(int i=0;i<vec.size();++i){
        if(i<vec.size()-1)
            cout << vec[i] << " ";
        else
            cout << vec[i] << endl;
    }
}

void quickSort(vector<int> &vec,int begin,int end){
    if(begin>=end){
        return;
    }
     
    int pivot = vec[end];
    int pivotIdx = begin;  
    // Go through the list to get the pivot index for pivot(vec[end]),
    // and put all the item to the left side of the pivot index.
    // In other words, the pivot index is the number of items which are 
    // smaller than the pivot.
    for(int i=begin;i<end;++i){
        if(vec[i]<=pivot){
            if(i>pivotIdx){
                swap(vec[i],vec[pivotIdx]);                   
            }
            ++pivotIdx; 
        }
    }
    // IMPORTANT - put the pivot to the place where it should be
    swap(vec[end],vec[pivotIdx]);   
    printVec(vec);
    // Sort left side and right side
    quickSort(vec,begin,pivotIdx-1);
    quickSort(vec,pivotIdx+1,end);  
    
}

int main() {
    int n;
    vector<int> vec;
    cin >> n;
    for(int i=0;i<n;++i){
        int e;
        cin>>e;
        vec.push_back(e);
    }
    
    quickSort(vec,0,n-1);
    
    return 0;
}
