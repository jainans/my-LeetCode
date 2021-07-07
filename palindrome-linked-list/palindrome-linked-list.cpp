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
    ListNode* rev(ListNode* head){
        ListNode* prev =NULL;
        ListNode* nex;
        ListNode* curr = head;
        while(curr){
            nex = curr->next;
            curr->next = prev;
            prev= curr;
            curr = nex;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slo = head;
        ListNode* fst = head;
        ListNode* prev=NULL;
        while(fst!=NULL && fst->next!=NULL){
            prev = slo;
            slo= slo->next;
            fst = fst->next->next;
        }
        if(prev==NULL)
            return true;
        prev->next = NULL;
        ListNode* get = rev(slo);
        while(head!=NULL){
            if(head->val==get->val){
                head = head->next;
                get = get->next;
            }
            else
                return false;
        }
        return true;
        
    }
};