#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


// 给你一个由 n 个数对组成的数对数组 pairs ，其中 pairs[i] = [lefti, righti] 且 lefti < righti 。
// 现在，我们定义一种 跟随 关系，当且仅当 b < c 时，数对 p2 = [c, d] 才可以跟在 p1 = [a, b] 后面。我们用这种形式来构造 数对链 。
// 找出并返回能够形成的 最长数对链的长度 。
// 你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。
// 输入：pairs = [[1,2], [2,3], [3,4]]
// 输出：2
// 解释：最长的数对链是 [1,2] -> [3,4] 。

// 输入：pairs = [[1,2],[7,8],[4,5]]
// 输出：3
// 解释：最长的数对链是 [1,2] -> [4,5] -> [7,8] 。
// n == pairs.length
// 1 <= n <= 1000
// -1000 <= lefti < righti <= 1000

// 思路一：时间复杂度o(n2)
// 1. 利用一个dp数组来记录到当前位置的最大长度，首先初始化为1，因为自身就是一个对链
// 2. 假设当前位置为i，则遍历0到i-1上能与当前位置构成对链的长度：dp[i] = max(dp[i], dp[j]+1)

// 思路二：时间复杂度o(nlogn)
// 1. 用一个数组arr来存储最长对链，每次只存对链(a,b)中的b
// 2. 假设当前位置为i，则利用二分查找arr中位置j的值，该值要比i的值大，则用i的值替换j的值



class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b){return a[0]<b[0];});
        // 思路一
        // int n = pairs.size();
        // vector<int> dp(n,1);
        // for(int i=1;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         if(pairs[i][0] > pairs[j][1]){
        //             dp[i] = max(dp[i], dp[j]+1);
        //         }
        //     }
        // }
        // return *max_element(dp.begin(), dp.end());  

        //思路二
        vector<int> arr;
        for(auto x: pairs){
            int a = x[0], b=x[1];
            if((int)arr.size()==0 || a>arr.back()){
                arr.emplace_back(b);
            }
            else{
                int idx = lower_bound(arr.begin(), arr.end(), a)-arr.begin();
                arr[idx] = min(b, arr[idx]);
            }
        }
        return arr.size();

    }
};




int main()
{
    vector<vector<int>> nums = {{1,2}, {7,8}, {4,5}};
    Solution func = Solution();
    int res = func.findLongestChain(nums);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}











