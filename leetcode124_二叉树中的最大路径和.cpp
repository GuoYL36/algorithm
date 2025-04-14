
#include<vector>
#include<iostream>
#include<string>
using namespace std;

// 二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
// 路径和 是路径中各节点值的总和。
// 给你一个二叉树的根节点 root ，返回其 最大路径和 。
// 输入：root = [1,2,3]
// 输出：6
// 解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
// 输入：root = [-10,9,20,null,null,15,7]
// 输出：42
// 解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42


// 思路
// 状态转移
// 空节点的最大贡献值等于 0。非空节点的最大贡献值等于节点值与其子节点中的最大贡献值之和（对于叶节点而言，最大贡献值等于节点值）。


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

    int res = INT_MIN;
    int dfs(TreeNode* root) {
        if(!root){
            return 0;
        }
        // 递归计算左右子节点的最大贡献值
        // 只有在最大贡献值大于 0 时，才会选取对应子节点
        int left = max(dfs(root->left), 0);
        int right = max(dfs(root->right), 0);

        // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
        int curmax = left + root->val + right;
        // 更新答案
        res = max(res, curmax);
        // 返回节点的最大贡献值
        return max(left, right) + root->val;
    
    }


    int maxPathSum(TreeNode* root) {
        if(!root){
            return 0;
        }
        res = max(res, dfs(root));
        return res;
    }
};


int main()
{
    TreeNode* root= new TreeNode(1);
    root->left = new TreeNode(2);
    // root->left->right = new TreeNode(3);
    root->right = new TreeNode(3);
    // root->right->right = new TreeNode(1);
    Solution func = Solution();
    int res = func.maxPathSum(root);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}























