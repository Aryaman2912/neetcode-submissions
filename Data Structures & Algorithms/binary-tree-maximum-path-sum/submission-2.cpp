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
    int res;
    int helper(TreeNode* root){
        if(!root)
            return -2000;
        int l1 = helper(root->left);
        int l2 = helper(root->right);
        int maxval = max(root->val, root->val + max(l1,l2));
        res = max(res, max(maxval, max(root->val + l1 + l2, max(l1,l2))));
        return maxval;
    }
    int maxPathSum(TreeNode* root) {
        res = -2000;
        helper(root);
        return res;
    }
};