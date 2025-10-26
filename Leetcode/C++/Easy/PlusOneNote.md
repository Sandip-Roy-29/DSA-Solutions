# 🧠 LeetCode Notes by **Sandip Roy**

## 🧩 Problem: *[66. Plus One]*

### **A. Problem Restatement:-**

The problem asks me to increase the Integer which is represented by the **digits** array by **1** and return the resultant value as a **digits** array .

### **B. Example:-**

| Input | Output | Explanation |
|--------|---------|-------------|
| `[1,2,3]` | `[1,2,4]` | 123 + 1 = 124 |
| `[9]` | `[1,0]` | 9 + 1 = 10 |

### **C. constraints:-**

- Length of the array must be between **1** to **100**
- Each element represents a single digits
- Integer has no leading **0**

## ⚙️ **Approach 1 — Brute Force**

### **Idea:**
Convert the **digits** array into an **Integer**, add **1**, then convert the resultant Integer back into array, and return it.

---

- Code:-
```cpp
#include<bits/stdc++.h>

using namespace std;

vector<int> plusOne(vector<int>& digits){
    int num = 0;
    vector<int> temp ;

    for(int i=0; i<digits.size();i++){
        num = num*10+digits[i];
    }

    num ++;

    if(num == 0) {
        temp.push_back(num);
        return temp;
    }

    while(num>0){
        temp.push_back(num%10);
        num = num/10;
    }

    reverse(temp.begin(),temp.end());
    
    return temp;
}

int main(){
    vector<int> digits = {4,3,2,1};
    vector<int> temp = plusOne(digits);
    for(int digits : temp){
        cout<<digits;
    }
    return 0;
}
```
---

> if the digit array is very larg (as per constrain e.g. **100**) then not **Int** and nor **long** or **any data type** can not hold it, Integer overflow happed . That's why this approach failed for long Input value.

---
### **Time & Space Complexity:-**

- Time:- convert the **digits** array to **Integer** takes **O(n)**; where n is the size of the digit array.<br>
convert the resultant **Integer** to a **digits** array takes **O(m)**; where m is the size of the resultant Integer.<br>
Total time = **O(n+m)**.

- Space:- Convert the resultant **Integer** into an **array** takes **O(n)**.

---

## ⚙️ **Approach 2 — Better Approach**

There is no better approach because any better approach would need take less than **O(n)>time** means either **O(log n)** or **O(1)**, Which is not possible in this case. because considering the worst case we have to traverse the full array.<br>

Example:- **Input**: [9,9,9] **Output**: [1,0,0,0]

---

## ⚙️ **Approach 3 — Optimal Approach**

If we use an in-place algorithm, we can solve this problem in O(n) time and O(1) space (except when all digits are 9, which requires O(m)).<br>

### **Idea:**

- we start traversing from right to left.
- if the right most element is less than **9** we simply increment the value by **1** and return the array.
- Otherwise, we set it to **0** and carry **1** to the next digit on the left.
-  if it reaches the left most element and still have carry **1**. we expand the size of the array and insert a new digit(1) it at the beginning using new array.

---

- code:-

```cpp
#include<bits/stdc++.h>

using namespace std;

vector<int> plusOne2(vector<int>& digits){
    
for(int i = digits.size(); i>0; i--){
    if(digits[i-1]<9){
        digits[i-1]++;
        return digits;
    } else{
        digits[i-1] = 0;
    }
}
digits.insert(digits.begin(),1);

return digits;
}

int main(){
    vector<int> digits = {4,3,2,1};
    vector<int> temp = plusOne2(digits);
    for(int digits : temp){
        cout<<digits;
    }
    return 0;
}
```

---

### **Time & Space Complexity:-**

- Time:- in worst cases it travers all the array so it takes **O(n)** time<br>

- Space:- in ength; where **n** is the size of the input array. so it takes **O(m)** size ; where **m** is the size of the resultant array.the worst case it create a new array with **n+1** l
> O(1) for most cases (in-place updates).O(m) only when a new digit is added (e.g., [9,9,9] → [1,0,0,0])

---

### **D. Final Note:-**
- Always consider integer overflow when converting arrays to integers.
- In-place operations are memory-efficient.
- Carry propagation is the key idea.
- Space is O(1) unless an extra digit is needed.
- Writing multiple approaches helps understand time-space trade-offs.
