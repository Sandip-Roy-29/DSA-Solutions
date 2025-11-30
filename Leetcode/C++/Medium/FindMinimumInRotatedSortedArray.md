# 🧠 LeetCode Notes by **Sandip Roy**

## 🧩 Problem: _[153. Find Minimum in Rotated Sorted Array]_

### **A. Problem Restatement:-**

Given an rotated sorted array **nums**, return the **smallest element in it**.<br> 

Sorted array: **[0,1,2,3,4,5,6]**.<br>
Roted sorted array: **[3,4,5,6,0,1,2] (roted 4 times)**.
### **B. Example:-**

| Input         | Output  | Explanation |
| ------------- | ------- | ----------- |
| `[3,4,5,1,2]` | `1` | The original array was **[1,2,3,4,5]** rotated **3** times. |
| `[4,5,6,7,0,1,2]`     | `0` | The original array was **[0,1,2,4,5,6,7]** and it was rotated **4** times. |


---

## **C. Intuition — Brute :**
Check each element and determine whether it is the smallest . 

### ⚙️ **Approach-**
 
- run a loop from **1** to **n-1**.
- declare **ans** and initialize with **maximum value**.
- update **ans = min(ans,num[i])**.
- return **ans**.  
---

### **Complexity:-**

- Time complexity: The loop runs  **approximately n** times in the worst case, so it will take **O(n)** time.

- Space complexity: it does not use any extra data structure so it takes **O(1)** space in memory.
- Code:-

```cpp
#include <bits/stdc++.h>

using namespace std;

int findMinimumInRotatedSortedArray(vector<int>& nums){
   
    int ans = INT_MAX;
    for(int i=0; i<nums.size(); i++){
        ans = min(ans,nums[i]);
    }
    return ans;
}

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    cout<<findMinimumInRotatedSortedArray(nums);
    return 0;
}
```
---

## **C. Intuition - Optimal :**
If the array is in **sorted** order and we have to **search** an element,we can efficiently use **binary search**.<br>

If we carefully observe the given example, we notice that by **identifying the sorted part of the array**, we can easily find the smallest element.

So first we find **mid** and check **nums[low] <= nums[mid]** if **true** means this **part (low to high)** is **sorted in ascending order**, so we take the **first element as minimum** and **eliminate this part**. If **false** is part contains the **pivot (unsorted)**, so we consider **nums[mid]** as a candidate for **minimum** and continue searching in this part.


### ⚙️ **Approach-**

- Declare **ans** and initialized it with **INT_MAX**.
- find **mid** and check **nums[low] <= nums[mid]** , if true  **ans = min(ans,nums[low])** and update **low = mid+1**.
- if false **ans = min(ans,nums[mid])** and update **high = mid+1**.
- return **ans**. 
>In case if you feel slightly confused it is recommended to perform a dry run of the steps above .

### **Complexity:-**

- Time complexity: this approach uses binary search so it will take **O(log n)** time.

- Space complexity: it does not use any extra data structure so it takes **O(1)** space in memory.

- Code:-

```cpp
#include <bits/stdc++.h>

using namespace std;

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
    cout<<findMinimumInRotatedSortedArray2(nums);
    return 0;
}
```
---
