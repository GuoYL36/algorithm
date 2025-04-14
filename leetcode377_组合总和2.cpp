#include<vector>
#include<iostream>
#include<string>
using namespace std;

// 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
// 题目数据保证答案符合 32 位整数范围。
// 输入：nums = [1,2,3], target = 4
// 输出：7
// 解释：
// 所有可能的组合为：
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
// 请注意，顺序不同的序列被视作不同的组合。
// 输入：nums = [9], target = 3
// 输出：0



// 思路：
// 由于不同顺序是不同的组合
// 1、从1遍历到target，计算每种i的组合总和dp[i]
// 2、i的组合可以通过遍历nums中取值x，使得0到i-1中存在k，使得k+x=i，那么组合总和为dp[i] += dp[i-k]



// 进阶：如果给定的数组中含有负数会发生什么？问题会产生何种变化？如果允许负数出现，需要向题目中添加哪些限制条件？
// 答案：
// 如果给定的数组中含有负数，则会导致出现无限长度的排列。
// 例如，假设数组 nums 中含有正整数 a 和负整数 −b（其中 a>0,b>0,−b<0），则有 a×b+(−b)×a=0，对于任意一个元素之和等于 target 的排列，在该排列的后面添加 b 个 a 和 a 个 −b 之后，得到的新排列的元素之和仍然等于 target，而且还可以在新排列的后面继续 b 个 a 和 a 个 −b。因此只要存在元素之和等于 target 的排列，就能构造出无限长度的排列。
// 如果允许负数出现，则必须限制排列的最大长度，避免出现无限长度的排列，才能计算排列数。

class Solution {
public:
    int combinationSum4(int target, vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(target+1,0);
        dp[0] = 1;

        for(int i=1;i<=target;i++){
            for(int j=0;j<n;j++){
                // 这里防止溢出，考虑组合总和最大值为INT_MAX
                if(i-nums[j]>=0 && dp[i-nums[j]]<INT_MAX-dp[i]){
                    dp[i] += dp[i-nums[j]];
                }
                
            }
        }
        return dp[target];
    }
};




int main()
{
    int target=4;
    vector<int> nums={1,2,3};
    Solution func = Solution();
    int res = func.combinationSum4(target, nums);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}




















