// leetcode159、至多包含两个不同字符的最长子串

// 描述：给定一个字符串 s ，找出 至多 包含两个不同字符的最长子串 t 
// 示例：
// 输入: “eceba” 输出: 3  解释: t 是 “ece”，长度为3。

// 例 2: 输入: “ccaabbb”  输出: 5  解释: t 是 “aabbb”，长度为5。

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution{
public:
    string findLongSubstr(string s){
        int length = s.size();
        if(length<=1){
            return s;
        }
        unordered_map<char, int> w;
        int left=0,right=0;
        int res=-1, start = -1;
        while(right<length){
            char c = s[right];
            ++w[c];

            while(w.size()>2){
                --w[s[left]];
                if(w[s[left]]==0){
                    w.erase(s[left]);
                }
                left++;
            }
            if((right-left+1)>res){
                res = right-left+1;
                start = left;
            }
            right++;
        }


        return start==-1?"":s.substr(start, res);

    }
};

int main(){
    // string s = "eceba";  // "ece"
    string s = "ccaabbb";  // "aabbb"
    Solution func = Solution();
    string res = func.findLongSubstr(s);
    cout<<"res: "<<res<<endl;

    return 1;
}