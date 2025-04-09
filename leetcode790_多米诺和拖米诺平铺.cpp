#include<vector>
#include<iostream>
#include<string>
using namespace std;

// 有两种形状的瓷砖：一种是 2 x 1 的多米诺形，另一种是形如 "L" 的托米诺形。两种形状都可以旋转。
// 给定整数 n ，返回可以平铺 2 x n 的面板的方法的数量。返回对 109 + 7 取模 的值。
// 平铺指的是每个正方形都必须有瓷砖覆盖。两个平铺不同，当且仅当面板上有四个方向上的相邻单元中的两个，使得恰好有一个平铺有一个瓷砖占据两个正方形。

// 输入: n = 3
// 输出: 5
// 解释: 五种不同的方法如上所示。
// 示例 2:
// 输入: n = 1
// 输出: 1


// 思路：
// 考虑这么一种平铺的方式：在第 i 列前面的正方形都被瓷砖覆盖，在第 i 列后面的正方形都没有被瓷砖覆盖（i 从 1 开始计数）。那么第 i 列的正方形有四种被覆盖的情况：
// （1)第i列中一个正方形都没有被覆盖，记为状态 0；
// （2）第i列中只有上方的正方形被覆盖，记为状态 1；
// （3）第i列中只有下方的正方形被覆盖，记为状态 2；
// （4）第i列中上下两个正方形都被覆盖，记为状态 3。
// 使用 dp[i][s] 表示平铺到第 i 列时，各个状态 s 对应的平铺方法数量,状态转移方程为：
// dp[i][0] = dp[i-1][3]; 第i-1列已经全部有正方形，那只能覆盖 1个多米诺型；
// dp[i][1] = dp[i-1][0] + dp[i-1][2]; dp[i-1][0]——第i-1列没有正方形，那只能覆盖 1个拖米诺型；dp[i-1][2]——第i-1列下方没有正方形，那只能覆盖 1个多米诺型
// dp[i][2] = dp[i-1][0] + dp[i-1][1]; dp[i-1][0]——第i-1列没有正方形，那只能覆盖 1个拖米诺型；dp[i-1][1]——第i-1列上方没有正方形，那只能覆盖 1个多米诺型
// dp[i][3] = dp[i-1][0] + dp[i-1][1]+ dp[i-1][2]+ dp[i-1][3]; dp[i-1][0]——第i-1列没有正方形，那只能覆盖 2个多米诺型；dp[i-1][1]——第i-1列上方没有正方形，那只能覆盖 1个拖米诺型；dp[i-1][2]——第i-1列下方没有正方形，那只能覆盖 1个拖米诺型；dp[i-1][3]——第i-1列下方都有正方形，那只能覆盖 1个多米诺型；


class Solution {
public:
    int numTilings(int n) {
        vector<vector<long long>> dp(n+1, vector<long long>(4));
        dp[0][3] = 1;
        long long mod = 1e9+7;

        for(int i=1;i<=n;i++){
            dp[i][0] = dp[i-1][3];
            dp[i][1] = (dp[i-1][0] + dp[i-1][2])%mod;
            dp[i][2] = (dp[i-1][0] + dp[i-1][1])%mod;
            dp[i][3] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3])%mod;
        }
        return dp[n][3];
    }
};




int main()
{
    int n=3;
    Solution func = Solution();
    int res = func.numTilings(n);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}




















