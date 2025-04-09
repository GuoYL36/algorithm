#include<vector>
#include<iostream>
#include<string>
using namespace std;


// 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
// 输入：n = 3
// 输出：5
// 示例 2：

// 输入：n = 1
// 输出：1


// 思路
//  对于BST 递归满足: 左子树<根节点<右子树
// 在1~n中 任取一个数i作为根节点 则i为根节点的BST数量为节点为1~(i-1)的BST数量(左子树) * 节点为(i+1)~n的BST数量(右子树)
// 又因为 由节点(i+1)~n构成的BST数量可以等价为由节点1~(n-i)构成的BST数量
// 显而易见 计算当前结果用到了之前的结果 并且满足同样的性质 DP求解
// 因此定义dp[i]为节点1~i构成的BST数量
// dp[n] = dp[i-1]*dp[n-i], i=1, 2, ..., n
// dp[0] = dp[1] = 1


class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};



int main()
{
    int n= 3;
    Solution func = Solution();
    int res = func.numTrees(n);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}





























