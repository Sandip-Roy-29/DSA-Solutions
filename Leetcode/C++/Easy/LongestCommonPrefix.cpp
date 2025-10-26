#include<bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string prefix = strs[0];
    for(int i=0; i < strs.size()-1;i++){
        string s1 = prefix;
        string s2 = strs[i+1];
        int j = 0;
        while(j<s1.size() && j<s2.size() && s1[j]==s2[j]){
            j++;
        }
        prefix = s1.substr(0,j);
        if(prefix == " ") return "";
    }    
    return prefix;
}

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
    cout<< longestCommonPrefix(strs);
    cout<< longestCommonPrefix2(strs);
    cout<< longestCommonPrefix3(strs,0,strs.size()-1);
    cout<< longestCommonPrefix4(strs);
    return 0;
}