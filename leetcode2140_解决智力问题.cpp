#include<vector>
#include<iostream>
#include<string>
using namespace std;

// 给你一个下标从 0 开始的二维整数数组 questions ，其中 questions[i] = [pointsi, brainpoweri] 。
// 这个数组表示一场考试里的一系列题目，你需要 按顺序 （也就是从问题 0 开始依次解决），针对每个问题选择 解决 或者 跳过 操作。解决问题 i 将让你 获得  pointsi 的分数，但是你将 无法 解决接下来的 brainpoweri 个问题（即只能跳过接下来的 brainpoweri 个问题）。如果你跳过问题 i ，你可以对下一个问题决定使用哪种操作。
// 比方说，给你 questions = [[3, 2], [4, 3], [4, 4], [2, 5]] ：
// 如果问题 0 被解决了， 那么你可以获得 3 分，但你不能解决问题 1 和 2 。
// 如果你跳过问题 0 ，且解决问题 1 ，你将获得 4 分但是不能解决问题 2 和 3 。
// 请你返回这场考试里你能获得的 最高 分数。

// 输入：questions = [[3,2],[4,3],[4,4],[2,5]]
// 输出：5
// 解释：解决问题 0 和 3 得到最高分。
// - 解决问题 0 ：获得 3 分，但接下来 2 个问题都不能解决。
// - 不能解决问题 1 和 2
// - 解决问题 3 ：获得 2 分
// 总得分为：3 + 2 = 5 。没有别的办法获得 5 分或者多于 5 分。

// 输入：questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
// 输出：7
// 解释：解决问题 1 和 4 得到最高分。
// - 跳过问题 0
// - 解决问题 1 ：获得 2 分，但接下来 2 个问题都不能解决。
// - 不能解决问题 2 和 3
// - 解决问题 4 ：获得 5 分
// 总得分为：2 + 5 = 7 。没有别的办法获得 7 分或者多于 7 分。

// 思路一：时间复杂度O(n*n)
// 用 dp[i] 来表示解决前 i 道题目可以获得的最高分数。根据是否选择解决第 i 道题目，会有以下两种情况：
// 1. 不解决第 i 道题目，此时 dp[i]=dp[i−1]；
// 2.解决第 i 道题目，此时要么前面的题目都未解决，要么上一道解决的题目对应的冷冻期已经结束。具体而言：dp[i] = questions[i][0]+max(0, 从0遍历到i-1，并且取值j+questions[i][1]<i中找出dp[j])

// 思路二：时间复杂度O(n)
// 我们用 dp[i] 来表示解决第 i 道题目及以后的题目可以获得的最高分数。同时，我们从后往前遍历题目，并更新 dp 数组。类似地，根据是否选择解决第 i 道题目，会有以下两种情况：
// 1. 不解决第 i 道题目，此时 dp[i]=dp[i+1]；
// 2. 解决第 i 道题目，我们只能解决下标大于 i+brainpower[i] 的题目，而此时根据 dp 数组的定义，解决这些题目的最高分数为 dp[i+brainpower[i]+1]（当 i≥n 的情况下，我们认为 dp[i]=0）。因此，我们有：
// dp[i]=points[i]+dp[i+brainpower[i]+1].
// 综合上述两种情况，我们就得出了 dp[i] 的状态转移方程：
// dp[i]=max(dp[i+1],points[i]+dp[i+brainpower[i]+1]).
// 在实际计算中，考虑到 i≥n 的边界条件，我们在定义 dp 数组时，可以预留 dp[n]=0 用来表示没有做任何题目的分数。那么上面的转移方程变为：
// dp[i]=max(dp[i+1],points[i]+dp[min(n,i+brainpower[i]+1)]).
// 最终，dp[0] 即为考试中可以获得的最高分数，我们返回该数值作为答案。




class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n+1);

        for(int i=n-1;i>=0;i--){
            dp[i] = max(dp[i+1], questions[i][0]+dp[min(n, i+questions[i][1]+1)]);
        }
        return dp[0];
        
    }
};


int main()
{
    vector<vector<int>> questions={{3,2},{4,3},{4,4},{2,5}};
    Solution func = Solution();
    long long res = func.mostPoints(questions);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}




































