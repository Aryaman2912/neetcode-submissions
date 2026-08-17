/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node* , Node*>mp;
    void dfs(Node* node, Node* parent){
        Node* new_node = new Node(node->val);
        mp[node] = new_node;
        if(parent)
            parent->neighbors.push_back(new_node);
        for(auto it: node->neighbors){
            if(mp.find(it) == mp.end()){
                dfs(it, new_node);
            } else {
                new_node->neighbors.push_back(mp[it]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        Node* root = new Node(node->val);
        dfs(node, nullptr);
        for(auto it: node->neighbors){
            if(mp.find(it) == mp.end()){
                dfs(it, root);
            } else {
                root->neighbors.push_back(mp[it]);
            }
        }
        return root;
    }
};
