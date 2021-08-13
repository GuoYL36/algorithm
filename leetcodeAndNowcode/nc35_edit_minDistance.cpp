// 35、最小编辑代价
// 给定两个字符串str1和str2，再给定三个整数ic，dc和rc，分别代表插入、删除和替换一个字符的代价，请输出将str1编辑成str2的最小代价。


#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    /**
     * min edit cost
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @param ic int整型 insert cost
     * @param dc int整型 delete cost
     * @param rc int整型 replace cost
     * @return int整型
     */
    int minEditCost(string str1, string str2, int ic, int dc, int rc) {
        int length0 = str1.size();
        int length1 = str2.size();
        vector<vector<int>> dp(length0+1,vector<int>(length1+1,0));
        // 初始化首行和首列
        // 如果行表示要编辑的字符串，列表示目标字符串
        // 对于首行，要编辑的字符串为""，要变成目标字符串，操作只能是插入
        for(int i=0;i<length1+1;i++){
            dp[0][i] = i*ic;
        }
        // 对于首列，由于目标字符串是""，操作只能是删除
        for(int i=0;i<length0+1;i++){
            dp[i][0] = i*dc;
        }

        for(int i=1;i<length0+1;i++){
            for(int j=1;j<length1+1;j++){
                if(str1[i] == str2[j]){
                    dp[i][j] = dp[i-1][j-1];  // 表示当前无需操作
                }else{
                    int insert = dp[i][j-1] + ic;  // 表示要编辑的字符串str1[i]已经与目标字符串str2[j-1]匹配，如果要匹配str2[j]，则str1需插入
                    int delet = dp[i-1][j-1] + rc; // 表示要编辑的字符串str1[i-1]已经与目标字符串str2[j-1]匹配，但str1[i]要和str2[j]匹配，则替换
                    int rep = dp[i-1][j] + dc; // 表示要编辑的字符串str1[i-1]已经与目标字符串str2[j]匹配，但str1[i]多出来了，则删除
                    dp[i][j] = min(insert, min(delet, rep));
                }
            }
        }
        return dp[length0][length1];

    }

    int minEditCost0(string str1, string str2, int ic, int dc, int rc) {
        int length0 = str1.size();
        int length1 = str2.size();

        vector<int> dp(length1+1,0);
        for(int i=1;i<length1+1;i++){
            dp[i] = i*ic;
        }

        for(int i=1;i<length0+1;i++){
            int prev = dp[0];
            dp[0] = i*dc;
            for(int j=1;j<length1+1;j++){
                int tmp = dp[j];
                if(str1[i-1]==str2[j-1]){
                    dp[j] = prev;
                }
                else{
                    int insert = dp[j-1]+ic;
                    int delet = tmp + dc;
                    int rep = prev + rc;  
                    dp[j] = min(insert, min(delet, rep));
                }
                prev = tmp;
            }
        }
        return dp[length1];


    }
};


int main(){
    string str1 = "abc";
    string str2 = "adc";
    Solution func = Solution();
    cout<<func.minEditCost(str1, str2, 1,2,3)<<endl;
    cout<<func.minEditCost0(str1, str2, 1,2,3)<<endl;
}

















