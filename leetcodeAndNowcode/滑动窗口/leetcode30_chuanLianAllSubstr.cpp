// leetcode30、串联所有单词的子串

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
public:
    bool isTrue(unordered_map<string, int>& m){
        for(auto it=m.begin();it != m.end();++it){
            if(it->second != 0){
                return false;
            }
        }
        return true;

    }
    
    vector<int> findSubstring(string s, vector<string>& words){
        int length = s.size();
        int subLength = 0;
        int lengthSub = words[0].size();
        unordered_map<string, int> arrs;
        for(int i=0;i<words.size();i++){
            subLength = subLength+words[i].size();
            ++arrs[words[i]];
        }

        vector<int> res;

        for(int i=0;i<=(length-subLength);i++){
            string st = s.substr(i,subLength);
            int j=0;
            unordered_map<string, int> arrs1;
            arrs1 = arrs;
            while(j<=(subLength-lengthSub)){
                string tmp = st.substr(j,lengthSub);
                if(arrs1.count(tmp)){
                    --arrs1[tmp];
                }
                j=j+lengthSub;
            }
            if(isTrue(arrs1)){
                res.push_back(i);
            }
        }
        return res;

    }


};

int main(){
    string s="barfoothefoobarman";
    vector<string> words;
    words = {"foo","bar"};
    Solution func = Solution();
    vector<int> res;
    res = func.findSubstring(s, words);
    for(int i=0;i<res.size();i++){
        cout<<i<<": "<<res[i]<<endl;
    }

    return 1;
}
