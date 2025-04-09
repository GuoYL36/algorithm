#include<vector>
#include<iostream>
using namespace std;


// 给定一个三角形 triangle ，找出自顶向下的最小路径和。
// 每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。

// 输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// 输出：11
// 解释：如下面简图所示：
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
// 示例 2：

// 输入：triangle = [[-10]]
// 输出：-10

// 你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题吗？



class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m= triangle.size();
        
        for(int i=1;i<m;i++){
            int n = triangle[i].size();
            int pre_r = triangle[i-1].size();
            for(int j=0;j<n;++j){
                int pre_left = j-1>=0?triangle[i-1][j-1]:INT_MAX;
                int pre_right = j<pre_r?triangle[i-1][j]:INT_MAX;
                triangle[i][j] += min(pre_left,pre_right);
            }
        }
        int min_val = INT_MAX;
        for(int i=0;i<(int)triangle[m-1].size();++i){
            min_val = min(min_val, triangle[m-1][i]);
        }
        return min_val;

    }
};

int main()
{
    vector<vector<int>> obstacleGrid = {{2},{3,4},{6,5,7},{4,1,8,3}};
    Solution func = Solution();
    int res = func.minimumTotal(obstacleGrid);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}






















