#include<vector>
#include<iostream>
#include<string>
using namespace std;


// 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
// 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

// 输入：n = 12
// 输出：3 
// 解释：12 = 4 + 4 + 4
// 输入：n = 13
// 输出：2
// 解释：13 = 4 + 9


// 思路：
// 假设计算n的最小完全平方数，可以来自于i的最小完全平方数+1：1+f[n-i*i]
// 状态转移:
// 1. 第一步，从1遍历到n，假设为i
// 2. 第二步，遍历 1到 根号i中j，找出满足i-j*j的完全平方数的最小值: tmp = min(tmp, f[i-j*j])
// 3. 第三步，找到第二步中最小值，加1，更新f[i]


class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n+1,0);

        for(int i=1;i<=n;i++){
            int tmp = INT_MAX;
            for(int j=1;j*j<=i;j++){
                tmp = min(tmp, f[i-j*j]);
            }
            f[i] = tmp+1;
        }
        return f[n];
        
    }
};




int main()
{
    int n= 12;
    Solution func = Solution();
    int res = func.numSquares(n);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}




















