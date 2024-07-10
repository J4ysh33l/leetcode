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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL|| left == right){
            return head;
        }

        ListNode*curr=head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        // right= right-left;
        for(int i=1;i<left;i++){
            prev=curr;
            curr=curr->next;
        }
        ListNode* next= curr->next;
        for (int i = 0; i < right - left; ++i){
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            // right--;
        }
        return dummy.next;
    }
};