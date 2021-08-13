// leetcode567、字符串排列



#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;


class Solution {
public:
    bool check(unordered_map<char,int>m, unordered_map<char,int>n){
        
        for(auto it=m.begin();it != m.end();++it){
            if(n.find(it->first) == n.end() || (n.find(it->first) != n.end() && n[it->first] != it->second)){
                return false;
            }
        }
        return true;    
    }

    bool checkInclusion(string s1, string s2) {
        int length1 = s1.size();
        int length2 = s2.size();
        unordered_map<char, int> um, window;

        
        for(int i=0;i<length1;i++){
            ++um[s1[i]];
        }

        int left=0,right=0;
        bool flag = true;
        while(right<length2){
            ++window[s2[right]];
            if((right-left+1)==length1){
                if(check(um, window)){
                   return true; 
                }
                --window[s2[left]];
                left++;
                
            }
            right++;
        }
        return false;

    }

    // 优化思路：O(|S1|+|S2|+A), |s1| 表示字符串 s1 的长度，这里 |s2| 表示字符串 s2 的长度。A表示字符集，即 s1 和 s2 中出现的所有的字符，A 是字符集的大小，
    bool checkInclusion1(string s1, string s2) {
        int length1 = s1.size(), length2 = s2.size();
        unordered_map<char, int> um;

        for(int i=0;i<length1;i++){
            ++um[s1[i]];
        }
        
        
        int left=0,right=0;
        while(right<length2){
            char c = s2[right];
            right++;
            --um[c];
            while(left<right && um[c]<0){  // 如果没有出现s1中的字符，则直接移动left;
                ++um[s2[left]];
                ++left;
            }
            if((right-left)==length1){    // 当连续出现了s1中字符且长度为length1时，此时um中s1的字符对应的value都为0
                return true;
            }
            right++;
        }
        return false;

    }

};


int main(){
    // string s1="ab",s2="eidbaooo"; // true
    string s1="ab",s2="eidboaoo";  // false

    Solution func = Solution();
    bool flag = func.checkInclusion(s1, s2);
    cout<<flag<<endl;

    return 1;
}


