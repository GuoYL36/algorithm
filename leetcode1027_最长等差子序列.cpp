#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

// 给你一个整数数组 nums，返回 nums 中最长等差子序列的长度。
// 回想一下，nums 的子序列是一个列表 nums[i1], nums[i2], ..., nums[ik] ，且 0 <= i1 < i2 < ... < ik <= nums.length - 1。并且如果 seq[i+1] - seq[i]( 0 <= i < seq.length - 1) 的值都相同，那么序列 seq 是等差的。
// 输入：nums = [3,6,9,12]
// 输出：4
// 解释： 
// 整个数组是公差为 3 的等差数列。
// 示例 2：

// 输入：nums = [9,4,7,2,10]
// 输出：3
// 解释：
// 最长的等差子序列是 [4,7,10]。
// 示例 3：

// 输入：nums = [20,1,15,3,10,5,8]
// 输出：4
// 解释：
// 最长的等差子序列是 [20,15,10,5]。

// 思路一：
// 状态定义：dp[i][d]表示以nums[i]结尾且公差为d的数列长度。
// 状态转移：对于nums[i]，可以枚举它的前一项nums[j]，0<= j < i，有了前一项nums[j]，其实公差就确定了d=nums[i]-nums[j]。
// 如果nums[j]可以是某个公差为d的数列的最后一项，nums[i]就可以接在后面形成更长的等差数列，状态转移方程为dp[i][d]=dp[j][d]+1
// 否则它两就形成公差为d的等差数列前两项，状态转移方程为dp[i][d]=2。
// 初始化dp[0][d]=1，-500<=d<=500，表示第一项可以属于任意公差的等差数列。



class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n= nums.size();
        int max_val = *max_element(nums.begin(),nums.end());
        int min_val = *min_element(nums.begin(),nums.end());
        int d = max_val-min_val;
        int res = INT_MIN;
        for(int i=-d;i<=d;i++){
            unordered_map<int, int> um;
            for(int j=0;j<n;j++){
                um[nums[j]] = um[nums[j]-i]+1;
                res = max(res, um[nums[j]]);
            }

        }
        return res;
    }
};


int main()
{
    vector<int> nums = {1,3,5,7};
    Solution func = Solution();
    int res = func.longestArithSeqLength(nums);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}











