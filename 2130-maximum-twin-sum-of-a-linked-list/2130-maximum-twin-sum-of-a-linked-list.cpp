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
    ListNode* findmid(ListNode* head){
        ListNode* fast= head;
        ListNode* slow= head;

        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    ListNode* revList(ListNode* head){
        ListNode* curr=head;
        ListNode* next;
        ListNode* prev= NULL;
        while(curr){
            next=curr->next;
            curr->next= prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* mid = findmid(head);
        mid = revList(mid);
        ListNode* curr = head;
        int maxSum=INT_MIN;
        while(mid && curr){
            maxSum= max(mid->val+curr->val,maxSum);
            mid=mid->next;
            curr=curr->next;
        }
        return maxSum;
    }
};