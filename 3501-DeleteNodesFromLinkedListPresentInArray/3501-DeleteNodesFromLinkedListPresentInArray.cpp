// Last updated: 05/01/2026, 00:02:39
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> umap;
        for(auto num:nums){
            umap[num]++;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* prev= dummy;
        ListNode*curr= head;
        while(curr){
            if(umap.find(curr->val)==umap.end()){
                prev=curr;
                curr=curr->next;
            }else{
                ListNode*next=curr->next;
                curr->next=NULL;
                delete curr;
                prev->next=next;
                curr= next;
            }
        }
        head= dummy->next;
        delete dummy;
        return head;
    }
};