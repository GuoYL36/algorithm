#include<vector>
#include<iostream>
#include<string>
using namespace std;


// 给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
// 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
// 假设每一种面额的硬币有无限个。 
// 题目数据保证结果符合 32 位带符号整数。
// 输入：coins = [1, 2, 5], amount = 11
// 输出：3 
// 解释：11 = 5 + 5 + 1
// 输入：coins = [2], amount = 3
// 输出：-1
// 输入：coins = [1], amount = 0
// 输出：0
// 提示：
// 1 <= coins.length <= 12
// 1 <= coins[i] <= 231 - 1
// 0 <= amount <= 104

// 思路：
// 由于硬币可以无限选择,定义 dp[i] 为组成金额 i 所需最少的硬币数量
// 所以，第一步，假设金额为 i
// 第二步，遍历硬币数组j,找出所有满足dp[x-coins[j]]的最少硬币个数：dp[i] = min(dp[i], dp[i-coins[j]]+1);



class Solution {
public:
    int coinChange(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<long long> dp(amount+1,INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<n;j++){
                if(i-coins[j]>=0){
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
        }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};




int main()
{
    int amount=11;
    vector<int> coins={1,2,5};
    Solution func = Solution();
    int res = func.coinChange(amount, coins);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}




















