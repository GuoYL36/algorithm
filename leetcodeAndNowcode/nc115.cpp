// 牛客115、栈和排序


# include<iostream>
# include<vector>
# include<stack>
# include<algorithm>
using namespace std;



class Solution {
public:
    /**
     * 栈排序
     * @param a int整型一维数组 描述入栈顺序
     * @param aLen int a数组长度
     * @return int整型vector
     */
    vector<int> solve(int* a, int aLen) {
        // write code h
        stack<int> s;
        vector<int> res;
        int i=0;
        int tmp = aLen;
        while(i<aLen){
            if(s.empty()){
                s.push(a[i]);
            }
            else{
                int lastmax = *max_element(a+i+1,a+aLen);  // 找出当前元素后面的元素中的最大值
                if(a[i]>lastmax){                          
                    res.push_back(a[i]);                   // 如果当前元素比后面所有元素最大值还大，直接保存结果
                    while(!s.empty() && s.top()>lastmax){           // 如果栈顶元素比后面所有元素最大值还大，直接保存结果
                        res.push_back(s.top());
                        s.pop();
                    }
                }else{
                    s.push(a[i]);
                }
            }
            i++;
        }
        while(!s.empty()){
            int t = s.top();
            res.push_back(t);
            s.pop();
        }
        return res;
    }
};



int main(){
    // int a[5] = {2,1,5,3,4};
    // int aLen = 5;

    // 结果：[40,36,35,20,30,11,32,9,28,26,17,31,23,12,27,19,1,7,10,4,33,22,16,25,37,14,8,21,24,15,6,34,2,5,3,38,29,39,18,13]
    int a[] = {13,18,39,29,38,3,5,2,34,6,15,24,21,8,14,37,25,16,22,33,4,10,7,1,19,27,12,36,40,23,31,17,26,28,9,32,11,30,20,35};
    int aLen = 40;  

    Solution func = Solution();
    vector<int> res = func.solve(a, aLen);
    cout<<"=================="<<endl;
    for(int i=0;i<aLen;i++){
        cout<<res[i]<<endl;
    }
    

    return 1;
}







