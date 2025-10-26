# 🧠 LeetCode Notes by **Sandip Roy**

## 🧩 Problem: _[1. Two Sum]_

### **A. Problem Restatement:-**

The problem asks me to find two numbers in a given array which **sum** is equal to **target** and return their indices.<br>
The answer can be returned in any order.

### **B. Example:-**

| Input         | Output  | Explanation |
| ------------- | ------- | ----------- |
| `[2,7,11,15]` | `[0,1]` | 2 + 7 = 9   |
| `[3,2,4]`     | `[1,2]` | 2 + 4 = 6   |

### **C. constraints:-**

- Length of the array must be between **2** to **10<sup>4</sup>.**
- Each element must be between **-10<sup>9</sup>** to **10<sup>9</sup>.**
- Target must be between **-10<sup>9</sup>** to **10<sup>9</sup>.**
- Only one valid answer exists.

## ⚙️ **Approach 1 — Brute Force**

### **Idea:**

- We use two for loops **i** and **j** to check all of the combinations.
- If any combination’s total equals the target, we return their indices.

---

- Code:-

```java
import java.util.HashMap;

public class TwoSum {

        public static int[] twoSum(int[] nums, int target) {
            for (int i = 0; i < nums.length; i++) {
                for (int j = 0; j < nums.length; j++) {
                    if (nums[i]+nums[j] == target) {
                        return new int[]{i,j};
                    }
                }
            }
            return new int[]{};
        }
    
    public static void main(String[] args) {
        int[] nums = {2,7,11,15};
        int[] temp = twoSum(nums,9);
        System.out.println(temp[0]+","+temp[1]);
    }
}
```

---

> it takes **O(n<sup>2</sup>)** which is too slow for larger input.

---

### **Time & Space Complexity:-**

- Time:- outer loops takes **O(n)**.<br>
  Inner loop takes **O(n)**.<br>
  Total time= **O(n<sup>2</sup>)**.

- Space:- it does not use any extra data structure so it takes **O(1)** space in memory.

---

## ⚙️ **Approach 2 — Optimal Approach**

if we uses hash map we can reduce the time upto **O(n)** but we have to sacrifice constant space because we need to take an hash map of the same size as vector, which takes **O(n)**.

### **Idea:**

- we declare a loop which travers the vector till to the end.
- then we have to find out the **complement= target - current number**
- then check the hash map, the complement is exist or not
- if exist returns both indices
- otherwise stores the current number and its index in the map.

---

- code:-

```java
import java.util.HashMap;

public class TwoSum {
    public static int[] twoSum2(int[] nums, int target) {
            HashMap<Integer,Integer> map = new HashMap<>();
            for (int i = 0; i < nums.length; i++) {
                int complement = target - nums[i];
                if (map.containsKey(complement)) {
                    return new int[]{map.get(complement),i};
                }else{
                    map.put(nums[i], i);
                }
            }
            return new int[]{};
        }
    
    public static void main(String[] args) {
        int[] nums = {2,7,11,15};
        int[] temp = twoSum2(nums,9);
        System.out.println(temp[0]+","+temp[1]);
    }
}
```

---

### **Time & Space Complexity:-**

- Time:- it takes **O(n)** because of single traversal ; where n is the size of the vector <br>

- Space:- it takes one extra hash map to track the element. So it takes **O(n)** space in memory.

---

### **D. Final Note:-**

- Writing multiple approaches helps understand time-space trade-offs.
- Sometimes you have to trade off space for time and choose the faster approach.
