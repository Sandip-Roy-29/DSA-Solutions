# 🧠 LeetCode Notes by **Sandip Roy**

## 🧩 Problem: _[34. Find First and Last Position of Element in Sorted Array]_

### **A. Problem Restatement:-**

Given a sorted array **nums** with a target, return the **first and last occurrence index of the target**.<br> 
If the target does not exist, return **[-1,-1]**.

### **B. Example:-**

| Input         | Output  | Explanation |
| ------------- | ------- | ----------- |
| `[5,7,7,8,8,10],target = 8` | `[3,4]` | **8** is at index **3** and **4**. |
| `[5,7,7,8,8,10], target = 6`     | `[-1,-1]` | There is no **6**. |
| `nums = [], target = 0`     | `[-1,-1]` | There is no **0**. |
| `nums = [5], target = 5`     | `[0,0]` | **5** is at **0**. |


---

## **C. Intuition — Brute :**
Check each element and determine whether it matches the target. 

### ⚙️ **Approach-**
 
- Declare firstOccurrence = -1 and lastOccurrence = -1.
- Run a loop from **0** to **n-1**.
- Check **nums[i] == target** and **firstOccurrence == -1**. 
    - If yes -> **firstOccurrence = i** and **lastOccurrence = i**.
    - If not -> check **nums[i] == target**.
        - If yes -> **lastOccurrence = i**.
- Return firstOccurrence and lastOccurrence.

### **Complexity:-**

- Time complexity: The loop runs  **approximately n** times in the worst case, so it will take **O(n)** time.

- Space complexity: it does not use any extra data structure so it takes **O(1)** space in memory.
- Code:-

```cpp
#include <bits/stdc++.h>

using namespace std;

vector<int> searchRange(vector<int>& nums,int target){
    int firstOccurrence = -1;
    int lastOccurrence = -1;

    for(int i=0; i<nums.size(); i++){
        if(nums[i] == target && firstOccurrence == -1){
            firstOccurrence = i;
            lastOccurrence = i;
        }else{
            if(nums[i] == target){
            lastOccurrence = i;
            }
        }  
    }
    return {firstOccurrence,lastOccurrence};
}

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    vector<int> temp = searchRange(nums,8);
    for(int it : temp){
        cout<< it;
    }
    return 0;
}
```
---

## **D. Intuition - Optimal :**
If the array is in **sorted** order and we have to **search** an element, we can efficiently use **binary search**.<br>
### Prerequisite:
Here we use lower and upper bound concept.

Lower bound: 
- returns the first index i such that  **nums[i] >= target**.
- If target does not exists return size of the array. 

Upper bound: 
- returns the first index i such that **nums[i] > target**.
- If target does not exists return size of the array. 

### ⚙️ **Approach-**

-  After finding Lower bound and Upper bound.
    - If **lb == nums.size()** or **nums[lb] != target**, return {-1,-1}
- Otherwise return **{lb,ub-1}**.

### **Complexity:-**

- Time complexity: This approach uses binary search so it will take **O(log n)** time.

- Space complexity: It does not use any extra data structure so it takes **O(1)** space in memory.

- Code:-

```cpp
#include <bits/stdc++.h>

using namespace std;

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
    vector<int> temp = searchRange2(nums,8);
    for(int it : temp){
        cout<< it;
    }
    return 0;
}
```
---
