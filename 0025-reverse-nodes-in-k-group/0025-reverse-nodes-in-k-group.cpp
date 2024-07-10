
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) {
            return head;
        }

        // Count the number of nodes in the list
        ListNode* curr = head;
        int count = 0;
        while (curr != nullptr && count < k) {
            curr = curr->next;
            count++;
        }

        // If there are less than k nodes left, return head without reversing
        if (count < k) {
            return head;
        }

        // Reverse k nodes
        curr = head;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        count = 0;
        while (curr != nullptr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Recursively reverse the next group of k nodes
        if (next != nullptr) {
            head->next = reverseKGroup(next, k);
        }

        // prev is now the head of the reversed group
        return prev;
    }
};
