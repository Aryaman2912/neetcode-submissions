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
    TreeNode* lca;
    bool find(TreeNode* root, TreeNode* node){
        if(!root)
            return false;
        if(root == node)
            return true;
        return find(root->left, node) or find(root->right, node);
    }
    void recurse(TreeNode *root, TreeNode *p, TreeNode *q){
        if(!root)
            return;
        if(find(root, p) and find(root, q))
            lca = root;
        recurse(root->left, p, q);
        recurse(root->right, p, q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        recurse(root, p, q);
        return lca;
    }
};
