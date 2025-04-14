#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


// 给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数，结果需要对 109 + 7 取模。
// 输入：s = "rabbbit", t = "rabbit"
// 输出：3
// 解释：
// 如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
// rabbbit
// rabbbit
// rabbbit

// 输入：s = "babgbag", t = "bag"
// 输出：5
// 解释：
// 如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag

// 其中 dp[i][j] 表示在 s[i:] 的子序列中 t[j:] 出现的个数。上述表示中，s[i:] 表示 s 从下标 i 到末尾的子字符串，t[j:] 表示 t 从下标 j 到末尾的子字符串。
// 考虑动态规划的边界情况：
// 当 j=n 时，t[j:] 为空字符串，由于空字符串是任何字符串的子序列，因此对任意 0≤i≤m，有 dp[i][n]=1；
// 当 i=m 且 j<n 时，s[i:] 为空字符串，t[j:] 为非空字符串，由于非空字符串不是空字符串的子序列，因此对任意 0≤j<n，有 dp[m][j]=0。
// 当 i<m 且 j<n 时，考虑 dp[i][j] 的计算：
// 当 s[i]=t[j] 时，dp[i][j] 由两部分组成：
//     如果 s[i] 和 t[j] 匹配，则考虑 t[j+1:] 作为 s[i+1:] 的子序列，子序列数为 dp[i+1][j+1]；
//     如果 s[i] 不和 t[j] 匹配，则考虑 t[j:] 作为 s[i+1:] 的子序列，子序列数为 dp[i+1][j]。
//     因此当 s[i]=t[j] 时，有 dp[i][j]=dp[i+1][j+1]+dp[i+1][j]。
// 当 s[i]=t[j] 时，s[i] 不能和 t[j] 匹配，因此只考虑 t[j:] 作为 s[i+1:] 的子序列，子序列数为 dp[i+1][j]。
//     因此当 s[i]=t[j] 时，有 dp[i][j]=dp[i+1][j]。

// 计算得到 dp[0][0] 即为在 s 的子序列中 t 出现的个数。



class Solution {
public:
    int numDistinct(string s, string t) {
        int m=s.size(), n=t.size();
        if(m<n){
            return 0;
        }
        vector<vector<unsigned long long>> dp(m+1, vector<unsigned long long>(n+1,0));
        // 如果t是空字符
        for(int i=0;i<=m;i++){
            dp[i][n] = 1;
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(s[i]==t[j]){
                    dp[i][j] = dp[i+1][j+1]+dp[i+1][j];
                }
                else{
                    dp[i][j] = dp[i+1][j];
                }

            }
        }
        return dp[0][0];
        
    }
};



int main()
{
    string word1 = "babgbag";
    string word2 = "bag";
    Solution func = Solution();
    int res = func.numDistinct(word1,word2);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}























