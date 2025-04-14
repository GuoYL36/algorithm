
#include<vector>
#include<iostream>
#include<string>
using namespace std;

// 给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​
// 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
// 输入: prices = [1,2,3,0,2]
// 输出: 3 
// 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
// 示例 2:
// 输入: prices = [1]
// 输出: 0

// 思路
// 状态定义
// dp[i][0]: 第i天结束时，持有股票时的最大收益。
// dp[i][1]: 第i天结束时，不持有股票且明天不可以购买股票时，最大收益。
// dp[i][2]: 第i天结束时，不持有股票且明天可以购买股票时，最大收益。
// 状态转移方程
// dp[i][0] = max(dp[i-1][0],dp[i-1][2]-prices[i])
// dp[i][1] = dp[i-1][0]+prices[i]
// dp[i][2] = max(dp[i-1][1],dp[i-1][2])



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int a = -prices[0], b=0, c=0;
        for(int i=1;i<n;i++){
            int t_a = max(a, c-prices[i]);
            int t_b = a+prices[i];
            int t_c = max(b, c);
            a = t_a;
            b = t_b;
            c = t_c;
        }
        return max(b, c);
        
    }
};



int main()
{
    vector<int> prices={1,2,3,0,2};
    Solution func = Solution();
    int res = func.maxProfit(prices);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}

















































