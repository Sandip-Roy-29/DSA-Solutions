#include<bits/stdc++.h>

using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i+1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

vector<int> twoSum2(vector<int>& nums, int target) {
    unordered_map<int,int> m;

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if(m.find(complement)!=m.end()){
                return vector<int>{m[complement],i};
            }else{
                m[nums[i]] = i;
            }
        }
        return vector<int>{};
}

int main(){
   vector<int> nums = {2,7,15,11};
    vector<int> temp = twoSum2(nums,9);
    for(int i:temp){
        cout<<i;
    }
   return 0;
}