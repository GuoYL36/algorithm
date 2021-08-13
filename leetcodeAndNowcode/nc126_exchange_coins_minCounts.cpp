// 126、换钱的最少货币数

# include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
    /**
     * 最少货币数
     * @param arr int整型vector the array
     * @param aim int整型 the target
     * @return int整型
     */

    // 思路1：递归法
    int res=INT_MAX;
    void dfs(vector<int>& arr, int cur, int val, int k){
        if(cur>val){
            return;
        }
        if(cur == val){
            res = min(res, k);
            return;
        }
        int tmp = k+1;
        for(int i=0;i<arr.size();i++){
            cur += arr[i];
            dfs(arr,cur, val, tmp);
            cur -= arr[i];
        }
    }
    
    int minMoney(vector<int>& arr, int aim) {
        if(aim<=0){
            return 0;
        }
        dfs(arr,0,aim,0);
        if(res==INT_MAX){
            return -1;
        }
        return res;
    }

    // 思路2：动态规划法
    int minMoney1(vector<int>& arr, int aim){
        if(aim<=0){
            return 0;
        }
        vector<int> dp(aim+1, aim+1);
        dp[0] = 0; // 总金额为0的时候需要的硬币数一定是0
        for(int i=1;i<=aim;i++){     // 因为aim是最终目标硬币值，所以它可以由小于它的其他硬币面值构成
            for(int j=0;j<arr.size();j++){
                if(arr[j]<=i){      // 当前面值小于当前目标硬币值时，计算构成该目标硬币值所需最小硬币数
                    dp[i] = min(dp[i],dp[i-arr[j]]+1);
                }
            }
        }
        return dp[aim]>aim?-1:dp[aim];

    }
};