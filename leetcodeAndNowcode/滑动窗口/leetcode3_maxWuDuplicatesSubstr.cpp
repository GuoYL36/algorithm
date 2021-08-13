// leetcode3、无重复字符的最长子串

#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.size();
        unordered_map<char, int> window;
        if(length<=1){
            return length;
        }
        int left=0,right=0;
        int res=0;
        while(right<length){
            char c = s[right];
            
            if(window.count(c)){
                left = max(left, window[c]+1);   // window[c]+1是针对"abca"，max()是针对"abba"
            }
            window[c] = right;
            res = res>(right-left+1)?res:(right-left+1);
            right++;
        }
        return res>(right-left)?res:(right-left);


    }
};



int main(){
    string s = "abba";
    Solution func = Solution();
    int res = func.lengthOfLongestSubstring(s);
    cout<<"res: "<<res<<endl;

    return 1;
}