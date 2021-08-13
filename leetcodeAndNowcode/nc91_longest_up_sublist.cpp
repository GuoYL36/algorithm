// 牛客91、最长上升子序列（最长递增子序列）——输出字典序最小的

#include<iostream>
#include<vector>

using namespace std;

// 思路
// arr = [3,2,5,8,6,7]
// 0 ---> tmp=[3], lis_length=[1]
// 1 ---> tmp=[2], lis_length=[1,1]
// 2 ---> tmp=[2,5], lis_length=[1,1,2]
// 3 ---> tmp=[2,5,8], lis_length=[1,1,2,3]
// 4 ---> tmp=[2,5,6], lis_length=[1,1,2,3,3]
// 5 ---> tmp=[2,5,6,7], lis_length=[1,1,2,3,3,4]
// 反向查找得到结果，最长递增子序列的长度为 j = tmp.size(), i=arr.size()-1
// (lis_length[5]=4) == (j=4), res[3]=arr[5]=7, j--,i--
// (lis_length[4]=3) == (j=3), res[2]=arr[4]=6, j--,i--
// (lis_length[3]=3) != (j=2), continue,i--
// (lis_length[2]=2) == (j=2), res[1]=arr[2]=5, j--,i--
// (lis_length[1]=1) == (j=1), res[0]=arr[1]=2, j--,i--
// j<0，停止


class solution{
    public:
    // 贪心+二分，时间复杂度为O(nlogn)
    vector<int> LIS(vector<int>& arr){
        vector<int> lis_length;
        lis_length = {1};
        vector<int> tmp;
        tmp = {arr[0]};

        // 找到每个位置上最长的子序列
        for(int i=0;i<arr.size();i++){
            if(arr[i]>tmp.back()){    // 如果当前元素大于当前子序列的最后一个元素，则添加到当前子序列中
                tmp.push_back(arr[i]);
                lis_length.push_back(tmp.size());
            }
            else{                     // 如果当前元素小于当前子序列的最后一个元素，则从当前子序列中找到第一个大于当前元素的值并替换它，更新最大长度
                for(int j=0;j<tmp.size();j++){     // 这个可以改成二分
                    if(tmp[j]>arr[i]){
                        tmp[j] = arr[i];
                        lis_length.push_back(j+1);
                        break;
                    }
                }
            }
        }
        // for(int i=0;i<tmp.size();i++){
        //     cout<<tmp[i]<<endl;
        // }
        // cout<<endl;
        // cout<<tmp.size()<<" "<<lis_length.back()<<endl;

        // 根据子序长度反向查找得到最长子序列
        vector<int> res(tmp.size(),0);
        int j = tmp.size()-1;
        for(int i=arr.size()-1;j>=0;i--){
            if(lis_length[i]==j+1){    // lis_length记录的是原始数组中每个索引下最长的子序列，所以当该索引下的子序列长度等于当前最长子序列长度时，对应元素可以保留下来
                res[j]=arr[i];
                j--;
            }
        }
        return res;

    }
};

int main(){
    vector<int> arr;
    // arr = {3,2,5,8,6,7};
    arr = {2,1,5,3,6,4,8,9,7};   //[1,3,4,8,9]
    solution fun = solution();
    vector<int> res = fun.LIS(arr);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }

    return 1;
}


