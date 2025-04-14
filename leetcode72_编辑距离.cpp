#include<vector>
#include<iostream>
#include<string>
using namespace std;

// 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

// 你可以对一个单词进行如下三种操作：

// 插入一个字符
// 删除一个字符
// 替换一个字符

// 输入：word1 = "horse", word2 = "ros"
// 输出：3
// 解释：
// horse -> rorse (将 'h' 替换为 'r')
// rorse -> rose (删除 'r')
// rose -> ros (删除 'e')

// 输入：word1 = "intention", word2 = "execution"
// 输出：5
// 解释：
// intention -> inention (删除 't')
// inention -> enention (将 'i' 替换为 'e')
// enention -> exention (将 'n' 替换为 'x')
// exention -> exection (将 'n' 替换为 'c')
// exection -> execution (插入 'u')



class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if(m*n==0){
            return n + m;
        }

        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            dp[i][0] = i;
        }
        for(int i=1;i<=n;i++){
            dp[0][i] = i;
        }
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                int ins = dp[i][j-1]+1;
                int del = dp[i-1][j]+1;
                int rep = dp[i-1][j-1];
                if(word1[i-1]!=word2[j-1]){
                    rep++;
                }
                dp[i][j]=min(ins, min(del, rep));
            }
        }
        return dp[m][n];
    }
};



int main()
{
    string word1 = "horse";
    string word2 = "ros";
    Solution func = Solution();
    int res = func.minDistance(word1,word2);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}





