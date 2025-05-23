#include<vector>
#include<iostream>
using namespace std;


// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
// 问总共有多少条不同的路径？


// 输入：m = 3, n = 7
// 输出：28

// 输入：m = 3, n = 2
// 输出：3
// 解释：
// 从左上角开始，总共有 3 条路径可以到达右下角。
// 1. 向右 -> 向下 -> 向下
// 2. 向下 -> 向下 -> 向右
// 3. 向下 -> 向右 -> 向下

// 输入：m = 7, n = 3
// 输出：28

// 输入：m = 3, n = 3
// 输出：6


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>num(n, 1);
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    continue;
                }
                else{
                    num[j] += num[j-1];
                }
            }
        }
        return num[n-1];
    }
};



int main()
{
    int m=7, n=3;
    Solution func = Solution();
    int res = func.uniquePaths(m,n);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}











