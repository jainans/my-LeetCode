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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* one = head;
        ListNode* two = head;
        ListNode* prev = NULL;
        for(int i=0; i<n; i++){
            two = two->next;
        }
        while(two!=NULL){
            prev = one;
            one = one->next;
            two = two->next;
        }
        if(prev==NULL)
        {
            ListNode* p = head->next;
            head->next=NULL;
            return p;
        }
        prev->next=one->next;
        one->next=NULL;
        return head;
    }
};