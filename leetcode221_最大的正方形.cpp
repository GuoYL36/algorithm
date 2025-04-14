#include<vector>
#include<iostream>
#include<string>
using namespace std;


// 在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。

// 输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// 输出：4

// 输入：matrix = [["0","1"],["1","0"]]
// 输出：1

// 输入：matrix = [["0"]]
// 输出：0

// 动态规划： dp(i,j) 表示以 (i,j) 为右下角，且只包含 1 的正方形的边长最大值。
// dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j])+1


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        int res=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(matrix[i][j]=='0'){
                    dp[i][j] = 0;
                }
                else{
                    int pre_left = i-1>=0&&j-1>=0?dp[i-1][j-1]:0;
                    int pre_right = i-1>=0&&j>=0?dp[i-1][j]:0;
                    int cur_left = j-1>=0?dp[i][j-1]:0;
                    dp[i][j] = min(min(pre_left, pre_right),cur_left)+1;
                }
                res = max(res, dp[i][j]);
            }
        }
        return res*res;
        
    }
};



int main()
{
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    Solution func = Solution();
    int res = func.maximalSquare(matrix);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}




















