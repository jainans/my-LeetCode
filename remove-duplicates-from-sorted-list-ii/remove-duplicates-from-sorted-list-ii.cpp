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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* gprev = new ListNode(-200);
        
        ListNode* ans=  gprev;
        ListNode* prev =gprev;
        ListNode* curr =head;
        ListNode* nex;
        while(curr){
            nex = curr->next;
            if(curr->val!=prev->val && (nex==NULL || nex->val!=curr->val)){
                ListNode* p=  new ListNode(curr->val);
                gprev->next =p;
                gprev = p;
            }
            prev = curr;
            curr= nex;
        }
        return ans->next;
    }
};