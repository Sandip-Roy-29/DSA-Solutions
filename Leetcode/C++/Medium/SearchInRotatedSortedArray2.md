# 🧠 LeetCode Notes by **Sandip Roy**

## 🧩 Problem: _[81. Search in Rotated Sorted Array II]_

### **A. Problem Restatement:-**

Given a rotated sorted array **nums** in **non-decreasing** order (not necessarily with **distinct values**) and a target, return **true** if target is in nums.<br> 
If it does not exist, return **false**.

Sorted array: **[0,1,2,4,4,4,5,6,6,7]**.<br>
Rotated sorted array: **[4,5,6,6,7,0,1,2,4,4]** (left rotated by 5 indices).
### **B. Example:-**

| Input         | Output  | Explanation |
| ------------- | ------- | ----------- |
| `[2,5,6,0,0,1,2], target = 0` | `true` | **0** exists in the array. |
| `[2,5,6,0,0,1,2], target = 3` | `false` | There is no **3**. |

---

## **C. Intuition — Brute :**
The brute force idea is simple: check every number until we find the target
### ⚙️ **Approach-**
 
- run a loop from **0** to **n-1**.
- check **nums[i] == target**, return **true**.
- if target value does not exist return **false**.
---

### **Complexity:-**

- Time complexity: The loop runs  **approximately n** times in the worst case, so it will take **O(n)** time.

- Space complexity: it does not use any extra data structure so it takes **O(1)** space in memory.
- Code:-

```cpp
#include <bits/stdc++.h>

using namespace std;

bool searchInRotatedSortedArrayTwo(vector<int>& nums,int target){
    for(int i=0; i<nums.size(); i++){
        if(nums[i] == target) return true;
    }
    return false;
}

int main(){
    vector<int> nums = {2,5,6,0,0,1,2};
    bool ans = searchInRotatedSortedArrayTwo(nums,0);
    cout<< ans;
    return 0;
}
```
---

## **D. Intuition - Optimal :**
If the array is in **sorted** order and we have to **search** an element,we can efficiently use **binary search**.<br>

Even though the array is rotated **one half is always sorted**.

- One half (left or right) is always **sorted**.
- We find which half is sorted.
- Then we check if the **target** lies inside that sorted half.
    - If **yes** → search inside it.
    - If **no** → search in the other half.
- If target does not lie in the array we return **false**.
> There is an edge case that we have to keep in mind otherwise our code will fail:<br> 
>- since the array may contain duplicates, have to check **nums[low] == nums[mid] == nums[high]**, if yes low++ and high--.<br>
>- This case breaks the logic because we **cannot determine** which half is sorted, so we shrink the search space from both sides. 

### ⚙️ **Approach-**

- Find **mid**.
- If **nums[mid] == target** → return **true**.
- If **nums[low] == nums[mid] == nums[high]**, low++ and high--;
- If left half is sorted **(nums[low] <= nums[mid])**:
    - Check if target lies between **nums[low]** and **nums[mid]**.
        - If **yes** → search in left half **(high = mid-1)**.
        - If **no** → search in right half **(low = mid+1)**.
    - Else → **right half* is sorted***
        - Check if target lies between **nums[mid]** and **nums[high]**.
        - If **yes** → search in right half **(low = mid+1)**.
        - If **no** → search in left half **(high = mid-1)**.
- If not found → return **false**.
>In case if you feel slightly confused it is recommended to perform a dry run of the steps above .

### **Complexity:-**

- Time complexity: this approach uses binary search so it will take **O(log n)** time.

- Space complexity: it does not use any extra data structure so it takes **O(1)** space in memory.

- Code:-

```cpp
#include <bits/stdc++.h>

using namespace std;

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
    bool ans = searchInRotatedSortedArrayTwo2(nums,0);
    cout<< ans;
    return 0;
}
```
---
