#include<bits/stdc++.h>

using namespace std;

int singleElementInSortedArray(vector<int>& nums){
    if(nums.size() == 1) return nums[0];

    for(int i=0; i<nums.size();i++){
        if(i == 0){
            if(nums[i] != nums[i+1]) return nums[i]; 
        }else if(i == nums.size()-1){
            if(nums[i] != nums[i-1]) return nums[i];
        }else{
            if(nums[i] != nums[i+1] && nums[i] != nums[i-1]) return nums[i];
        }
    }
    return -1;
}


int singleElementInSortedArray2(vector<int>& nums){

    if(nums.size() == 1) return nums[0];
    if(nums[0] != nums[1]) return nums[0];
    if(nums[nums.size()-1] != nums[nums.size()-2]) return nums[nums.size()-1];
    
    int low = 1;
    int high = nums.size()-2;

    while(low<=high){
        int mid = low+(high-low)/2;

        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
        else if((mid%2 != 0 && nums[mid] == nums[mid-1])|| (mid%2 ==0 && nums[mid]==nums[mid+1])){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return -1;
}

int main(){

    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    cout<<singleElementInSortedArray(nums);
    cout<<singleElementInSortedArray2(nums);
    return 0;
}