#include<vector>
#include<iostream>
#include<string>
using namespace std;

// 在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行。在接下来的一年里，你要旅行的日子将以一个名为 days 的数组给出。每一项是一个从 1 到 365 的整数。
// 火车票有 三种不同的销售方式 ：
// 一张 为期一天 的通行证售价为 costs[0] 美元；
// 一张 为期七天 的通行证售价为 costs[1] 美元；
// 一张 为期三十天 的通行证售价为 costs[2] 美元。
// 通行证允许数天无限制的旅行。 例如，如果我们在第 2 天获得一张 为期 7 天 的通行证，那么我们可以连着旅行 7 天：第 2 天、第 3 天、第 4 天、第 5 天、第 6 天、第 7 天和第 8 天。
// 返回 你想要完成在给定的列表 days 中列出的每一天的旅行所需要的最低消费 。
// 示例 1：
// 输入：days = [1,4,6,7,8,20], costs = [2,7,15]
// 输出：11
// 解释： 
// 例如，这里有一种购买通行证的方法，可以让你完成你的旅行计划：
// 在第 1 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 1 天生效。
// 在第 3 天，你花了 costs[1] = $7 买了一张为期 7 天的通行证，它将在第 3, 4, ..., 9 天生效。
// 在第 20 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 20 天生效。
// 你总共花了 $11，并完成了你计划的每一天旅行。
// 示例 2：
// 输入：days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
// 输出：17
// 解释：
// 例如，这里有一种购买通行证的方法，可以让你完成你的旅行计划： 
// 在第 1 天，你花了 costs[2] = $15 买了一张为期 30 天的通行证，它将在第 1, 2, ..., 30 天生效。
// 在第 31 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 31 天生效。 
// 你总共花了 $17，并完成了你计划的每一天旅行。
// 提示：
// 1 <= days.length <= 365
// 1 <= days[i] <= 365
// days 按顺序严格递增
// costs.length == 3
// 1 <= costs[i] <= 1000


// 思路：
// dp[i]表示第i天旅游的情况下，[1,i]这段日子的最小花费。在这个定义下，答案就应该是dp[days.back()]。
// 首先没开始的时候肯定不花钱，dp[0]=0。令j=0指向数组days的首元素，如果第i天不旅游，状态转移方程即为dp[i]=dp[i−1]。
// 如果i=days[j]，那为了保证第i天旅游，有三种选择策略。状态转移方程为dp[i]=min(dp[max(0,i−1)]+costs[0],dp[max(0,i−7)]+costs[1],dp[max(0,i−30)]+costs[2])，分别表示选择1、7、30天有效期的策略，选择最小的转移，转移完记得让j右移。
// 事实上，我们也不是非要DP到第365天，当j≥n（n为days的长度）时就可以停止DP过程了，因为最后一个需要旅行的日子已经安排完了。


class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(366, 0);
        dp[0] = 0;
        for(int i=1, j=0;i<=365&& j<n;i++){
            dp[i] = dp[i-1];
            if(i == days[j]){
                dp[i] = dp[max(0, i-1)]+costs[0];
                dp[i] = min(dp[i], dp[max(0, i-7)]+costs[1]);
                dp[i] = min(dp[i], dp[max(0, i-30)]+costs[2]);
                j++;
            }
        }

        return dp[days.back()];
    }
};




int main()
{
    vector<int> days={1,4,6,7,8,20}, costs={2,7,15};
    Solution func = Solution();
    int res = func.mincostTickets(days, costs);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}




















