#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;



// #Leetcode 最长连续序列
// # 描述：给定一个未排序的整数数组，找出最长连续序列的长度
// # 输入: [100, 4, 200, 1, 3, 2]
// # 输出: 最长连续序列是[1,2,3,4]，长度为4.

// # 解法一：先排序后遍历，时间复杂度为o(nlogn)

// #解法二：利用hashmap，时间复杂度为o(n).


class Solution
{
    public:
    int longest_continue_sequence(vector<int>& nums){
        int n = nums.size();
        unordered_set<int> us;
        for(auto x: nums){
            us.emplace(x);
        }
        int max_length = INT_MIN;
        for(int x: us){
            // 只有当x是连续序列起点时才统计
            if(!us.count(x-1)){
                int tmp = 1;
                int k = x;
                while(us.count(++k)){
                    tmp++;
                }
                max_length = max(max_length, tmp);
            }
        }
        return max_length;

    }
}
;

int main()
{
    vector<int> nums={100, 4, 200, 1, 3, 2};
    Solution func = Solution();
    int res = func.longest_continue_sequence(nums);
    cout<<"res: "<<res<<endl;

}





