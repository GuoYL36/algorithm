// 牛客92、最长公共子序列
// 思路：
// 动态规划方程:
//  (1)   arr[i][j] = arr[i-1][j-1]+1    if s[i]==s[j]
//  (2)   arr[i][j] = max(arr[i-1][j], arr[i][j-1])    if s[i] != s[j]
//

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution{
public:
    string longCommonSubList(string s1, string s2){
        int length1 = s1.size();
        int length2 = s2.size();

        vector<vector<int>> arr(length1+1, vector<int>(length2+1,0));

        for(int i=1;i<length1+1;i++){
            for(int j=1;j<length2+1;j++){
                if(s1[i-1]==s2[j-1]){                  // 相等时加1
                    arr[i][j] = arr[i-1][j-1]+1;
                }
                else{                             // 不相等时，取最大的一个
                    arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
                }
            }
        }
        // 这里，如果是求长度的话，直接返回arr[length1][length2]

        // // 打印arr数组
        // for(int i=0;i<length1+1;i++){
        //     for(int j=0;j<length2+1;j++){
        //         cout<<arr[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }


        // 寻找最长子串
        int row = length1;
        int col = length2;
        string res="";
        while(row>0 && col>0){
            if(s1[row-1] == s2[col-1]){   // 当字符相等时，往左上角移动
                res = s1[row-1]+res;
                row--;
                col--;
            }
            else if(arr[row][col-1]>arr[row-1][col]){   // 当字符不等，且左边数字大于上边数值，则往左移动
                col--;
            }
            else{
                row--;                     // 当字符不等，且左边数字小于等于上边数值，则往上移动
            }
        }
        if(res.empty()){
            return "-1";
        }
        return res;
    }

};


int main(){
    string s1 = "1A2C3D4B56";
    string s2 = "B1D23A456A";
    Solution func = Solution();
    string res = func.longCommonSubList(s1,s2);
    cout<<res<<endl;
    return 1;
}






































