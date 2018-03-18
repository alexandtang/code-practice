#include <bits/stdc++.h>

using namespace std;
// Merge the arrary and return the number of times of swapping
long merge_sort(int arr[], int l, int r){
    int s = r-l;
    if(s < 1 || l>r ) return 0;
    int mid = (l+r)/2;
    int temp_idx = 0;
    int swaps = 0;
    int* temp_arr = new int[r-l+1];
    int left_idx = l;
    int right_idx = mid+1;

    swaps = merge_sort(arr,l,mid) + merge_sort(arr,mid+1,r);
    
    while(left_idx <= mid && right_idx <=r){
        if(arr[left_idx] <= arr[right_idx]){
            temp_arr[temp_idx] = arr[left_idx];
            left_idx++;
        }else{
            temp_arr[temp_idx] = arr[right_idx];
            right_idx++;
            swaps += (mid + 1 - left_idx);
        }
        temp_idx++;
    }
    for(int i=left_idx;i<=mid;temp_idx++,i++)
        temp_arr[temp_idx]=arr[i];
    for(int i=right_idx;i<=r;temp_idx++,i++)
        temp_arr[temp_idx]=arr[i];    
    for(int i=0,n=l;n<=r;n++,i++)
        arr[n] = temp_arr[i];
    delete [] temp_arr;
    return swaps;
}


int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int* arr = new int[n];
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        long swaps = merge_sort(arr,0,n-1);
        cout << swaps << endl;
    }
    return 0;
}
