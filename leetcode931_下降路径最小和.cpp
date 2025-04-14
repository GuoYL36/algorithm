#include<vector>
#include<iostream>
using namespace std;


// 给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径 的 最小和 。

// 下降路径 可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。具体来说，位置 (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1) 。

// 输入：matrix = [[2,1,3],[6,5,4],[7,8,9]]
// 输出：13
// 解释：如图所示，为和最小的两条下降路径

// 输入：matrix = [[-19,57],[-40,-5]]
// 输出：-59
// 解释：如图所示，为和最小的下降路径


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();

        for(int i=1;i<m;++i){
            for(int j=0;j<m;++j){
                int left = j-1>=0?matrix[i-1][j-1]:INT_MAX;
                int middle = matrix[i-1][j];
                int right = j+1<m?matrix[i-1][j+1]:INT_MAX;
                matrix[i][j] += min(min(left,middle),right);
            }
        }
        int res = INT_MAX;
        for(int i=0;i<m;++i){
            res = min(res, matrix[m-1][i]);
        }
        return res;
    }
};


int main()
{
    vector<vector<int>> obstacleGrid = {{2,1,3},{6,5,4},{7,8,9}};
    Solution func = Solution();
    int res = func.minFallingPathSum(obstacleGrid);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}

























