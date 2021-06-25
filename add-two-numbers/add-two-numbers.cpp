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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = l1;
        ListNode* temp = l2;
        int extra=0;
        int p;
         ListNode* prev;
        while(l1!=NULL && l2!=NULL){
            p = (l1->val+l2->val+extra)/10;
            l1->val= (l1->val+l2->val+extra)%10;
            l2->val = l1->val;
            extra = p;
            prev = l1;
            l1=l1->next;
            l2=l2->next;
        }
        int ns=0;
       
        while(l1){
            p = (l1->val+extra)/10;
            l1->val = (l1->val+extra)%10;
            extra= p;
            prev  = l1;
            l1 = l1->next;
            ns=1;
        }
        while(l2){
            p = (l2->val+extra)/10;
            l2->val = (l2->val+extra)%10;
            extra= p;
            prev = l2;
            l2 = l2->next;
            ns=2;
        }
        if(ns<=1 && extra!=0){
            ListNode* ex = new ListNode(extra);
            prev->next = ex;
            return ans;
        }
        else if(ns==2 && extra!=0){
            ListNode* ex = new ListNode(extra);
            prev->next = ex;
            return temp;
        }
        if(ns<=1)
        return ans;
        return temp;
    }
};