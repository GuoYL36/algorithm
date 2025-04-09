#include<vector>
#include<iostream>
#include<string>
using namespace std;

// 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
// 请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
// 如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

// 输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
// 输出：4
// 解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
// 其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。
// 示例 2：

// 输入：strs = ["10", "0", "1"], m = 1, n = 1
// 输出：2
// 解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
 
// 提示：
// 1 <= strs.length <= 600
// 1 <= strs[i].length <= 100
// strs[i] 仅由 '0' 和 '1' 组成
// 1 <= m, n <= 100

// 思路：
// 定义三维数组 dp，其中 dp[i][j][k] 表示在前 i 个字符串中，使用 j 个 0 和 k 个 1 的情况下最多可以得到的字符串数量。假设数组 str 的长度为 l，则最终答案为 dp[l][m][n]。
// 当没有任何字符串可以使用时，可以得到的字符串数量只能是 0，因此动态规划的边界条件是：当 i=0 时，对任意 0≤j≤m 和 0≤k≤n，都有 dp[i][j][k]=0。
// 当 1≤i≤l 时，对于 strs 中的第 i 个字符串（计数从 1 开始），首先遍历该字符串得到其中的 0 和 1 的数量，分别记为 zeros 和 ones，然后对于 0≤j≤m 和 0≤k≤n，计算 dp[i][j][k] 的值。
// 当 0 和 1 的容量分别是 j 和 k 时，考虑以下两种情况：
// 如果 j<zeros 或 k<ones，则不能选第 i 个字符串，此时有 dp[i][j][k]=dp[i−1][j][k]；
// 如果 j≥zeros 且 k≥ones，则如果不选第 i 个字符串，有 dp[i][j][k]=dp[i−1][j][k]，如果选第 i 个字符串，有 dp[i][j][k]=dp[i−1][j−zeros][k−ones]+1，dp[i][j][k] 的值应取上面两项中的最大值。

// 优化时间复杂度
// 由于 dp[i][][] 的每个元素值的计算只和 dp[i−1][][] 的元素值有关，因此可以使用滚动数组的方式，去掉 dp 的第一个维度，将空间复杂度优化到 O(mn)。
// 实现时，内层循环需采用倒序遍历的方式，这种方式保证转移来的是 dp[i−1][][] 中的元素值。




class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k=strs.size();
        vector<int> len0(k, 0), len1(k,0);
        for(int i=0;i<k;i++){
            string s = strs[i];
            int t0=0, t1=0;
            for(auto t: s){
                if(t=='0'){
                    t0++;
                }
                else{
                    t1++;
                }
            }
            len0[i]=t0;
            len1[i]=t1;
        }

        // vector<vector<vector<int>>> dp(k+1, vector<vector<int>>(m+1,vector<int>(n+1,0)));
        // for(int i=1;i<=k;i++){
        //     for(int j=0;j<=m;j++){
        //         for(int v=0;v<=n;v++){
        //             dp[i][j][v] = dp[i-1][j][v];
        //             if(j>=len0[i-1] && v>=len1[i-1]){
        //                 dp[i][j][v] = max(dp[i-1][j][v], dp[i-1][j-len0[i-1]][v-len1[i-1]]+1);
        //             }
        //         }

        //     }
        // }
        // return dp[k][m][n];


        // 优化思路
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=k;i++){
            for(int j=m;j>=len0[i-1];j--){
                for(int v=n;v>=len1[i-1];v--){
                    dp[j][v] = max(dp[j][v], dp[j-len0[i-1]][v-len1[i-1]]+1);
                }

            }
        }
        return dp[m][n];

    }
};







int main()
{
    int m=5, n=3;
    vector<string> strs={"10", "0001", "111001", "1", "0"};
    Solution func = Solution();
    int res = func.findMaxForm(strs, m,n);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}



