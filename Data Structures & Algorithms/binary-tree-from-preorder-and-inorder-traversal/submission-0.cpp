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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int l1, int r1, int l2, int r2){
        if(l1 > r1)
            return nullptr;
        TreeNode *node = new TreeNode(preorder[l1]);
        int div1, div2;
        int x = l2;
        while(inorder[x] != preorder[l1])
            x++;
        div2 = x;
        div1 = (l1 + x - l2);
        node->left = helper(preorder, inorder, l1 + 1, div1, l2, div2-1);
        node->right = helper(preorder, inorder, div1 + 1, r1, div2 + 1, r2);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return helper(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};