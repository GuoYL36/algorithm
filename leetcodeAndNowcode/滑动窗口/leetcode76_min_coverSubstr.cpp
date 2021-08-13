// leetcode76、最小覆盖子串


#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;


class Solution {
public:

    // ================= 超时
    bool isTrue(unordered_map<char,int>& m, unordered_map<char, int>& t){

        for(auto it=t.begin();it!=t.end();it++){
            if(m[it->first]==0 || m[it->first] < it->second){
                return false;
            }
        }
        return true;
    }

    string minWindow1(string s, string t) {
        int s_length = s.size();
        int t_length = t.size();
        if(s=="" || t=="" || t_length>s_length){
            return "";
        }
        unordered_map<char, int> target, window;
        int res_length = INT32_MAX;
        string res="";
        for(int i=0;i<t_length;i++){
            ++target[t[i]];
        }

        int left = 0, right=0;
        while(right<s_length){
            cout<<"left: "<<left<<" right: "<<right<<endl;
            cout<<"res: "<<res<<endl;
            char c = s[right];
            right++;
            if(target.count(c)){
                ++window[c];
            }

            if((right-left)>=t_length && isTrue(window, target)){
               
                if(res_length>(right-left)){
                    res_length = right-left;
                    res = s.substr(left, res_length);     
                }
                // left = left+findFirstCommon(s.substr(left, right-left), target);
                
                window.clear();
                left++;
                c = s[left];
                while(left<s_length && target.count(c)==0){
                    left++;
                    c = s[left];
                }
                right = left;           
            }

        }
        return res;
    }

    // ================= 上述改进
    string minWindow(string s, string t){
        int s_length = s.size();
        int t_length = t.size();
        if(s=="" || t=="" || t_length>s_length){
            return "";
        }
        unordered_map<char, int> target, window;
        int res_length = INT32_MAX, res_left = -1;;
        string res="";
        for(int i=0;i<t_length;i++){
            ++target[t[i]];
        }

        int left = 0, right=0;
        while(right<s_length){
            if(target.find(s[right]) != target.end()){
                ++window[s[right]];
            }
            while(isTrue(window, target) && left<=right){
                if((right-left+1)<res_length){
                    res_left = left;
                    res_length = right-left+1;
                }

                if(target.find(s[left]) != target.end()){
                    --window[s[left]];
                }
                left++;
            }


            right++;
        }
        return res_left != -1?s.substr(res_left, res_length):"";

    }

    // ==================== 解法2
    string minWindow3(string s, string t) {
        int s_length = s.size();
        int t_length = t.size();
        if(s_length<t_length){
            return "";
        }

        int minLength = t_length;
        unordered_map<char, int> target;
        for(char c: t){
            ++target[c];
        } 

        int res_start = -1;
        int res_length = INT32_MAX;

        int left =0, right=0;
        while(right<s_length){
            if(target.find(s[right]) != target.end()){
                if(target[s[right]]>0) minLength--;
                target[s[right]]--;
            }

            if(minLength == 0){
                while(true){

                    if(target.find(s[left]) == target.end()){
                        left++;
                    }
                    else{
                        if(target[s[left]]<0){
                            target[s[left]]++;
                            left++;
                        }
                        else{
                            break;
                        }
                    }

                }
                
                if((right-left+1)<res_length){
                    res_length = right-left+1;
                    res_start = left;
                }

            }
            right++;
        }

        if(res_start == -1){
            return "";
        }
        return s.substr(res_start, res_length);
    
    }

};

int main(){
    string s = "ADOBECODEBANC", t = "ABC"; // 结果“BANC”
    // string s = "aa", t="aa"; // 结果"aa"
    // string s="abc", t ="bc";  // "bc"
    Solution func = Solution();
    string res = func.minWindow3(s,t);
    cout<<res<<endl;


}












