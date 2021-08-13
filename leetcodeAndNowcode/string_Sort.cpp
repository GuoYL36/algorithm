// 利用快排的思路对字符串进行排序
# include<iostream>
# include<vector>
# include<string>
using namespace std;

class Sort{
public:
    vector<string> nums;
    bool cmp(string a, string b){
        return a+b>b+a;
    }

    int partition(int m, int n){

        int left = m;
        int right = n;
        string tmp = nums[left];
        while(left<right){
            while(left<right && cmp(tmp, nums[right])){
                right--;
            }
            if(left<right){
                nums[left] = nums[right];
                left++;
            }
            while(left<right && cmp(nums[left], tmp)){
                left++;
            }
            if(left<right){
                nums[right] = nums[left];
                right--;
            }
        }
        nums[left] = tmp;
        return left;
    }

    void sort_string(int m, int n){
        if(m>=n){
            return;
        }
        int left = m;
        int right = n;
        int mid = partition(left, right);
        sort_string(left, mid-1);
        sort_string(mid+1,right);
    }
};


int main(){
    vector<string> arr;
    // arr = {"1","0","12","32","45","76"};
    arr = {"0","0"};
    Sort func = Sort();
    func.nums = arr;
    func.sort_string(0, func.nums.size()-1);
    for(int i=0;i<arr.size();i++){
        cout<<func.nums[i]<<endl;
    }
    
    return 1;


}













