#include<vector>
#include<iostream>
#include<string>
using namespace std;

// 给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
// 子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
// 输入：s = "bbbab"
// 输出：4
// 解释：一个可能的最长回文子序列为 "bbbb" 。
// 输入：s = "cbbd"
// 输出：2
// 解释：一个可能的最长回文子序列为 "bb" 。

// 思路：将字符串反转后，求最长公共子序列

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string s1;
        for(int i=n-1;i>=0;i--){
            s1 += s[i];
        }

        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;++j){
                if(s[i-1]==s1[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
        
    }
};


int main()
{
    string s = "bbbab";
    Solution func = Solution();
    int res = func.longestPalindromeSubseq(s);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}


