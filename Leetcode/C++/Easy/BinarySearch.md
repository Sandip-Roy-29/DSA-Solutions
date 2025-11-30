# 🧠 LeetCode Notes by **Sandip Roy**

## 🧩 Problem: _[704. Binary Search]_

### **A. Problem Restatement:-**

Given a sorted array **nums** with a target, return the **index of the target**.<br> 
If the target does not exist, return **-1**.

**nums** contains distinct values in  **ascending order**.

We have to solve this problem using **Binary Search**.

### **B. Example:-**

| Input         | Output  | Explanation |
| ------------- | ------- | ----------- |
| `[-1,0,3,5,9,12], target = 9` | `4` | **9** is at index **4**. |
| `[-1,0,3,5,9,12], target = 2` | `-1` | There is no **2**. |

---

## **C. Intuition :**
We reduce the search space by comparing mid with target.<br>
If mid is **greater** → remove the right half.<br>
If mid is **smaller** → remove the left half.

### ⚙️ **Approach-**
 
- Declare low = 0 and high = n-1.
- Run a loop until **low<=high**.
- Find mid = **low+(high-low)/2**.
- tf **nums[mid] == target**, return **mid**. 
- if **nums[mid]>target**, **high = mid-1**.
- Otherwise **low = mid+1**;
- If target does not exist return -1.
> high = mid-1; eliminates right half.<br>low = mid+1; eliminates left half.<br>**Overflow:** if we find mid by **low+high/2** it may occurs overflow, eg. if mid is integer data type and low and high is INT_MAX, so INT_MAX+INT_MAX , which we can not store in mid ,in that case we can perform two tasks to avoid overflow case -<br>1. we change mid to **long** or **long long** data type.<br>2. use **low(high-low)/2**.    

### **Complexity:-**

- Time complexity: Each steps remove half of the search space, so total time takes **O(log n)**.

- Space complexity: it does not use any extra data structure so it takes **O(1)** space in memory.
- Code:-

```cpp
#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int>& nums, int target){
    int low = 0;
    int high = nums.size()-1;

    while(low<=high){
        int mid = low+(high-low)/2;

        if(nums[mid] == target) return mid;
        else if(nums[mid]>target) high = mid-1;
        else low = mid+1;
    }
    return -1;
}

int main(){
    vector<int> nums = {-1,0,3,5,9,12};
    cout<<binarySearch(nums,9);
    return 0;
}
```
---