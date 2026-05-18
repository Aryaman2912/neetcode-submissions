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
            return 0;
        int l1 = max(0,helper(root->left));
        int l2 = max(0,helper(root->right));
        res = max(res, root->val + l1 + l2);
        return root->val + max(l1,l2);
    }
    int maxPathSum(TreeNode* root) {
        res = INT_MIN;
        helper(root);
        return res;
    }
};