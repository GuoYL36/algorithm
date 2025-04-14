#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;


class Solution
{
    public:
    string cal_num(int a, int b){
        if(b == 0){
            return "";
        }
        int f_a = a>0?1:-1;
        int f_b = b>0?1:-1;
        unordered_set<int> us;
        string res="";
        int k = a%b;
        while(us.empty() || us.find(k) == us.end()){
            if(k==0){
                break;
            }
            res += to_string(k*10/b);
            us.emplace(k);
            k = (k*10)%b;
        }
        return res;

    }
}
;


int main()
{
    int a=10, b=3;
    Solution func = Solution();
    string res = func.cal_num(a,b);
    cout<<"Res: "<<res<<endl;
}





















