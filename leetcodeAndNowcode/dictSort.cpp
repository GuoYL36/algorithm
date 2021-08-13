// 字典序求下一排列问题

// 思路：数组arr
// 1、第一步，从右向左遍历，找到第一个左边元素小于右边元素，记录左边元素的索引i，如果没有则表示没有下一排列;
// 2、第二步，从右向左遍历，找到第一个元素arr[j]，使得arr[j]>arr[i]，交换两个元素值，并对i后面的元素从小到大排列；
// 3、第二步的结果即为当前排列的下一排列，如果要继续查找，则从第一步迭代就行；

#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;


class Solution{
public:
    vector<vector<int> > permute(vector<int> &num) {
        int length = num.size();
        vector<vector<int>> res;
        if(length<=1){
            res.push_back(num);
            return res;
        }
        res.push_back(num);
        
        vector<int> arr = num;
        int end = length-1;
        while(true){
            
            // 从右往左找，找出第一个右边元素大于左边元素的索引
            int j = end-1;
            while(j>=0 && arr[j]>arr[j+1]){
                j--;
            }
            
            if(j<0){
                break;
            }
            // 从右往左找，找出第一个大于上面索引位置的元素
            int i = end;
            while(i>j && arr[i]<arr[j]){
                i--;
            }
            if(i<=j){
                break;
            }
            // 交换arr[i]和arr[j]
            arr[i] = arr[i]^arr[j];
            arr[j] = arr[i]^arr[j];
            arr[i] = arr[i]^arr[j];
            // 对arr[j]后面的元素排序
            sort(arr.begin()+j+1,arr.end());
            res.push_back(arr);
        }
        return res;
    }
};


int main(){
    vector<int> num;
    num = {1,2,3};
    Solution func = Solution();
    vector<vector<int>> res = func.permute(num);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<endl;
        }
        cout<<"===================="<<endl;
    }

    return 1;
}





