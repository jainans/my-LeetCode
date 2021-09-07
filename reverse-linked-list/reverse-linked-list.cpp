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
    // ListNode* reverse(ListNode* root, ListNode* prev){
    //     if(root->next==NULL){
    //         root->next =prev;
    //         return root;
    //     }
    //     ListNode* p = root->next;
    //     root->next =prev;
    //     return reverse(p, root);
    // }
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        
       ListNode* nex;
        while(curr){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
};