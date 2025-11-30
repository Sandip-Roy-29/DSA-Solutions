# 🧠 LeetCode Notes by **Sandip Roy**

## 🧩 Problem: _[540. Single Element in a Sorted Array]_

### **A. Problem Restatement:-**

Given an array **nums**, return the **element which appears exactly once**.<br> 

### **B. Example:-**

| Input         | Output  | Explanation |
| ------------- | ------- | ----------- |
| `[1,1,2,3,3,4,4,8,8]` | `2` | **2** appears exactly once. |
| `[3,3,7,7,10,11,11]`     | `10` | **10** appears exactly once. |


---

## **C. Intuition — Brute :**
Check each element and determine whether it is equal to its neighbor. 

### ⚙️ **Approach-**
 
- if **nums.size() == 1**, return **nums[0]**. 
- for **nums[0]**, check **nums[0] != nums[1]**, if true return **nums[0]**.
- for **nums[n-1]**, check **nums[n-1] != nums[n-2]**, if true return **nums[n-1]**.
- for all the other cases - 
    - if **nums[i-1] != nums[i] != nums[i+1]**, return **nums[i]**.
- if no such element exists return **-1**.  
---

### **Complexity:-**

- Time complexity: The loop runs  **approximately n** times in the worst case, so it wil take **O(n)** time.

- Space complexity: it does not use any extra data structure so it takes **O(1)** space in memory.
- Code:-

```cpp
#include <bits/stdc++.h>

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

int main(){
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    cout<<singleElementInSortedArray(nums);;
    return 0;
}
```
---

## **C. Intuition - Optimal :**
If the array is in **sorted** order and we have to **search** an element, we must use **binary search**.<br>

If we carefully observe the given example, we notice that on the **left** side of the single element, pairs exist at **even,odd** indices and **right** side **odd,even** indices.

so first we find **mid** and check whether it is the single element or not, if not, check **mid**, if **mid** is **odd** and **nums[mid] = nums[mid-1]** or it is **even** and **nums[mid] = nums[mid+1]**, means **mid** is in the **left** side otherwise **mid** is **right** side.

If **mid** is in the **left eliminate the left half** and if it is **right eliminate the right half**.

### ⚙️ **Approach-**

- if **nums.size() == 1**, return **nums[0]**. 
- for **nums[0]**, check **nums[0] != nums[1]**, if true return **nums[0]**.
- for **nums[n-1]**, check **nums[n-1] != nums[n-2]**, if true return **nums[n-1]**.
- for all the other cases - 
    - run a loop from **1** to **n-2**.
    - find **mid** and check **nums[mid-1] != nums[mid]  != nums[mid+1]**, if true return **mid** otherwise continue.
    - if **mid** is **odd** and **nums[mid-1] == nums[mid]** or **mid** is **even** and **nums[mid+1] == nums[mid]** means array is in left side and we need to eliminate the left side to find our desired result, so update **low = mid+1**.
    - if **mid** is **odd** and **nums[mid+1] == nums[mid]** or **mid** is **even** and **nums[mid-1] == nums[mid]** means array is in right side and we need to eliminate the right side to find our desired result, so update **high = mid-1**.
- if single element is not existed return **-1**. 
>In case if you feel slightly confused it is recommended to perform a dry run above the following step.

### **Complexity:-**

- Time complexity: this approach uses binary search so it will take **O(log n)** time.

- Space complexity: it does not use any extra data structure so it takes **O(1)** space in memory.

- Code:-

```cpp
#include <bits/stdc++.h>

using namespace std;

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
    cout<<singleElementInSortedArray2(nums);;
    return 0;
}
```
---
