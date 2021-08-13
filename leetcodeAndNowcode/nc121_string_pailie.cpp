// nc121、字符串的排列——较难

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;


class Solution{
    public:

    vector<string> res;
    void dfs(string str, string s){
        if(str.size()==0){
            res.push_back(s);
            return;
        }
        set<string> a;      // 用于记录当前递归函数中已经遍历过的字符
        for(int k=0;k<str.size();k++){
            if(a.count(to_string(str[k]))>0){  // 如果该字符已经被遍历，则跳过
                continue;
            }
            s += str[k];
            string tmp_str = str.substr(0,k)+str.substr(k+1,str.size()-1-k);   // 下一个递归中要剔除掉当前字符
            a.insert(to_string(str[k]));
            dfs(tmp_str,s);
            s = s.substr(0,s.size()-1);
        }        
    }
    
    vector<string> Permutation(string str) {
        if(str.empty()){
            res.push_back(str);
            return res;
        }
        // 第一步，对str进行字典序排序
        sort(str.begin(), str.end());
        
        // 第二步，按照字典序进行递归遍历
        dfs(str,"");
        return res;
    }
};


int main(){
    string s="abac";
    cout<<s<<" "<<s.size()<<endl;
    Solution func = Solution();
    vector<string> res = func.Permutation(s);
    cout<<"res size: "<<res.size()<<endl;
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
    return 1;
}

























