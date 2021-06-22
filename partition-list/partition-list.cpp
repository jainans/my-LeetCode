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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(-1);
        ListNode* ans = less;
        ListNode* prev= new ListNode(-200);
        ListNode* root = head;
        ListNode* add=NULL;
        while(root!=NULL){
            if(root->val>=x){
                if(prev->val==-200)
                    add = root;
                prev = root;
                root = root->next;
            }
            else{
                    less->next = root;
                    less = less->next;
                    prev->next = root->next;
                    root = root->next;
                    less->next = NULL;
            }
        }
        less->next = add;
        return ans->next;
    }
};