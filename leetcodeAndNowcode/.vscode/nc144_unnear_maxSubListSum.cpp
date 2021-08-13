// 牛客144、不相邻最大子序列和
// 给一个整数n，和一个长度为n的数组，选择位置不相邻的两个数的基础上，求该序列的最大子序列和（挑选出的子序列可以为空）

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算
     * @param n int整型 数组的长度
     * @param array int整型vector 长度为n的数组
     * @return long长整型
     */
    long long subsequence(int n, vector<int>& array) {
        vector<int> arr(n+2,0);
        int res = 0;
        if(n==0){ 
            return res; 
        }
        if(n==1){
            return array[0];
        }
        
        for(int i=0;i<n;i++){
            if(i==0){
                arr[i+2] = array[i];
            }
            else{
                arr[i+2] = max(arr[i],arr[i-1])+array[i];    // 找出当前元素索引i的第i-2和第i-3索引的最大子序列和，并进行累计
            }
            res = res>arr[i+2]?res:arr[i+2];
        }
        return res;
    }
};


int main(){

    int n=4;
    vector<int> array;
    array = {4,2,3,5};
    Solution func = Solution();
    int res = func.subsequence(n, array);
    return 0;
}




























