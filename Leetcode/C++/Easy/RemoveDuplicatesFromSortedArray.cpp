#include<bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums){
    int pos = 0;
    for (size_t i = 1; i < nums.size()-1; i++)
    {
        /* code */
        if(nums[i] != nums[i+1]){
            nums[pos] = nums[i];
            pos++;
        }
    }
    nums[pos] = nums[nums.size()-1];
    pos++;

    return pos;
    
}

int removeDuplicates2(vector<int>& nums) {
    int write = 0;
    int read = 1;

    while (read < nums.size()) {
        if (nums[read] != nums[write]) {
            nums[++write] = nums[read];
        }
        read++;
    }

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return write + 1;
}

int main(){
    vector<int> nums = {1,1,2,2,3,3,4,4,5,5};
    cout<< removeDuplicates2(nums);
}