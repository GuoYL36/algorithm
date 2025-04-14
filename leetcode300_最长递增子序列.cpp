#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

// 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
// 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
// 输入：nums = [10,9,2,5,3,7,101,18]
// 输出：4
// 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
// 输入：nums = [0,1,0,3,2,3]
// 输出：4
// 输入：nums = [7,7,7,7,7,7,7]
// 输出：1


// 思路一：O(n*n)时间复杂度
// 1、所有元素初始化最长递增子序列长度为1
// 2、基于当前位置，遍历之前的位置，找出所有小于当前位置元素的索引，从这些中找出最长递增子序列长度，再加1 即为当前位置的最长递增子序列长度

// 思路二：O(nlogn)时间复杂度，用一个数组来存储递增子序列，让这个数组尽可能增长得慢
// 用一个数组dp来存储递增子序列
// 1、如果当前值大于数组最后一个元素，则添加进dp；否则，二分查找dp，找到第一个小于当前值的索引i，并更新dp[i+1]为当前值
// 2、


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // O(n*n)时间复杂度
        // int n = nums.size();
        // vector<int> dp(n, 1);
        // for(int i=1;i<n;++i){
        //     int tmp = 0;
        //     for(int j=0;j<i;++j){
        //         if(nums[i]>nums[j]){
        //             tmp = max(tmp, dp[j]+1);
        //         }
        //     }
        //     dp[i] = max(tmp,dp[i]);
        // }
        // return *max_element(dp.begin(),dp.end());

        // O(nlogn)时间复杂度
        int n = nums.size();
        vector<int> dp(n+1,0);
        int len = 1;
        dp[len] = nums[0];
        for(int i=1;i<n;++i){
            if(nums[i]>dp[len]){
                dp[++len] = nums[i];
            }
            else{
                int l=1, r=len, k=0; // 设置k=0，表示如果找不到，则需要更新dp[1]
                while(l<=r){
                    int mid = (l+r) >> 1;
                    if(dp[mid]<nums[i]){
                        k = mid;
                        l = mid+1;
                    }
                    else{
                        r = mid-1;
                    }
                }
                dp[k+1] = nums[i];
            }
        }
        return len;

    }
};



int main()
{
    vector<int> nums = {10,9,2,5,3,7,101,18};
    Solution func = Solution();
    int res = func.lengthOfLIS(nums);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}















