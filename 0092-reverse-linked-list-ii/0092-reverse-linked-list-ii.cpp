
class Solution {
    void reverseList(ListNode*head, ListNode*tail){
        ListNode*curr = head->next;
        ListNode*prev=head;
        ListNode*forward= NULL;
        while(prev!=tail){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        head->next=tail->next;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        ListNode dummy(0, head);
        ListNode* prevLeft = &dummy;

        for (int i = 1; i < left; ++i) {
            prevLeft = prevLeft->next;
        }

        ListNode* start = prevLeft->next;
        ListNode* end = start;
        for (int i = left; i < right; ++i) {
            end = end->next;
        }

        ListNode* afterRight = end->next;

        // Reverse the sublist
        reverseList(start, end);

        // Connect the reversed sublist back to the list
        prevLeft->next = end;
        start->next = afterRight;

        return dummy.next;
    }
};