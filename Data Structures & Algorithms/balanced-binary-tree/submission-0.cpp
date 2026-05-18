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
    bool balanced;
    int height(TreeNode* root){
        if(!root)
            return 0;
        int hl = height(root->left);
        int hr = height(root->right);
        if(abs(hl-hr) > 1)
            balanced = false;
        return max(hl,hr) + 1;
    }
    bool isBalanced(TreeNode* root) {
        balanced = true;
        height(root);
        return balanced;
    }
};
