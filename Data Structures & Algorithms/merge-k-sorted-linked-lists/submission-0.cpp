/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Compare {
public:
    bool operator()(ListNode *a, ListNode *b){
        if (a->val > b->val) {
            return true;
        }
        return false;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare>pq;
        int n = lists.size();
        for(int i = 0; i < n; i++){
            pq.push(lists[i]);
        }
        ListNode *head = nullptr, *end = nullptr;
        while(!pq.empty()){
            ListNode *node = pq.top();
            pq.pop();
            if(node->next){
                pq.push(node->next);
            }
            if(head == nullptr){
                head = node;
                end = node;
                continue;
            }
            end->next = node;
            end = end->next;
        }
        return head;
    }
};
