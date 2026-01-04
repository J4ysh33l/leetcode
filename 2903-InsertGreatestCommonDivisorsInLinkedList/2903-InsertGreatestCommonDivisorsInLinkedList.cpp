// Last updated: 05/01/2026, 00:03:48
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
    int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a % b);    
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode*curr=head;
        while(curr && curr->next){
            int divi=gcd(curr->val,curr->next->val);
            ListNode* temp= new ListNode(divi);
            ListNode* next= curr->next;
            curr->next=temp;
            temp->next=next;
            curr=next;
        }
        return head;
    }
};