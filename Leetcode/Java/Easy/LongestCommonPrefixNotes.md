# 🧠 LeetCode Notes by **Sandip Roy**

## 🧩 Problem: *[14. Longest Common Prefix]*

### **A. Problem Restatement:-**

The problem asks me to find the **Longest Common Prefix** among a given array of string.<br>
If no common prefix exists return empty string **""**

### **B. Example:-**

| Input | Output | Explanation |
|--------|---------|-------------|
| `[flower,flow,flight]` | `fl` | **fl** is the longest common prefix|
| `[dog,racecar,car]` | `""` | there is no common prefix |

### **C. constraints:-**

- Length of the array of string must be between **1** to **200**
- Each string size must be between **0** to **200**
- Each string consist only of lowercase English letters(if non-empty).

## ⚙️ **Approach 1 — Brute Force**

### **Idea-1:**
Checks the common prefix between strings one by one.<br>
Example: **[flower,flow,flight]** -> first check prefix between **flower** and **flow**(returns **flow**) then check the prefix that came from previous comparision with **flight**(returns **fl**).

---

- Code:-
```java
public class LongestCommonPrefix {
    public static String longestCommonPrefix(String[] strs) {
        String prefix = strs[0];
        for (int i = 0; i < strs.length-1; i++) {
            String s1 = prefix;
            String s2 = strs[i+1];
            int j = 0;

           while (j<s1.length() && j<s2.length()) {
                if (s1.charAt(j) == s2.charAt(j)) {
                    j++;
                }else{
                    break;
                }
            }          
            prefix = s1.substring(0, j);
            if (prefix.isEmpty()) {
                return "";
            }
        }
        return prefix;
    }

    public static void main(String[] args) {
        String[] strs = {"flower","flow","flight"};
        System.out.println(longestCommonPrefix(strs));
    }
}

```
---

> This approach is also known as Horizontal approach because,The horizontal approach compares pairs of strings sequentially (e.g., first string with the second, then result with the next). first check **flow**er with **flow**, then checks the result **fl**ow with remaining string **fl**ight,and then returns **fl**.

---
### **Time & Space Complexity:-**

- Time:- it travers the full array takes **O(n)**; where **n** is the size of the array.<br>
travers upto smallest common prefix takes **O(m)**; where **m** is the size of the smallest common prefix.<br>
Total time = **O(n*m)**.

- Space:- There is no need to take extra data structure so it takes constant(O(1)) space .

---

### **Idea-2:**
Checks a character of the one string with others, if same checks next character and if not return the character.<br>
Example: **[flower,flow,flight]** -> first check character **f** from flower with **flow** and **flight**, same, check next character **l**, same checks next one  **o**, not same returns **fl**.

---

- Code:-
```java
public class LongestCommonPrefix {

    public static String longestCommonPrefix2(String[] strs) {
        if(strs.length == 0) return "";
        for (int i = 0; i < strs[0].length(); i++) {
           char ch = strs[0].charAt(i);

          for (int j = 0; j < strs.length; j++) {
            if (i>=strs[j].length() || strs[j].charAt(i) != ch) {
                return strs[0].substring(0,i);
            }
          }
        }
        return strs[0];
    }

    public static void main(String[] args) {
        String[] strs = {"flower","flow","flight"};
        System.out.println(longestCommonPrefix2(strs));
    }
}

```
---

> This approach is also known as vertical approach because, the vertical approach compares characters column by column across all strings., first check **f**lower with **f**low and **f**light, then checks the remaining character.

---
### **Time & Space Complexity:-**

- Time:- same as horizontal approach **O(n*m)**.

- Space:- also same as horizontal approach **O(1)**.

---

## ⚙️ **Approach 2 — Optimal Approach**

### **Idea-1:**

Using merge sort:<br>
- it divides the array into two parts **low-mid** & **mid+1-high**
- then checks the prefix using **horizontal approach** first **low-mid** and returns the prefix, then **mid+1-high** and returns the prefix if exist.
- then compare both prefix and returns the final resultant prefix

---

- code:-

```java
public class LongestCommonPrefix {

    public static String longestCommonPrefix3(String[] strs,int low,int high) {
        if(low==high) return strs[low];

        int mid = (low+high)/2;
        String left = longestCommonPrefix3(strs,low,mid);
        String right = longestCommonPrefix3(strs,mid+1,high);
        return commonPrefix(left,right);
    }
    
    public static String commonPrefix(String left,String right){
        int minLen = Math.min(left.length(), right.length());
        int i =0;
        
        while (i<minLen && left.charAt(i) == right.charAt(i)) {
            i++;
        }
        return left.substring(0,i);
        
    }

    public static void main(String[] args) {
        String[] strs = {"flower","flow","flight"};
        System.out.println(longestCommonPrefix3(strs,0,strs.length-1));
    }
}

```

---

### **Time & Space Complexity:-**

- Time:- It uses the divide and conquer technique, which takes **O(log n)** recursive calls.<br>
And then used horizontal approach, takes **O(m)**; where m denotes the size of the prefix.<br>
Total time= **O(log n+m)**

- Space:- it does not required any extra data types so it takes **O(1)** size in memory . Since it uses **merge sort** so considering  **recursion stack** space it takes **O(n)** additional memory; where **n** is s the size of the array.

### **Idea-2:**

Using Binary Search.<br>
- first we find out the **minimum length** string among the array of string.
- set the low=**0** and **high**=**minimum length**.
- find out the **mid** and set the prefix from **0** to **mid**.
-  then check all the string from **0** to **mid**, if not equal to prefix return **false** and change the position of the **high**=**mid-1**.
- if equal to prefix it returns **true** and changes the positon of the **low**=**mid+1**.
- this steps continue until **low>high** and returns the position from **0** to **mid**.

---

- code:-

```java
public class LongestCommonPrefix {

    public static String longestCommonPrefix4(String[] strs) {
        int minLen = strs[0].length();
        for (int i = 1; i < strs.length; i++) {
            minLen = Math.min(minLen, strs[i].length());
        }
        int low = 0, high = minLen;
        while (low<=high) {
            int mid = low+(high+low)/2;
            if (isCommonPrefix(strs,mid)) {
                low = mid + 1;
            }else{
                high = mid-1;
            }
        }
        return strs[0].substring(0,(high+low)/2);
    }

    public static boolean isCommonPrefix(String strs[],int len){
        String prefix = strs[0].substring(0,len);

        for (int i = 1; i < strs.length; i++) {
            if (strs[i].substring(0,len) != prefix) {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) {
        String[] strs = {"flower","flow","flight"};
        System.out.println(longestCommonPrefix4(strs));
    }
}

```

---

### **Time & Space Complexity:-**

- Time:- it uses binary search, takes **O(log n)**.<br>
And takes **O(m)**; where m is the smallest string size at worst case.<br>
Total time= O(log n+m); same as using merge sort.

- Space:- it does not required any extra data types so it takes **O(1)** size in memory. 

---

### **D. Final Note:-**
- Writing multiple approaches helps understand time-space trade-offs.
- Choosing between divide and conquer or binary search depends on your preference — both are optimal in complexity.
