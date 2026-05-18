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
    int ind, kg, res;
    void inorder(TreeNode* root){
        if(!root)
            return;
        inorder(root->left);
        ind++;
        if(ind == kg)
            res = root->val;
        inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        kg = k;
        ind = 0;
        inorder(root);
        return res;
    }
};
