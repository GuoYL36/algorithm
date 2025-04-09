#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


// 给你一个整数数组 nums ，你可以对它进行一些操作。
// 每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。
// 开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。

// 输入：nums = [3,4,2]
// 输出：6
// 解释：
// 删除 4 获得 4 个点数，因此 3 也被删除。
// 之后，删除 2 获得 2 个点数。总共获得 6 个点数。

// 输入：nums = [2,2,3,3,3,4]
// 输出：9
// 解释：
// 删除 3 获得 3 个点数，接着要删除两个 2 和 4 。
// 之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
// 总共获得 9 个点数。


// 思路：
// 1、将每个值作为key，将所有相同key累加作为value
// 2、打家劫舍思路，相邻两间房屋不能同时被偷

class Solution {
public:
    

    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        int k = *max_element(nums.begin(), nums.end());
        vector<int> res(k+1, 0);
        for(int i=0;i<n;i++){
            res[nums[i]] += nums[i];
        }

        // 打家劫舍
        int a = res[0], b = max(res[0],res[1]);
        for(int i=2;i<=k;++i){
            int t = b;
            b = max(res[i]+a, b);
            a = t;
        }
        return b;
    }
};




int main()
{
    vector<int> nums = {3,4,2};
    Solution func = Solution();
    int res = func.deleteAndEarn(nums);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}














