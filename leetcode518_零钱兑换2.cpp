#include<vector>
#include<iostream>
#include<string>
using namespace std;


// 给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
// 请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
// 假设每一种面额的硬币有无限个。 
// 题目数据保证结果符合 32 位带符号整数。
// 输入：amount = 5, coins = [1, 2, 5]
// 输出：4
// 解释：有四种方式可以凑成总金额：
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1
// 输入：amount = 3, coins = [2]
// 输出：0
// 解释：只用面额 2 的硬币不能凑成总金额 3 。
// 输入：amount = 10, coins = [10] 
// 输出：1
// 提示：
// 1 <= coins.length <= 300
// 1 <= coins[i] <= 5000
// coins 中的所有值 互不相同
// 0 <= amount <= 5000

// 思路：
// 由于硬币可以无限选择
// 所以，第一步，遍历硬币选择 x
// 第二步，遍历x到amount的取值j,累计j-x的所有组合,计算dp[j] += dp[j-x];



class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<uint64_t> dp(amount+1,0);
        dp[0] = 1;
        int n=coins.size();

        for(int i=0;i<n;i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};




int main()
{
    int amount=5;
    vector<int> coins={1,2,5};
    Solution func = Solution();
    int res = func.change(amount, coins);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}




















