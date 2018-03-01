#include <bits/stdc++.h>
using namespace std;
void printVec(vector<int> &arr){
    for(int i=0;i<arr.size();++i){
        if(i<arr.size()-1)
            cout << arr[i] <<" " ;
        else
            cout << arr[i];
    }
    cout << endl;
    return;
}


void quickSort(vector <int> &arr) {
    vector<int> left;
    vector<int> right;
    if(arr.size()<2)
        return;
    int pivot = arr[0];
    int mid = arr.size()/2;
    for(int i=1;i<arr.size();++i){        
        if(arr[i]<=pivot){
            left.push_back(arr[i]);
        }else{
            right.push_back(arr[i]);
        }
    }
    quickSort(left);
    quickSort(right);
    arr.clear();
    arr.insert(arr.end(),left.begin(),left.end());
    arr.push_back(pivot);
    arr.insert(arr.end(),right.begin(),right.end());
    printVec(arr);
    return;
    
}

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }
    quickSort(arr);

    return 0;
}
