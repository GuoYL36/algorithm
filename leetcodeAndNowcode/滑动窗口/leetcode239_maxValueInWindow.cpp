// leetcode239、滑动窗口中的最大值


#include<iostream>
#include<vector>
#include<queue>
#include<deque>
using namespace std;

class Solution {
public:

    // 利用最大堆寻找当前窗口最大值，时间复杂度O(nlogn)、空间复杂度O(n)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int length = nums.size();
        vector<int> arr;
        priority_queue<pair<int, int>> p; // 优先队列，默认是大顶堆

        for(int i=0;i<k;i++){
            p.emplace(nums[i],i);
        }
        arr.push_back(p.top().first);

        for(int i=k;i<length;i++){
            p.emplace(nums[i],i);
            while(p.top().second <= i-k){
                p.pop();
            }
            arr.push_back(p.top().first);
        }
        return arr;    
        
    }

    // 利用单调队列，时间复杂度O(N),空间复杂度：O(N)
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        int length = nums.size();
        vector<int> arr;
        deque<int> d;

        for(int i=0;i<k;i++){
            while(!d.empty() && nums[i]>nums[d.back()]){
                d.pop_back();
            }
            d.push_back(i);          // 记录当前窗口的最大值索引
        }

        for(int i=k;i<length;i++){
          
            while(!d.empty() && nums[i]>nums[d.back()]){
                d.pop_back();
            }
            d.push_back(i);
            while(d.front()<=(i-k)){
                d.pop_front();
            }
            arr.push_back(nums[d.front()]);
        }
        return arr;


    
    }

};

int main(){

    // [3,3,5,5,6,7]
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution func = Solution();
    vector<int> res = func.maxSlidingWindow(nums,k);

    for(auto i: res){
        cout<<i<<endl;
    }


    return 1;
}

