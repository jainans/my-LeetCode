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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nex;
        while(curr){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)
            return head;
        ListNode* prev = new ListNode(-600);
        ListNode* trk =prev;
        ListNode* nex;
        for(int i=0; i<left-1; i++){
            trk->next = head;
            nex = head->next;
            head->next = NULL;
            trk = trk->next;
            head = nex;
        }
        int len = right-left+1;
        ListNode* y = head;
        ListNode* u = NULL;
        for(int i=0; i<len; i++){
            u = y;
            y = y->next;
        }
        u->next = NULL;
        // prev->next, head, y
        ListNode* rev = reverse(head);
        ListNode* track = prev;
        while(track->next!=NULL)
            track = track->next;
        track->next = rev;
        while(track->next!=NULL)
            track=track->next;
        track->next = y;
        return prev->next;
    }
};