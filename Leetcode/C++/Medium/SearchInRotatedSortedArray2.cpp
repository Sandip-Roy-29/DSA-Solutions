#include<bits/stdc++.h>

using namespace std;

bool searchInRotatedSortedArrayTwo(vector<int>& nums,int target){
    for(int i=0; i<nums.size(); i++){
        if(nums[i] == target) return true;
    }
    return false;
}

bool searchInRotatedSortedArrayTwo2(vector<int>& nums,int target){
    int low = 0;
    int high = nums.size()-1;

    while(low<=high){
        int mid = low+(high-low)/2;

        if(nums[mid] == target ) return true;
        else if(nums[low] == nums[mid] && nums[mid] == nums[high]){
            low++;
            high--;
            continue;
        }
        // left half is sorted
        if(nums[low]<=nums[mid]){
            if(nums[low]<=target && target<=nums[mid]){
                high = mid-1;
            }else{
                low = mid+1;
            }
        // right  half is sorted
        }else{
            if(nums[mid]<=target && target<=nums[high]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
    }
    return false;
}

int main(){

    vector<int> nums = {2,5,6,0,0,1,2};
    bool ans = searchInRotatedSortedArrayTwo(nums,0);
    cout<< ans;
    return 0;
}