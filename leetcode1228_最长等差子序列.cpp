#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

// 给你一个整数数组 arr 和一个整数 difference，请你找出并返回 arr 中最长等差子序列的长度，该子序列中相邻元素之间的差等于 difference 。

// 子序列 是指在不改变其余元素顺序的情况下，通过删除一些元素或不删除任何元素而从 arr 派生出来的序列。

// 输入：arr = [1,2,3,4], difference = 1
// 输出：4
// 解释：最长的等差子序列是 [1,2,3,4]。
// 示例 2：
// 输入：arr = [1,3,5,7], difference = 1
// 输出：1
// 解释：最长的等差子序列是任意单个元素。
// 示例 3：
// 输入：arr = [1,5,7,8,5,3,4,2,1], difference = -2
// 输出：4
// 解释：最长的等差子序列是 [7,5,3,1]。


// 思路二
// 我们从左往右遍历 arr，并计算出以 arr[i] 为结尾的最长的等差子序列的长度，取所有长度的最大值，即为答案。
// 令 dp[i] 表示以 arr[i] 为结尾的最长的等差子序列的长度，我们可以在 arr[i] 左侧找到满足 arr[j]=arr[i]−d 的元素，将 arr[i] 加到以 arr[j] 为结尾的最长的等差子序列的末尾，这样可以递推地从 dp[j] 计算出 dp[i]。
// 由于我们是从左往右遍历 arr 的，对于两个相同的元素，下标较大的元素对应的 dp 值不会小于下标较小的元素对应的 dp 值，因此下标 j 可以取满足 j<i 且 arr[j]=arr[i]−d 的所有下标的最大值



class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // 思路一
        // int n=arr.size();
        // vector<int> dp(n,1);
        // for(int i=1;i<n;++i){
        //     for(int j=0;j<i;++j){
        //         if(arr[i]-arr[j] == difference){
        //             dp[i] = max(dp[i], dp[j]+1);
        //         }
        //     }
        // }
        // return *max_element(dp.begin(), dp.end());

        // 思路二
        int n=arr.size();
        unordered_map<int, int> um;
        int ans = INT_MIN;
        for(auto x: arr){
            um[x] = um[x-difference] + 1;
            ans = max(ans, um[x]);
        }
        return ans;

    }
};


int main()
{
    vector<int> nums = {1,3,5,7};
    int diff = 2;
    Solution func = Solution();
    int res = func.longestSubsequence(nums,diff);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}











