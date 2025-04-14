#include<vector>
#include<iostream>
#include<string>
using namespace std;


// 给你一个字符串 s，找到 s 中最长的 回文子串。
// 输入：s = "babad"
// 输出："bab"
// 解释："aba" 同样是符合题意的答案。
// 输入：s = "cbbd"
// 输出："bb"


class Solution {
public:

    string calLength(string s, int m, int n){
        int k = s.size();
        int count = 0;
        bool flag=m==n;
        while(m>=0 && n<k && s[m]==s[n]){
            m--;
            ++n;
            ++count;
        }
        if(count!=0){
            return flag?s.substr(m+1,count*2-1):s.substr(m+1,count*2);
        }
        return s.substr(m,1);
    }

    string longestPalindrome(string s) {

        int k = s.size();
        string res="";
        for(int i=0;i<k;i++){
            string a = calLength(s, i,i);
            string b = calLength(s, i, i+1);
            if((int)a.size()>(int)b.size()){
                res = (int)res.size()>(int)a.size()?res:a;
            }
            else{
                res = (int)res.size()>(int)b.size()?res:b;
            }
        }
        return res;
        
    }
};




int main()
{
    string s = "babad";
    Solution func = Solution();
    string res = func.longestPalindrome(s);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}










