
#include<vector>
#include<iostream>
#include<string>
using namespace std;

// 给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。
// 你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
// 返回获得利润的最大值。
// 注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。
// 输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
// 输出：8
// 解释：能够达到的最大利润:  
// 在此处买入 prices[0] = 1
// 在此处卖出 prices[3] = 8
// 在此处买入 prices[4] = 4
// 在此处卖出 prices[5] = 9
// 总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8
// 示例 2：

// 输入：prices = [1,3,7,5,10,3], fee = 3
// 输出：6



// 思路:buy和sell状态
// buy是持有第k次交易的股票时（可以是今天买的，也可以是以前买的），获取的最大利益；
// sell[k]是不持有第k次交易的股票时（可以是今天卖的，也可以是以前卖的），获取的最大利益。
    // buy[i] = max(buy[i], sell[i-1]-prices[i])
    // sell[i] = max(sell[i], buy[i]+prices[i])


class Solution {
public:
    int maxProfit(int fee, vector<int>& prices) {
        int n = prices.size();
        int buy = -prices[0], sell = 0;
        for(int i=1;i<n;i++){
            int t_buy = max(buy, sell-prices[i]);
            int t_sell = max(sell, buy+prices[i]-fee);
            buy = t_buy;
            sell = t_sell;
        }
        return sell;
    }
};



int main()
{
    vector<int> prices={1, 3, 2, 8, 4, 9};
    int fee=2;
    Solution func = Solution();
    int res = func.maxProfit(fee,prices);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}


















































