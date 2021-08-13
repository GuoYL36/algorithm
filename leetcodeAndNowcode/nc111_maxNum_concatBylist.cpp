// 最大数-中等
// 给定一个数组由一些非负整数组成，现需要将他们进行排列并拼接，使得最后的结果最大，返回值需要是string类型 否则可能会溢出

// 思路：
// 1、将数组中int型转换为string类型
// 2、对数组进行排序，排序规则：每次将相邻的两个字符串正反拼接，然后比较大小，从而确定相邻的两个字符串是否交换位置
// 3、如果排序好的数组第一个元素是"0"，那么结果直接返回"0"，否则，直接从头到尾拼接返回就行

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    /**
     * 最大数
     * @param nums int整型vector 
     * @return string字符串
     */
    // 排序规则
    bool cmp(string a, string b){
        return a+b>b+a;
    }

    string solve(vector<int>& nums) {
        // 将int型转换为string
        vector<string> arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back(to_string(nums[i]));
        }
        sort(arr.begin(),arr.end(),cmp);
        if(arr[0]=="0"){
            return "0";
        }
        string res="";
        for(int i=0;i<arr.size();i++){
            res += arr[i];
        }
        return res;
    }
};


int main(){
    vector<int> arr;
    arr = {30,1};

    return 1;
}


