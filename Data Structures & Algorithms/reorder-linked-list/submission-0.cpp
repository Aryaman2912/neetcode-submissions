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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr or head->next == nullptr)
            return head;
        ListNode* cur = head->next;
        ListNode* prev = head;
        while(cur){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        head->next = nullptr;
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast and fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = slow->next;
        slow->next = nullptr;
        head2 = reverseList(head2);
        slow = head;
        fast = head2;
        ListNode* head3 = head;
        ListNode* end = head3;
        head = head->next;
        bool one = false;
        while(slow){
            cout << slow->val << " ";
            slow = slow->next;
        }
        cout << endl;
        while(fast){
            cout << fast->val << " ";
            fast = fast->next;
        }
        cout << endl;
        while(head and head2){
            if(one){
                end->next = head;
                head = head->next;
            } else {
                end->next = head2;
                head2 = head2->next;
            }
            end = end->next;
            one = !one;
        }
        if(head)
            end->next = head;
        if(head2)
            end->next = head2;
        head = head3;
    }
};
