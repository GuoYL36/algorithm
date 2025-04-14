#include<vector>
#include<iostream>
#include<string>
using namespace std;

// 给你整数 zero ，one ，low 和 high ，我们从空字符串开始构造一个字符串，每一步执行下面操作中的一种：
// 将 '0' 在字符串末尾添加 zero  次。
// 将 '1' 在字符串末尾添加 one 次。
// 以上操作可以执行任意次。
// 如果通过以上过程得到一个 长度 在 low 和 high 之间（包含上下边界）的字符串，那么这个字符串我们称为 好 字符串。
// 请你返回满足以上要求的 不同 好字符串数目。由于答案可能很大，请将结果对 109 + 7 取余 后返回
// 输入：low = 3, high = 3, zero = 1, one = 1
// 输出：8
// 解释：
// 一个可能的好字符串是 "011" 。
// 可以这样构造得到："" -> "0" -> "01" -> "011" 。
// 从 "000" 到 "111" 之间所有的二进制字符串都是好字符串。
// 输入：low = 2, high = 3, zero = 1, one = 2
// 输出：5
// 解释：好字符串为 "00" ，"11" ，"000" ，"110" 和 "011" 。
// 1 <= low <= high <= 105
// 1 <= zero, one <= low

// 思路：
// 状态转移方程为：dp[i] = max(dp[i], dp[i-zero]+dp[i-one]); 最后从low到high累加结果
// 举例，low = 3, high = 3, zero = 1, one = 1, dp[0]=1
// dp[1] = max(dp[1], dp[1-zero]+dp[1-one])   "0"、"1"
// dp[2] = max(dp[2], dp[2-zero]+dp[2-one])   "00"、"01"、"10"、"11"
// dp[3] = max(dp[3], dp[3-zero]+dp[3-one])   "000"、"001"、"010"、"011"、"100"、"101"、"110"、"111"


class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, 0);
        dp[0] =1;
        int res = 0;
        for(int i=1;i<=high;i++){
            int t_0 = i-zero>=0?dp[i-zero]:0;
            int t_1 = i-one>=0?dp[i-one]:0;
            dp[i] = max(dp[i], (t_0+t_1)%1000000007);
            if(i>=low && i <=high){
                res = (res+dp[i])%1000000007;
            }
        }
        return res;
    }
};




int main()
{
    int low=2, high=3, zero=1, one=2;
    Solution func = Solution();
    int res = func.countGoodStrings(low, high, zero, one);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}

























































