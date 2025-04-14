#include<vector>
#include<iostream>
using namespace std;


// 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。
// 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
// 输入：nums = [1,1,1,2,2,3]
// 输出：5, nums = [1,1,2,2,3]
// 解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3。 不需要考虑数组中超出新长度后面的元素。
// 输入：nums = [0,0,1,1,1,1,2,3,3]
// 输出：7, nums = [0,0,1,1,2,3,3]
// 解释：函数应返回新长度 length = 7, 并且原数组的前七个元素被修改为 0, 0, 1, 1, 2, 3, 3。不需要考虑数组中超出新长度后面的元素。


class Solution
{
    public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if(length <= 0){
            return length;
        }
        int pre=0;
        int nxt=0;
        int count = 0;
        int tmp = nums[0];
        while(nxt<length){
            while(nxt<length && nums[nxt]==tmp){
                count++;
                if(count<=2){
                    nums[pre] = nums[nxt];
                    pre++;
                }
                nxt++;
            }
            if(nxt<length){
                tmp = nums[nxt];
                count = 0;
            }
        }
        return pre;

        // 官方题解
        // if (length <= 2) {
        //     return length;
        // }
        // int slow = 2, fast = 2;
        // while (fast < length) {
        //     if (nums[slow - 2] != nums[fast]) {
        //         nums[slow] = nums[fast];
        //         ++slow;
        //     }
        //     ++fast;
        // }
        // return slow;
    }
}
;


int main()
{
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    Solution func = Solution();
    int res = func.removeDuplicates(nums);
    cout<<"res: "<<res<<endl;
    for(auto x: nums){
        cout<<x<<" ";
    }
    cout<<endl;
    return 1;
}














