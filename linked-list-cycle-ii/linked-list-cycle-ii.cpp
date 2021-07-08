/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slo = head;
        ListNode* fst = head;
        ListNode* p = NULL;
        while(fst && fst->next){
            slo = slo->next;
            fst = fst->next->next;
            if(slo==fst)
            {
                p = slo;
                break;
            }
        }
        if(p==NULL)
            return p;
        ListNode* q = head;
        while(q!=slo){
            q=q->next;
            slo =  slo->next;
        }
        return slo;
    }
};