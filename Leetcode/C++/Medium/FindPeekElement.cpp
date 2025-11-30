#include<bits/stdc++.h>

using namespace std;

int findPeek(vector<int>& arr){
    if(arr.size() == 1) return 0;
    for(int i=0; i<arr.size();i++){
        if((i == 0 && arr[i]>arr[i+1]) || 
            (i == arr.size()-1 && arr[i]>arr[i-1]) || 
            (i>0 && i<arr.size()-1 && arr[i]>arr[i+1] && arr[i]>arr[i-1])){
            return i;
        }
    }
    return -1;
}

int findPeek2(vector<int>& arr){
    if((arr.size() == 1) || arr[0]>arr[1]){
        return 0;
    } 
    if(arr[arr.size()-1] > arr[arr.size()-2]) return arr.size()-1;

    int low = 1;
    int high = arr.size()-2;

    while(low<=high){
        int mid = low+(high-low)/2;

        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
        else if(arr[mid]>arr[mid-1]){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    

    vector<int> arr = {1,2,1,3,5,6,4};
    cout<<findPeek(arr);
    cout<<findPeek2(arr);
}