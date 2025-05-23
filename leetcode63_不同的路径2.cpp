#include<vector>
#include<iostream>
using namespace std;


// 给定一个 m x n 的整数数组 grid。一个机器人初始位于 左上角（即 grid[0][0]）。机器人尝试移动到 右下角（即 grid[m - 1][n - 1]）。机器人每次只能向下或者向右移动一步。
// 网格中的障碍物和空位置分别用 1 和 0 来表示。机器人的移动路径中不能包含 任何 有障碍物的方格。
// 返回机器人能够到达右下角的不同路径数量。
// 测试用例保证答案小于等于 2 * 109。

// 输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// 输出：2
// 解释：3x3 网格的正中间有一个障碍物。
// 从左上角到右下角一共有 2 条不同的路径：
// 1. 向右 -> 向右 -> 向下 -> 向下
// 2. 向下 -> 向下 -> 向右 -> 向右

// 输入：obstacleGrid = [[0,1],[0,0]]
// 输出：1


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int>num(n, 0);
        for(int i=0;i<n;i++){
            if(i==0){
                num[i]=obstacleGrid[0][i]==0?1:0;
            }
            else{
                num[i] = obstacleGrid[0][i]==1?0:num[i-1];
            }
        }

        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    num[j] = 0;
                }
                else{
                    if(j==0){
                        continue;
                    }
                    else{
                        num[j] += num[j-1];
                    }
                    
                }
            }
        }
        return num[n-1];
    }
};



int main()
{
    vector<vector<int>> obstacleGrid = {{0,1},{0,0}};
    Solution func = Solution();
    int res = func.uniquePathsWithObstacles(obstacleGrid);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}











