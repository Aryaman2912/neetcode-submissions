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
    bool ans = true;
    vector<int>solve(TreeNode* root){
        if(!root)
            return {INT_MAX, INT_MIN};
        vector<int>v1,v2;
        v1 = v2 = {INT_MAX, INT_MIN};
        if(root->left)
            v1 = solve(root->left);
        if(root->right)
            v2 = solve(root->right);
        int maxl = v1[1], minr = v2[0];
        // cout << root->val << " " << v1[0] << " " << v1[1] << " " << v2[0] << " " << v2[1] << endl;
        if(root->val <= maxl or root->val >= minr)
            ans = false;
        int mini = INT_MAX, maxi = INT_MIN;
        mini = min(mini, min(root->val, min(v1[0], v2[0])));
        maxi = max(maxi, max(root->val, max(v1[1], v2[1])));
        return {mini, maxi};
    }
    bool isValidBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};
