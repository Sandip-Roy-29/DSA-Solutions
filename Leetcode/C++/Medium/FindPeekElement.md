# 🧠 LeetCode Notes by **Sandip Roy**

## 🧩 Problem: _[162. Find Peak Element]_

### **A. Problem Restatement:-**
**Peek element** - A peak element is an element that is strictly **greater than both of its neighbors**.

Given an array **nums**, return the **index of any peak element**.<br>
If the array contains **multiple peaks**, returning **any one of their indices** is acceptable.

Assume that: **nums[-1] = nums[n] = -∞**,
which ensures that the boundaries can also be considered for peaks. 

### **B. Example:-**

| Input         | Output  | Explanation |
| ------------- | ------- | ----------- |
| `[1,2,3,1]` | `2` | **3** is greater than  it's neighbors **(2< 3 >1)**. |
| `[1,2,1,3,5,6,4]`     | `1/5` | Both **2** and **6** are peaks, so either **1** or **5** is valid. |
| `[1,2,3,4]` | `3` |Last element **4** is a peak because **3 < 4 > -∞**.|
| `[7,6,5,4]` | `0` |First element **7** is a peak because **-∞ < 7 > 6**.|

---

## **C. Intuition — Brute :**
Check each element and determine if it is greater than its neighbors. 

### ⚙️ **Approach-**
 
- for **nums[0]**, check **nums[0]>nums[1]**, if yes simply return **0**.
- for **nums[n-1]**, check **nums[n-1]>nums[n-2]**, if yes simply return **n-1**.
- for all the other cases - 
    - run a loop from **1** to **n-2**.
    - if **nums[i-1]< nums[i] >nums[i+1]**, return **i**.
- if peek is not available return **-1**.  
---

### **Complexity:-**

- Time complexity: The loop runs from **approximately n** times in the worst case, so it wil take **O(n)** time.

- Space complexity: it does not use any extra data structure so it takes **O(1)** space in memory.
- Code:-

```cpp
#include <bits/stdc++.h>

using namespace std;

int findPeek(vector<int>& arr){
    if(arr.size() == 1) return 0;
    for(int i=0; i<arr.size();i++){
        if((i == 0 && arr[i]>arr[i+1]) || 
            (i == arr.size()-1 && arr[i]>arr[i-1]) || 
            (i>0 && i<arr.size()-1 && arr[i]>arr[i+1] && arr[i]>arr[i-1])){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1,2,1,3,5,6,4};
    cout<<findPeek(arr);
    return 0;
}
```
---

## **C. Intuition - Optimal :**
if the array is in sorted order and we have to search an element, we must use binary search.

- if array contains only one peak element- [1,2,3,1].<br>
> in the below image **big orange ball** act as the **peak** which is **2** in this case, and the **small orange balls** act as **mid**.<br>

![one peak](./one%20peek.png "Optional Title on mouseover")
if **mid** is pointing to the **left side(1)** of the **peak** we have to **eliminate the left side and update the low as mid+1** and if **mid** is pointing to the **right side(3 or 1)** of the peak we have to **eliminate the right side and update the value of the high as mid-1**.

- if array contain multiple peak elements- [1,2,1,3,5,6,4].<br>
> in the below image **big orange ball** act as the **peak** which is **2** or **6** in this case, and the **small orange balls** act as **mid**.<br>

![multiple peak](./multiple%20peek.png "Optional Title on mouseover")
Same as  before but the main difference is that **the main difference is that while eliminating one side, any extra peak will automatically be removed**.<br>
In this example while eleminating the elements, **extra peak(which can be 2 or 6) will be eleminate** and the **remaining peak (which can be 2 if 6 eliminate or which can be 6 if 2 eliminate) will be the final result**.

- if array is increasing order- [1,2,3,4].<br>

![increasing order](./increasing%20order.png "Optional Title on mouseover")
we have to check only the **last element** if it is **greater than from second last** it will be the answer.

- if array is decreasing order- [7,6,5,4].<br>

![decreasing order](./decreasing%20order.png "Optional Title on mouseover")
we have to check only the **first element** if it is **greater than from second** it will be the answer.

### ⚙️ **Approach-**

 - for **nums[0]**, check **nums[0]>nums[1]**, if yes simply return **0**.
- for **nums[n-1]**, check **nums[n-1]>nums[n-2]**, if yes simply return **n-1**.
- for all the other cases - 
    - run a loop from **1** to **n-2**.
    - find **mid** and check **nums[mid-1]< nums[mid] >nums[mid+1]**, if true return **mid** otherwise continue.
    - if **nums[mid-1]< nums[mid]** means array is in increasing order and definitely the peek will be the right side of the mid, so update **low = mid+1**.
    - if **nums[mid-1]> nums[mid]** means array is in decreasing order and definitely the peek will be the left side of the mid, so update **high = mid-1**.
- if peek is not available return **-1**. 


### **Complexity:-**

- Time complexity: this approach used binary search so it will take **O(log n)** time.

- Space complexity: it does not use any extra data structure so it takes **O(1)** space in memory.
- Code:-

- Code:-

```cpp
#include <bits/stdc++.h>

using namespace std;

int findPeek2(vector<int>& arr){
    if((arr.size() == 1) || arr[0]>arr[1]){
        return 0;
    } 
    if(arr[arr.size()-1] > arr[arr.size()-2]) return arr.size()-1;

    int low = 1;
    int high = arr.size()-2;

    while(low<=high){
        int mid = low+(high-low)/2;

        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
        else if(arr[mid]>arr[mid-1]){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1,2,1,3,5,6,4};
    cout<<findPeek2(arr);
    return 0;
}
```
---
