#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

// 给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。
// 注意 这个数列必须是 严格 递增的。
// 输入: [1,3,5,4,7]
// 输出: 2
// 解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
// 输入: [2,2,2,2,2]
// 输出: 5
// 解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。


// 思路一：O(n*n)时间复杂度
// 1、所有元素初始化最长递增子序列长度为1
// 2、基于当前位置，遍历之前的位置，找出所有小于当前位置元素的索引，从这些中找出最长递增子序列长度，再加1 即为当前位置的最长递增子序列长度


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        // O(n*n)时间复杂度
        int n = nums.size();
        vector<int> dp(n), dp_c(n);
        int max_len = INT_MIN, max_c = 0;
        for(int i=0;i<n;++i){
            dp_c[i] = 1;
            dp[i] = 1;
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j]){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j]+1;
                        dp_c[i] = dp_c[j];
                    }
                    else if(dp[j]+1 == dp[i])
                    {
                        dp_c[i] += dp_c[j];
                    }
                }
            }
            if(max_len < dp[i]){
                max_len = dp[i];
                max_c = dp_c[i];
            }
            else if(max_len == dp[i]){
                max_c += dp_c[i];
            }

        }
        return max_c;

        

    }
};



int main()
{
    vector<int> nums = {10,9,2,5,3,7,101,18};
    Solution func = Solution();
    int res = func.findNumberOfLIS(nums);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}















