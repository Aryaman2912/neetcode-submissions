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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        ListNode* end;
        if(list1->val < list2->val){
            end = list1;
            list1 = list1->next;
        } else {
            end = list2;
            list2 = list2->next;
        }
        ListNode* head = end;
        while(list1 and list2){
            if(list1->val < list2->val){
                end->next = list1;
                end = list1;
                list1 = list1->next;
            } else {
                end->next = list2;
                end = list2;
                list2 = list2->next;
            }
        }
        if(list1)
            end->next = list1;
        if(list2)
            end->next = list2;
        return head;
    }
};
