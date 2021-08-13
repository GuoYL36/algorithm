// 87、丢棋子问题
//一座大楼有0-n层，地面算作第0层，最高的一层为第n层。已知棋子从第0层掉落肯定不会摔碎，从第i层掉落可能会摔碎，也可能不会摔碎(1<=i<=n)。
// 给定整数n作为楼层数，再给定整数k作为棋子数，返回如果想找到棋子不会摔碎的最高层数，即使在最差的情况下扔的最小次数。一次只能扔一个棋子。
#include<vector>
#include<iostream>
using namespace std;

class Solution
{
public:

    int dfs(int n, int k){
        if(n==0 || k==0){
            return 0;
        }
        if(n>0 && k==1){    // 当棋子只有1颗时，次数等于楼层
            return n;
        }

        int res = INT32_MAX;
        for(int i=1;i<n;i++){     // 从第1层开始扔，一直到第n-1层，找出其中最小的次数
            res = min(res, max(dfs(i-1,k-1), dfs(n-i,k)));   // 当在第i层扔时，出现两种情况，一种是棋子碎了，则只能计算之前层的最少次数dfs(i-1,k-1)；一种是棋子没碎，则从剩余的n-i层找出最小次数dfs(n-i,k)；取两种情况中的最大值（因为考虑最差情况）
        }
        return res+1;
    }

    int solve(int n, int k){
        return dfs(n,k);
    }

    // 解法2超过了内存限制
    int solve2(int n, int k){
        if(n==0 || k==0){
            return 0;
        }
        if(n>0 && k==1){
            return n;
        }

        vector<vector<int>>res(n+1, vector<int>(k+1, 0));

        for(int i=0;i<=n;i++){  // 对于只有1颗棋子的时候
            res[i][1] = i;
        }

        for(int j=1;j<=k;j++){  // 对于第一层的时候
            res[1][j] = 1;
        }

        for(int i=2;i<=n;i++){
            for(int j=2;j<=k;j++){
                int tmp = INT32_MAX;
                for(int v=1;v<i;v++){
                    tmp = min(tmp, max(res[v-1][j-1], res[i-v][j]));
                }
                if(tmp<INT32_MAX){
                    res[i][j] = tmp+1;
                }
            }
        }
        return res[n][k];

    }

    // 最优解法：将问题转换一下—— 给定k个棋子，只能扔t次，最大能达到的楼层高度n
    int dfs3(int k, int t){   // k个棋子，次数为t
        if(k==1 || t==1){     // 如果只有一次尝试机会或者棋子只有一个，则只能确定t+1数量的楼层哪一层棋子会碎
            return t+1;
        }
        return dfs3(k, t-1) + dfs3(k-1, t-1);
    }
    int solve3(int n, int k){
        if(n==0 || k==0){
            return 0;
        }
        if(n>0 && k==1){
            return n;
        }
        int t=1;
        while(dfs3(k, t)<(n+1)){    // k个棋子，扔t次能达到的最大高度n
            t++;
        }
        return t;
    }

};

int main(){
    
    // int n = 105,k=2;   // 结果为14
  
    // int n=12,k=2;   // 结果为5

    int n=1, k=1000000;   // 结果为1
    Solution func = Solution();
    int res = func.solve3(n, k);
    cout<<res<<endl;

    return 1;
}

































