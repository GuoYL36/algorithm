// 在二叉树中找到两个节点的最近公共祖先
'''
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution0 {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    TreeNode* res=new TreeNode(-1);
    
    bool dfs(TreeNode* head, int o1, int o2){
        if(head==nullptr){
            return false;
        }
        if(head->val==o1 || head->val==o2){
            return true;
        }
        bool tmp1 = dfs(head->left, o1,o2);
        bool tmp2 = dfs(head->right,o1,o2);
        // tmp1&&tmp2为节点位于公共节点两侧时
        // head->left!=nullptr或head->rght!=nullptr时，节点位于公共节点同一侧并且自身可能是公共节点
        if((tmp1&&tmp2) || (head->left!=nullptr && (head->left->val==o1||head->left->val==o2))|| (head->right!=nullptr && (head->right->val==o1||head->right->val==o2))){
            if(tmp1&&tmp2){
                res= head;
            }
            else if((head->left!=nullptr && (head->left->val==o1||head->left->val==o2))){
                res = head->left;
            }
            else if((head->right!=nullptr && (head->right->val==o1||head->right->val==o2))){
                res = head->right;
            }
            
        }

        return tmp1||tmp2;
    }
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        bool tmp = dfs(root, o1,o2);
        return res->val;
    }
};

//============================================================
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    TreeNode* res=new TreeNode(-1);
    
    bool dfs(TreeNode* head, int o1, int o2){
        if(head==nullptr){
            return false;
        }

        bool tmp1 = dfs(head->left, o1,o2);
        bool tmp2 = dfs(head->right,o1,o2);
        if((tmp1&&tmp2) || ((tmp1||tmp2)&&(head->val==o1||head->val==o2))){
            res= head;
            
        }

        return tmp1||tmp2||head->val==o1||head->val==o2;
    }
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        bool tmp = dfs(root, o1,o2);
        return res->val;
    }
};

'''
