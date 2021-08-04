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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        int len=0;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* last = head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast && fast->next==NULL)
                last = fast;
            else if(fast && fast->next && fast->next->next==NULL)
                last = fast->next;
            
            len++;
        }
        if(fast==NULL)
            len=  len*2;
        else
            len = len*2+1;
        k = k%len;
        if(k==0)
            return head;
        ListNode* p = head;
        ListNode* prev=  NULL;
        
        for(int i=0; i<len-k; i++){
            prev = p;
            p = p->next;
            
        }
        last->next = head;
        prev->next=NULL;
        return p;
    }
};