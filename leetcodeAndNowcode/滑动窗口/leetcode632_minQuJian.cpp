// leetcode632、最小区间

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

    }
};


int main(){

    vector<vector<int>> nums;
    nums = {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}}; // [20,24]
    Solution func = Solution();
    vector<int> res = func.smallestRange(nums);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }

    return 1;
}