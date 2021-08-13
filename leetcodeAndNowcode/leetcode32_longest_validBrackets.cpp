// leetcode32、最长有效括号——困难
// 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。




#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;



class Solution{
    public:
    // 思路：O(n)+O(n)——栈
    // 1、利用栈记录索引，遇到'('就记录索引；
    // 2、遇到')'就将栈顶元素弹出，
    int longestValidParentheses(string s) {
        int length = s.size();
        int res = 0;
        stack<int> st;
        st.push(-1);
        for(int i=0;i<length;i++){
            if(s[i]=='('){
                st.push(i);
            }else{
                st.pop();
                if(s.empty()){
                    st.push(i);
                }
                else{
                    res = max(res, i-st.top());
                }
            }
        }
        return res;
    }


    // 最优解法：O(n)+O(1)
    // 思路
    // 1、利用两个计数器 left 和 right 。首先，我们从左到右遍历字符串，对于遇到的每个 ‘(’，我们增加left 计数器，对于遇到的每个 ‘)’ ，我们增加 right 计数器。每当 left 计数器与 right 计数器相等时，我们计算当前有效字符串的长度，并且记录目前为止找到的最长子字符串。当 right 计数器比 left 计数器大时，我们将 left 和 right 计数器同时变回 0。
    // 2、从右往左遍历用类似的方法计算即可，只是这个时候判断条件反了过来：
    //      当 left 计数器比 right 计数器大时，我们将 left 和 right 计数器同时变回 0。
    //      当 left 计数器与 right 计数器相等时，我们计算当前有效字符串的长度，并且记录目前为止找到的最长子字符串。

    int longestValidParentheses1(string s) {
        int length = s.size();
        int left = 0;
        int right = 0;
        int res = 0;

        // 从左向右统计'('和')'的数量
        for(int i=0;i<length;i++){
            if(s[i]=='('){
                left++;
            }
            else{
                right++;
            }

            if(left==right){
                res = max(res, 2*right);
            }
            else if(left<right){
                left = 0;
                right=0;
            }
        }

        // 从右向左统计')'和'('的数量
        left = 0;
        right = 0;
        for(int i=length-1;i>=0;i--){
            if(s[i]=='('){
                left++;
            }
            else{
                right++;
            }

            if(left==right){
                res = max(res, 2*right);
            }
            else if(left>right){
                left = 0;
                right=0;
            }
        }
        return res;
    
    }



};


int main(){

    string s=")()())";
    Solution func = Solution();
    int res = func.longestValidParentheses(s);
    cout<<res<<endl;
    return 1;
}





