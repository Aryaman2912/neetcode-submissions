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

class Codec {
public:
    string int_to_string(int val){
        string x = "";
        bool neg = (val < 0);
        // cout << val << " ";
        val = abs(val);
        while(val){
            x.push_back('0' + val % 10);
            val /= 10;
        }
        if(neg)
            x.push_back('-');
        reverse(x.begin(), x.end());
        // cout << x << endl;
        return x;
    }
    
    int string_to_int(string val){
        if(val == "null")
            return INT_MIN;
        int res = 0;
        int i = (val[0] == '-' ? 1 : 0);
        for(; i < val.size(); i++){
            res = 10 * res + (val[i] - '0');
        }
        res *= (val[0] == '-' ? -1 : 1);
        // cout << val << " " << res << endl;
        return res;
        
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int nulls = 0;
            for(int i = 0; i < n; i++){
                TreeNode *node = q.front();
                q.pop();
                if(!node){
                    res += "null,";
                    continue;
                }
                res += int_to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
            if(nulls == n)
                break;
        }
        res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>vals;
        string temp;
        for(int i = 0; i < data.size(); i++){
            if(data[i] == ','){
                vals.push_back(temp);
                temp = "";
            } else {
                temp.push_back(data[i]);
            }
        }
        if(!vals.size())
            return nullptr;
        vector<TreeNode*>nodes;
        TreeNode* root = new TreeNode(string_to_int(vals[0]));
        nodes.push_back(root);
        for(int i = 1; i < vals.size(); i++){
            int par = (i - 1) / 2;
            TreeNode* node = nullptr;
            if(string_to_int(vals[i]) == INT_MIN)
                continue;
            node = new TreeNode(string_to_int(vals[i]));
            if(2 * par + 1 == i)
                nodes[par]->left = node;
            if(2 * par + 2 == i)
                nodes[par]->right = node;
            nodes.push_back(node);
        }
        return root;
    }
};
