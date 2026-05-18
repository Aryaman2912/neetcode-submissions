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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *temp1 = l1, *temp2 = l2, *tail;
        while(temp1 and temp2){
            int sum = temp1->val + temp2->val + carry;
            carry = sum / 10;
            sum %= 10;
            temp1->val = sum;
            tail = temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1){
            int sum = temp1->val + carry;
            carry = sum / 10;
            sum %= 10;
            temp1->val = sum;
            tail = temp1;
            temp1 = temp1->next;
        }
        while(temp2){
            int sum = temp2->val + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode *new_node = new ListNode(sum);
            tail->next = new_node;
            tail = tail->next;
            temp2 = temp2->next;
        }
        if(carry){
            ListNode *new_node = new ListNode(carry);
            tail->next = new_node;
        }
        return l1;
    }
};
