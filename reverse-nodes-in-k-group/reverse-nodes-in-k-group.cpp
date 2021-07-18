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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prevadd= new ListNode(-1);
        ListNode* ans = prevadd;
        ListNode* q = head;
        int n=0;
        while(q){
            n++;
            q=q->next;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nex;
       for(int i=0; i<n/k; i++){
        int p = k;
        ListNode* fut = curr;
        while(p>0 && curr!=NULL){
                
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
            p--;
        }
        
        prevadd->next = prev;
        prev = NULL;
        prevadd= fut;
        }
        prevadd->next = curr;
        return ans->next;
    }
};