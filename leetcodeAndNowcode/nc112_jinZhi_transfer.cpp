// 牛客112、进制转换


#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;


class Solution{
public:
    // 进制转换
    string solve(int M, int N){
        map<int, string> m;
        m[10]="A";
        m[11]="B";
        m[12]="C";
        m[13]="D";
        m[14]="E";
        m[15]="F";
        m[16]="G";
        string res="";
        int a=M>0?M:(-M);
        while(a!=0){
            res+=(a%N>=10)?m[a%N]:to_string(a%N);
            a = a/N;
        }
        if(M<0){
            res+="-";
        }
        reverse(res.begin(),res.end());
        return res;
    }

    
};


int main(){
    Solution func = Solution();
    cout<<"=======进制转换结果======"<<endl;
    cout<<func.solve(131,12)<<endl;
    return 1;
}