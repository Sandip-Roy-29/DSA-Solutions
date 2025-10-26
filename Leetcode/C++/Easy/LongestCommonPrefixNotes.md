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
```cpp
#include<bits/stdc++.h>

using namespace std;

string longestCommonPrefix1(vector<string>& strs) {
    string prefix = strs[0];
    for(int i=0; i < strs.size()-1;i++){
        string s1 = prefix;
        string s2 = strs[i+1];
        int j = 0;
        while(j<s1.size() && j<s2.size() && s1[j]==s2[j]){
            j++;
        }
        prefix = s1.substr(0,j);
        if(prefix == "") return "";
    }    
    return prefix;
}

int main(){
    vector<string> strs ={"flower","flow","flight"};
    cout<< longestCommonPrefix1(strs);
    return 0;
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
```cpp
#include<bits/stdc++.h>

using namespace std;

string longestCommonPrefix2(vector<string>& strs) {
    if(strs.empty()) return "";
    for(int i=0; i < strs[0].size();i++){
        char ch = strs[0][i];
        for (size_t j = 1; j < strs.size(); j++)
        {
            if(i>=strs[j].size() || strs[j][i] != ch) return strs[0].substr(0,i);
        }        
    }    
    return strs[0];
}

int main(){
    vector<string> strs ={"flower","flow","flight"};
    cout<< longestCommonPrefix2(strs);
    return 0;
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

```cpp
#include<bits/stdc++.h>

using namespace std;

string commonPrefix(string left, string right){
    int mLength = min(left.size(),right.size());
    int i = 0;

    while(i<=mLength && left[i] == right[i]){
        i++;
    }
    return left.substr(0,i);
}

string longestCommonPrefix3(vector<string>& strs, int low, int high) {
    if(low==high) return strs[low];

    int mid = (low+high)/2;
    string left = longestCommonPrefix3(strs, low, mid);
    string right = longestCommonPrefix3(strs, mid+1, high);
    return commonPrefix(left,right);

}

int main(){
    vector<string> strs ={"flower","flow","flight"};
    cout<< longestCommonPrefix3(strs);
    return 0;
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

```cpp
#include<bits/stdc++.h>

using namespace std;

bool isCommonPrefix(vector<string>& strs,int len){
    string prefix = strs[0].substr(0,len);
    for(int i=1;i<strs.size();i++){
        if(strs[i].substr(0,len) != prefix){
            return false;
        }
    }
    return true;
}

string longestCommonPrefix4(vector<string>& strs) {
    int minLen = strs[0].size();
    int low = 0;
    int high ;
    for(int i=0; i<strs.size()-1;i++){
        minLen = min(minLen,(int)strs[i+1].size());
    }
    high = minLen;

    while(low<=high){
        int mid = low+(high-low)/2;
        if(isCommonPrefix(strs,mid)){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return strs[0].substr(0,(high+low)/2);
}

int main(){
    vector<string> strs ={"flower","flow","flight"};
    cout<< longestCommonPrefix4(strs);
    return 0;
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
