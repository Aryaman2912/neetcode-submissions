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
        while(val){
            x.push_back('0' + val % 10);
            val /= 10;
        }
        reverse(x.begin(), x.end());
        return x;
    }
    
    int string_to_int(string val){
        if(val == "null")
            return INT_MIN;
        int res = 0;
        for(int i = 0; i < val.size(); i++){
            res = 10 * res + (val[i] - '0');
        }
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
                    nulls++;
                    q.push(nullptr);
                    q.push(nullptr);
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
        cout << res << endl;
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
        vector<TreeNode*>nodes(vals.size(), nullptr);
        TreeNode* root = new TreeNode(string_to_int(vals[0]));
        nodes[0] = root;
        for(int i = 0; i < vals.size(); i++){
            TreeNode *lchild = (2 * i + 1 < vals.size()) ? new TreeNode(string_to_int(vals[2 * i + 1])) : nullptr;
            TreeNode *rchild = (2 * i + 2 < vals.size()) ? new TreeNode(string_to_int(vals[2 * i + 2])) : nullptr;
            if(lchild and lchild->val != INT_MIN){
                nodes[i]->left = lchild;
                nodes[2 * i + 1] = lchild;
            }
            if(rchild and rchild->val != INT_MIN){
                nodes[i]->right = rchild;
                nodes[2 * i + 2] = rchild;
            }
        }
        return root;
    }
};
