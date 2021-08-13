// nc128、容器盛水问题——中等难度

#include<iostream>
#include<vector>
using namespace std;

// 解题思路——双指针法
// 第一步，将首尾作为左右两侧的最高点；
// 第二步，找出左右最高点哪个更低，并判断当前值与该点的高低，如果低则计算差值并累加，否则用当前点更新该点；
// 第三步，重复第二步直至达到最后一个值，判断左右最高点中哪个更低，并判断当前值与该点的高低，如果低则计算差值并累加，否则结束遍历。


class Solution{
    public:

    long long maxWater(vector<int>& arr){
        int length = arr.size();
        int left = 0;
        int right = length-1;
        int left_max = arr[0];  // 记录左边最高点
        int right_max = arr[right];  // 记录右边最高点
        long long res=0; 
        while(left<=right){
            if(left==right){    // 当处于最后一个值时
                int tmp = min(left_max,right_max);    // 找出左右两边哪个更低
                if(arr[left]<tmp) res += tmp-arr[left];  // 计算最低的与当前值的差并累计
                break;
            }
            if(arr[left]<arr[right]){        // 更新左边最高点
                if(arr[left]<left_max){      // 当前点比左边最高点更低时，累计差值
                    res += left_max-arr[left];
                }else{
                    left_max = arr[left];
                }
                left++;
            }
            else{
                if(arr[right]<right_max){    // 更新右边最高点
                    res += right_max-arr[right];    // 当前点比右边最高点更低时，累计差值
                }else{
                    right_max = arr[right];
                }
                right--;
            }
        }
        return res;
    }
};

int main(){

    vector<int> arr;
    arr = {3,1,2,5,2,4};
    Solution f = Solution();
    cout<<"容器能装: "<<f.maxWater(arr)<<endl;

    return 1;
}






















