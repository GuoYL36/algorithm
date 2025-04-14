#include<vector>
#include<iostream>
#include<string>
using namespace std;


// 给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。
// 输入：n = 3
// 输出：[[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
// 输入：n = 1
// 输出：[[1]]


// 思路
// 1. 将1～n所有数字作为根节点遍历一遍
// 2. 假设根节点为i，则将1～(i-1)作为左子树进行遍历构成二叉搜索树；将(i+1)~n作为右子树进行遍历构成二叉搜索树
// 3.左子树和右子树遍历形成不同的 二叉搜索树
// 4. 左子树和右子树的构建 按步骤一重新迭代构建


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:

    vector<TreeNode*> dfs(int a, int b){
        if (a > b) {
            return { nullptr };
        }
        vector<TreeNode*> res;
        // 枚举可行根节点
        for(int i=a;i<=b;i++){
            
            vector<TreeNode*> leftTree = dfs(a, i-1);
            vector<TreeNode*> rightTree = dfs(i+1, b);
            for(auto left: leftTree){
                for(auto right: rightTree){
                    TreeNode* tmp = new TreeNode(i);
                    tmp->left = left;
                    tmp->right = right;
                    res.push_back(tmp);
                }
            }  
        }
        return res;
    }


    vector<TreeNode*> generateTrees(int n) {
        if(n<=0){
            return {};
        }
        return dfs(1, n);
    }
};



int main()
{
    int n= 3;
    Solution func = Solution();
    vector<TreeNode*> res = func.generateTrees(n);
    // cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}





























