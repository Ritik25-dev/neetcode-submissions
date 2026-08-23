/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val == p->val || root->val == q->val){
            return root;
        }

        TreeNode* leftSub = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightSub = lowestCommonAncestor(root->right,p,q);

        if(!leftSub && !rightSub) return NULL;
        if(leftSub && rightSub) return root;
        return  leftSub?leftSub:rightSub;

    }
};