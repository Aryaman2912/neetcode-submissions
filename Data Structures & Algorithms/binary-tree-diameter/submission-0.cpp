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
    int diameter;
    int recurse(TreeNode* root){
        if(!root)
            return 0;
        int l = recurse(root->left);
        int r = recurse(root->right);
        diameter = max(diameter, l + r + 1);
        return max(l,r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 1;
        recurse(root);
        return diameter - 1;
    }
};