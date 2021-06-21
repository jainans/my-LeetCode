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
    void mergeTwo(ListNode*& A, ListNode*& B){
        ListNode* head= A;
        ListNode* prev= NULL;
        while(head!=NULL && B!=NULL){
            if(B->val>=head->val){
                prev = head;
                head=head->next;
            }
            else{
                if(prev==NULL){
                    ListNode* curr = B;
                    B= B->next;
                    curr->next = head;
                    A = curr;
                    prev = curr;
                    
                }
                else{
                   ListNode* curr = B;
                    B= B->next;
                    prev->next = curr;
                    curr->next = head;
                    prev = curr;
                }
            }
        }
        if(B!=NULL){
            if(prev==NULL)
                A= B;
            else
            prev->next = B;
        }
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0)
            return NULL;
        if(n==1)
            return lists[0];
        for(int i=1; i<n; i++){
            mergeTwo(lists[0], lists[i]);
        }
        return lists[0];
    }
};