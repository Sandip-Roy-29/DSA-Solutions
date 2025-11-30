#include<bits/stdc++.h>

using namespace std;

int findMinimumInRotatedSortedArray(vector<int>& nums){
   
    int ans = INT_MAX;
    for(int i=0; i<nums.size(); i++){
        ans = min(ans,nums[i]);
    }
    return ans;
}

int findMinimumInRotatedSortedArray2(vector<int>& nums){
    int low = 0;
    int high = nums.size()-1;
    int ans = INT_MAX;

    while(low<=high){
        int mid = low+(high-low)/2;

        if(nums[low]<=nums[mid]){
            ans = min(ans,nums[low]);
            low = mid+1;
        }else{
            ans = min(ans,nums[mid]);
            high = mid-1;
        }
    }
    return ans;
}

int main(){

    vector<int> nums = {4,5,6,7,0,1,2};
    cout<<findMinimumInRotatedSortedArray(nums);
    return 0;
}