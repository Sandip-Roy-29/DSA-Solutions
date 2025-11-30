#include<bits/stdc++.h>

using namespace std;

vector<int> searchRange(vector<int>& nums,int target){
    int firstOccurance = -1;
    int lastOccurance = -1;

    for(int i=0; i<nums.size(); i++){
        if(nums[i] == target && firstOccurance == -1){
            firstOccurance = i;
            lastOccurance = firstOccurance;
        }else{
            if(nums[i] == target){
            lastOccurance = i;
            }
        }  
    }
    return {firstOccurance,lastOccurance};
}

int lowerBound(vector<int>& nums,int target){
    int low = 0;
    int high = nums.size()-1;
    int ans = nums.size();

    while(low<=high){
        int mid = low+(high-low)/2;
        if(nums[mid]>=target){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}

int upperBound(vector<int>& nums,int target){
    int low = 0;
    int high = nums.size()-1;
    int ans = nums.size();

    while(low<=high){
        int mid = low+(high-low)/2;
        if(nums[mid]>target){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}
vector<int> searchRange2(vector<int>& nums, int target) {
    int lb = lowerBound(nums,target);
    int ub = upperBound(nums,target);

    if(lb == nums.size() || nums[lb] != target) return {-1,-1};
    else return {lb,ub-1};
}

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    vector<int> temp = searchRange(nums,8);
    for(int it : temp){
        cout<< it;
    }
    return 0;
}