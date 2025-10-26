# 🧠 LeetCode Notes by **Sandip Roy**

## 🧩 Problem: _[26. Remove Duplicates from Sorted Array]_

### **A. Problem Restatement:-**

The problem asks me to remove **duplicate elements** from a **non-decreasing sorted array in-place**, in such a way that the **relative order** of elements remains the same.
After removing duplicates, the function should **return the number of unique elements**.<br>
Let **k** be the number of unique elements. After processing, the first **k** elements of the array should contain the **unique elements in sorted order**, and the remaining elements beyond index **k-1** can be ignored

### **B. Example:-**

| Input         | Output  | Explanation |
| ------------- | ------- | ----------- |
| `[1,1,2]` | `2` | after removing the duplicate the array has **[1,2,_]**  two elements.|
| `[0,0,1,1,1,2,2,3,3,4]`     | `5` | after removing the duplicate the array has **[0,1,2,3,4,_,_,_,_,_]**  five elements |

### **C. constraints:-**

- Length of the array must be between **1** to **3 * 10<sup>4</sup>.**
- Each element must be between **-100** to **100.**
- The array is sorted in **non-decreasing** order.

## ⚙️ **Approach 2 — Optimal Approach**
 
### **Idea-1:**

- Declare a **pos** variable initialized to **0**, which tracks the position for unique elements.
- loop through the array.
- Inside the loop, check if the current element is equal to the next one.
- If they are not equal, store the current element at the **pos** position and increment **pos**.
- Skip duplicates and move forward. 
- Finally, store the last element, increment **pos**, and return it.
---

- Code:-

```java
public class RemoveDuplicatesFromSortedArray {
    public static int removeDuplicates(int[] nums) {
        int pos = 0;

        for (int i = 0; i < nums.length-1; i++) {
            if (nums[i] != nums[i+1]) {
                nums[pos] = nums[i];
                pos++;
            }
        }

        nums[pos] = nums[nums.length - 1];
        pos++;

        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i]+" ");
        }
        System.out.println();
        return pos;
    }

    public static void main(String[] args) {
        int[] nums = {1,1,2,2,3,3,4,4,5,5};
        System.out.println(removeDuplicates(nums));
    }
}

```
---

### **Time & Space Complexity:-**

- Time:- there is only one loop that traverse the array, takes **O(n)** time; where **n** is the size of the array.

- Space:- it does not use any extra data structure so it takes **O(1)** space in memory.

---

### **Idea-2[Using Two-Pointer]:**

- Declare **write** (to track the position for unique elements) and **read** (to traverse the array).
- Iterate through the array using **read**.
- Compare the elements at **read** and **write** positions.
- If they are different, increment **write** and copy the **read** element to **nums[write]**.
- If they are the same, continue with the next **read** index.
- At the end, return **write + 1**, because write starts from **0**. 

---

- code:-

```java
public class RemoveDuplicatesFromSortedArray {

    public static int removeDuplicates2(int[] nums) {
        int write = 0;
        int read = 1;

        while (read < nums.length) {
            if (nums[read] != nums[write]) {
                nums[++write] = nums[read];
            }
            read++;
        }

        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i]+" ");
        }
        System.out.println();
        return write+1;
    }
    public static void main(String[] args) {
        int[] nums = {1,1,2,2,3,3,4,4,5,5};
        System.out.println(removeDuplicates2(nums));
    }
}

```

---

### **Time & Space Complexity:-**

- Time:- it takes **O(n)** because of single traversal ; where n is the size of the array <br>

- Space:- it does not use any extra data structure so it takes **O(1)** space in memory.

---
> This  problem is not have any Brute and Better approach. Besause we must traverse the array to the end for solving the problem.
### **D. Final Note:-**

- Writing multiple approaches helps understand time-space trade-offs.
- Some problems have only one valid way to solve them, which also happens to be the optimal approach..
