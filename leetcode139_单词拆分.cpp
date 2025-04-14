#include<vector>
#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;


// 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。

// 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

// 输入: s = "leetcode", wordDict = ["leet", "code"]
// 输出: true
// 解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。

// 输入: s = "applepenapple", wordDict = ["apple", "pen"]
// 输出: true
// 解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
//      注意，你可以重复使用字典中的单词。

// 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// 输出: false

// 提示：
// 1 <= s.length <= 300
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 20
// s 和 wordDict[i] 仅由小写英文字母组成
// wordDict 中的所有字符串 互不相同


// 思路：背包算法，以i长度的字符串为例，枚举分割点j，保证dp[j]同时s[j...i-1]在字典中

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> us;
        for(auto x: wordDict){
            us.insert(x);
        }

        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j] && us.find(s.substr(j,i-j)) != us.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
        
    }
};



int main()
{
    string s = "leetcode";
    vector<string> wordDict={"leet", "code"};
    Solution func = Solution();
    bool res = func.wordBreak(s, wordDict);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}




















