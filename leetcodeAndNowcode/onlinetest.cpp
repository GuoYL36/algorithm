//一个方便自己测试的


#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;


class Solution {
public:
    /**
     * return topK string
     * @param strings string字符串vector strings
     * @param k int整型 the k
     * @return string字符串vector<vector<>>
     */

    vector<string> conat(vector<string>& str, map<string,int>& m){
        for(int i=0;i<str.size();i++){
            str[i] = to_string(m[str[i]])+str[i];
        }
        return str;
    }
    
    static bool compa(string a,string b){
        string count_a = to_string(a[0]);
        string count_b = to_string(b[0]);
        string tmp_a = a.substr(1,a.size()-1);
        string tmp_b = b.substr(1,b.size()-1);
        return (count_a>count_b)||(count_a==count_b && tmp_a<tmp_b);
    }
    vector<vector<string> > topKstrings(vector<string>& strings, int k) {
        int length = strings.size();
        vector<vector<string>> res;
        map<string, int> m;
        vector<string> a;
        if(length==0 || k<=0){
            return res;
        }
        for(int i=0;i<length;i++){
            if(m.count(strings[i])>0){
                m[strings[i]] = m[strings[i]]+1;
            }else{
                m[strings[i]] = 1;
                a.push_back(strings[i]);
            }

        }
        vector<string> s = conat(a, m);
        sort(s.begin(),s.end(),compa);


        for(int i=0;i<k;i++){
            vector<string> tmp1;
            tmp1.push_back(s[i].substr(1,s[i].size()-1));
            tmp1.push_back(s[i].substr(0,1));
            res.push_back(tmp1);
         }
        return res;
        
        
    }


    int MLS(vector<int>& arr) {
        int length=arr.size();
        if(length<=1){
            return length;
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<length;i++){
            cout<<arr[i]<<endl;
        }
        cout<<"=========="<<endl;
        int i=0;
        int j=1;
        int count=0;
        while(j<length){
            while(j<length && arr[j]-arr[j-1]==1){
                j++;
            }
            count= max(count, j-i);
            i = j;
            j++;
            
        }
        return count;
    }

};



int main(){
    // string s="-11";
    // int a = stoi(s);
    // cout<<a<<endl;
    // Solution func = Solution();
    // cout<<"=======进制转换结果======"<<endl;
    // cout<<func.solve(131,12)<<endl;
    
    // vector<int> h;
    // h = {2,1,5,6,2,3};
    // int tmp = *min_element(h.begin()+2,h.begin()+6);
    // cout<<tmp<<endl;

    // string s="(1+2)";
    // bool floor = s.compare(0,1,"(")==0?true:false;
    // cout<<floor<<endl;
    // string s1 = "aabac";
    // sort(s1.begin(),s1.end());
    // cout<<s1<<endl;
    // set<string> a;
    // a.insert(s);

    int k = 2;
    vector<string> a;
    a={"a","b","c","b","c"};
    Solution func = Solution();
    // vector<vector<string>> res = func.topKstrings(a,k);
    // for(int i=0;i<k;i++){
    //     cout<<res[i][0]<<" "<<res[i][1]<<endl;
    // }
    vector<int> arr;
    arr = {100,4,200,1,3,2};
    int res = func.MLS(arr);
    cout<<res<<endl;

   
    return 1;
}
















