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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        while(temp and n >= 0){
            temp = temp->next;
            n--;
        }
        if(temp == nullptr and n == 0)
            return head->next;
        ListNode* temp2 = head;
        while(temp){
            temp = temp->next;
            temp2 = temp2->next;
        }
        if(temp2->next)
            temp2->next = temp2->next->next;
        return head;
    }
};
