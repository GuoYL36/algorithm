
#include<vector>
#include<iostream>
#include<string>
using namespace std;

// 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

// 输入：prices = [3,3,5,0,0,3,1,4]
// 输出：6
// 解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
//      随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
// 输入：prices = [1,2,3,4,5]
// 输出：4
// 解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
//     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
//     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
// 输入：prices = [7,6,4,3,1] 
// 输出：0 
// 解释：在这个情况下, 没有交易完成, 所以最大利润为 0。
// 输入：prices = [1]
// 输出：0

// 思路
// 状态：
// 未进行过任何操作: buy0；-- 一直不买收益都是0
// 只进行过一次买操作： buy1；
// 进行了一次买操作和一次卖操作，即完成了一笔交易： sell1；
// 在完成了一笔交易的前提下，进行了第二次买操作： buy2；
// 完成了全部两笔交易： sell2。
// // 转移方程：
// buy1 = max(buy1, buy0-prices[i]);
// sell1 = max(sell1, buy1+prices[i]);
// buy2 = max(buy2, sell1-prices[i]);
// sell2 = max(sell2, buy2+prices[i]);
// 初始状态: buy2即为在同一天买入并且卖出后再以 prices[0] 的价格买入股票，
// buy0=0、buy1=-prices[0]、sell1=0、buy2=-prices[0]、sell2=0；


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy1=-prices[0], sell1=0, buy2=-prices[0], sell2=0;
        for(int i=1;i<n;i++){
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1+prices[i]);
            buy2 = max(buy2, sell1-prices[i]);
            sell2 = max(sell2, buy2+prices[i]);
        }
        return sell2; //如果是只有一次买卖就能获取最大收益，则sell1能转换为sell2，因为buy2初始化与buy1一样，相当于已经买卖过一次了
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

















































