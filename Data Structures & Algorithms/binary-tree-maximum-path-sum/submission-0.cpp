/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root,int& maxSum){
        if(!root){
            return 0;
        }

        int left = solve(root->left,maxSum);
        int right = solve(root->right,maxSum);

        if(left > 0 && right > 0){
            int sum = left + right + root->val;
            maxSum = max(maxSum,sum);
            return root->val + max(left,right);
        }else if(left < 0 && right < 0){
            maxSum = max(maxSum,root->val);
            return root->val;
        }else{
            int sum = max(left,right) + root->val;
             maxSum = max(maxSum,sum);
             return sum;
        }

    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        solve(root,maxSum);
        return maxSum;
    }
};