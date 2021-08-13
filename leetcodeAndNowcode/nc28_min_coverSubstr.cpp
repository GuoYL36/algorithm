// 牛客28、最小覆盖子串
// 描述：给出两个字符串 SS 和 TT，要求在O(n)O(n)的时间复杂度内在 SS 中找出最短的包含 TT 中所有字符的子串。
    // 例如：

    // S ="XDOYEZODEYXNZ"
    // T ="XYZ"
    // 找出的最短子串为"YXNZ"

    // 注意：
    // 如果 SS 中没有包含 TT 中所有字符的子串，返回空字符串 “”；
    // 满足条件的子串可能有很多，但是题目保证满足条件的最短的子串唯一。

// 滑动窗口解法




#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
    /**
     * 
     * @param S string字符串 
     * @param T string字符串 
     * @return string字符串
     */
    string minWindow(string S, string T) {
        // write code here
        int length = S.size();
        int length1 = T.size();
        if(length==0 || length1 == 0){
            return "";
        }
        unordered_map<char, int> target, window;
        int left=0,right=0;
        int count = 0; // 记录T中字符在D中出现次数
        int res=INT32_MAX;
        string res1 = "";
        // 记录目标字符串字符数
        for(int i=0;i<length1;i++) ++target[T[i]];

        while(right<length){
            char c = S[right];
            right++;                          // 滑动窗口的右端点增加，扩大窗口
            if(target.count(c)){
                ++window[c];
                if(target[c] == window[c]) ++count;         // 如果某个字符出现次数一样，则该字符已完全出现
            }
            while(count==target.size()){        // 当出现的字符个数等于目标字符串T中的字符个数
                if((right-left) < res){         // 计算子串长度
                    res = right-left;
                    res1 = S.substr(left, res);
                }
                c = S[left];               // 滑动窗口的左区间开始收缩
                ++left;
                if(target.count(c)){
                    if(window[c]==target[c]){
                        count--;
                    }
                    window[c]--;
                }
            }

        }
        return res1;


    }
};

int main(){

    string S = "XDOYEZODEYXNZ",T = "XYZ";  // 结果为YXNZ
    Solution func = Solution();
    string res = func.minWindow(S, T);
    cout<<"res: "<<res<<endl;


    return 1;
}