// leetcode 209、长度最小的子数组


#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = nums.size();

        int left=0,right=0;
        int res=INT32_MAX, curSum=0;
        while(right<length){
            curSum += nums[right];

            while(curSum>=target){
                res = res<(right-left+1)?res:(right-left+1);
                curSum -= nums[left];
                left++;
            }
            right++;
        }
        return res==INT32_MAX?0:res;

    }
};

int main(){

    // 2
    // int target = 7;
    // vector<int> nums = {2,3,1,2,4,3}; 

    // // 1
    // int target = 4;
    // vector<int> nums = {1,4,4};

    // 11
    int target = 11;
    vector<int> nums = {1,1,1,1,1,1,1,1};   

    Solution func = Solution();
    int res = func.minSubArrayLen(target, nums);
    cout<<"res: "<<res<<endl;

    return 1;
}


