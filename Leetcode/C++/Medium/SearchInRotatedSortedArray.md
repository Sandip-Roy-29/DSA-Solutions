# 🧠 LeetCode Notes by **Sandip Roy**

## 🧩 Problem: _[33. Search in Rotated Sorted Array]_

### **A. Problem Restatement:-**

Given a rotated sorted array **nums** with distinct valuesand a target, return the **index of the target**.<br> 
If it does not exist, return -1.

Sorted array: **[0,1,2,4,5,6,7]**.<br>
Rotateded sorted array: **[4,5,6,7,0,1,2] (left rotated by 3 indices)**.
### **B. Example:-**

| Input         | Output  | Explanation |
| ------------- | ------- | ----------- |
| `[4,5,6,7,0,1,2],target = 0` | `4` | **0** is at index **4th**. |
| `[4,5,6,7,0,1,2],target = 3`     | `-1` | There is no **3**. |
| `nums = [1], target = 0`     | `-1` | There is no **0**. |


---

## **C. Intuition — Brute :**
Check each element and determine whether it matches the target. 

### ⚙️ **Approach-**
 
- run a loop from **0** to **n-1**.
- check **nums[i] == target**, return **i**.
- if targeted value does not exist return **-1**.
---

### **Complexity:-**

- Time complexity: The loop runs  **approximately n** times in the worst case, so it will take **O(n)** time.

- Space complexity: it does not use any extra data structure so it takes **O(1)** space in memory.
- Code:-

```cpp
#include <bits/stdc++.h>

using namespace std;

int searchInRotatedSortedArray(vector<int>& nums,int target){
    for(int i=0; i<nums.size(); i++){
        if(nums[i] == target) return i;
    }
    return -1;
}

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    cout<<searchInRotatedSortedArray(nums,0);
    return 0;
}
```
---

## **C. Intuition - Optimal :**
If the array is in **sorted** order and we have to **search** an element,we can efficiently use **binary search**.<br>

Even though the array is rotated **one half is always sorted**.

- One **half (left or right)** is always **sorted**.
- We find which half is sorted.
- Then we check if the **target** lies inside that **sorted half**.
    - If **yes** → search inside it.
    - If **no** → search in the other half.
- If target does not lies in the array we return **-1**.

### ⚙️ **Approach-**

- Find **mid**.
- If **nums[mid] == target** → return **mid**.
- If left half is sorted **(nums[low] <= nums[mid])**:
    - Check if target lies between **nums[low]** and **nums[mid]**.
        - If **yes** → search in left half **(high = mid-1)**.
        - If **no** → search in right half **(low = mid+1)**.
    - Else → **right half* is sorted***
        - Check if target lies between **nums[mid] and nums[high]**.
        - If **yes** → search in right half **(low = mid+1)**.
        - If **no** → search in left half **(high = mid-1)**.
- If not found → return **-1**.
>In case if you feel slightly confused it is recommended to perform a dry run of the steps above .

### **Complexity:-**

- Time complexity: this approach uses binary search so it will take **O(log n)** time.

- Space complexity: it does not use any extra data structure so it takes **O(1)** space in memory.

- Code:-

```cpp
#include <bits/stdc++.h>

using namespace std;

int searchInRotatedSortedArray2(vector<int>& nums,int target){
    int low = 0;
    int high = nums.size()-1;

    while(low<=high){
        int mid = low+(high-low)/2;

        if(nums[mid] == target ) return mid;
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
    return -1;
}

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    cout<<searchInRotatedSortedArray(nums,0);
    return 0;
}
```
---
