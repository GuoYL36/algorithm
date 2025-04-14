#include<vector>
#include<iostream>
#include<string>
using namespace std;


// 给你一个下标从 0 开始的整数数组 nums 和一个整数 target 。
// 返回和为 target 的 nums 子序列中，子序列 长度的最大值 。如果不存在和为 target 的子序列，返回 -1 。
// 子序列 指的是从原数组中删除一些或者不删除任何元素后，剩余元素保持原来的顺序构成的数组。

// 示例 1：
// 输入：nums = [1,2,3,4,5], target = 9
// 输出：3
// 解释：总共有 3 个子序列的和为 9 ：[4,5] ，[1,3,5] 和 [2,3,4] 。最长的子序列是 [1,3,5] 和 [2,3,4] 。所以答案为 3 。
// 示例 2：
// 输入：nums = [4,1,3,2,1,5], target = 7
// 输出：4
// 解释：总共有 5 个子序列的和为 7 ：[4,3] ，[4,1,2] ，[4,2,1] ，[1,1,5] 和 [1,3,2,1] 。最长子序列为 [1,3,2,1] 。所以答案为 4 。
// 示例 3：
// 输入：nums = [1,1,5,4,5], target = 3
// 输出：-1
// 解释：无法得到和为 3 的子序列。

// 思路：
// 因为是求子序列的最大长度，所以状态转移方程为 dp[j] = max(dp[j], dp[j-nums[i]]+1)的长度最大值
// 首先，外层循环遍历数组nums，假设当前为nums[i]，遍历时累加子序列的和
// 然后，内存循环从当前和一直遍历到nums[i]，假设为j，计算新增nums[i]后，所有满足j-nums[i]的长度最大值



class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1, INT_MIN);
        dp[0] = 0;
        int res = 0;
        for(int i=0;i<n;i++){
            res = min(target, res+nums[i]);
            for(int j=res;j>=nums[i];j--){
                dp[j] = max(dp[j], dp[j-nums[i]]+1);
            }
        }

        return dp[target]<=0?-1:dp[target];
    }
};




int main()
{
    vector<int> nums={1,2,3,4,5};
    int target=9;
    Solution func = Solution();
    int res = func.lengthOfLongestSubsequence(nums, target);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}




















