
#include<vector>
#include<iostream>
#include<string>
using namespace std;


// 小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
// 除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。
// 给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。

// 输入: root = [3,2,3,null,3,null,1]
// 输出: 7 
// 解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7
// 输入: root = [3,4,5,1,3,null,1]
// 输出: 9
// 解释: 小偷一晚能够盗取的最高金额 4 + 5 = 9



// 思路
// 1.状态
// （1）用 f(o) 表示选择 o 节点的情况下，o 节点的子树上被选择的节点的最大权值和；
// （2）g(o) 表示不选择 o 节点的情况下，o 节点的子树上被选择的节点的最大权值和；l 和 r 代表 o 的左右孩子。
// 2. 转移过程
// (1)假设当前选择，则左右子节点都不能选，则最大全值和：f(o)=g(l)+g(r)+node->val;
// (2)假设当前不选择，则左右子节点都能选，则最大全值和：g(o)=max(f(l), g(l))+max(f(r), g(r));
// 3. 遍历方式：哈希表来存 f 和 g 的函数值，用深度优先搜索的办法后序遍历这棵二叉树


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

    unordered_map<TreeNode*, int>um_f, um_g;
    void dfs(TreeNode* root){
        if(!root){
            return;
        }
        dfs(root->left);
        dfs(root->right);
        um_f[root] = root->val + um_g[root->left] + um_g[root->right];
        um_g[root] = max(um_f[root->left], um_g[root->left])+max(um_f[root->right], um_g[root->right]);

    }

    int rob(TreeNode* root) {
        dfs(root);
        return max(um_f[root], um_g[root]);
    }
};



int main()
{
    TreeNode* root= new TreeNode(3);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    Solution func = Solution();
    int res = func.rob(root);
    cout<<"res: "<<res<<endl;
    // for(auto x: nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return 1;
}





























