
#include<vector>
#include<iostream>
#include<string>
using namespace std;

// 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
// 在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
// 返回 你能获得的 最大 利润 。
// 输入：prices = [7,1,5,3,6,4]
// 输出：7
// 解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
// 随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3。
// 最大总利润为 4 + 3 = 7 。
// 输入：prices = [1,2,3,4,5]
// 输出：4
// 解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
// 最大总利润为 4 。
// 示例 3：
// 输入：prices = [7,6,4,3,1]
// 输出：0
// 解释：在这种情况下, 交易无法获得正利润，所以不参与交易可以获得最大利润，最大利润为 0。


// 思路
// 状态转移方程
// 状态 dp[i][0] 表示第 i 天交易完后手里没有股票的最大利润
// dp[i][1] 表示第 i 天交易完后手里持有一支股票的最大利润（i 从 0 开始）
// dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
// dp[i][1] = max(dp[i-1][0]-prices[i], dp[i-1][1]);



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<int> dp(n, 0);
        // int res = INT_MIN;
        // for(int i=1;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         if(prices[i] > prices[j]){
        //             dp[i] = max(dp[i], *max_element(dp.begin(), dp.begin()+j)+prices[i]-prices[j]);
        //         }
        //     }
        //     res = max(res, dp[i]);
        // }
        // return res==INT_MIN?0:res;

        int n = prices.size();
        int a = 0, b=-prices[0];
        for(int i=1;i<n;i++){
            int t_a = max(a, b+prices[i]);
            int t_b = max(a-prices[i], b); 
            a = t_a;
            b = t_b;
        }
        return a;
        
    }
};



int main()
{
    vector<int> prices={7,1,5,3,6,4};
    Solution func = Solution();
    int res = func.maxProfit(prices);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}

















































