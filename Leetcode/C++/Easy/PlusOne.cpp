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