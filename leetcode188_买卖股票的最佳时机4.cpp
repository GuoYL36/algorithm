
#include<vector>
#include<iostream>
#include<string>
using namespace std;

// 给你一个整数数组 prices 和一个整数 k ，其中 prices[i] 是某支给定的股票在第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。也就是说，你最多可以买 k 次，卖 k 次。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
// 输入：k = 2, prices = [2,4,1]
// 输出：2
// 解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
// 示例 2：
// 输入：k = 2, prices = [3,2,6,5,0,3]
// 输出：7
// 解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
//      随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。

// 思路:利用长度为k+1的数组来存储 buy和sell状态
// buy[k]是持有第k次交易的股票时（可以是今天买的，也可以是以前买的），获取的最大利益；
// sell[k]是不持有第k次交易的股票时（可以是今天卖的，也可以是以前卖的），获取的最大利益。
    // buy[i] = max(buy[i], sell[i-1]-prices[i])
    // sell[i] = max(sell[i], buy[i]+prices[i])


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int>buy(k+1, INT_MIN), sell(k+1, 0);

        for(auto x: prices){
            for(int i=1; i<=k;i++){
                buy[i] = max(buy[i], sell[i-1]-x);
                sell[i] = max(sell[i], buy[i]+x);
            }
        }
        return sell[k];
    }
};



int main()
{
    vector<int> prices={3,2,6,5,0,3};
    int k=2;
    Solution func = Solution();
    int res = func.maxProfit(k,prices);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}

















































