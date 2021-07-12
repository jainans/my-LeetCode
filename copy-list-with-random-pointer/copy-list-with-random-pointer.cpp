/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //the method that u used was inefficient 
        //efficient method is to not destroy original one
        if(head==NULL)
            return NULL;
        Node* curr =head;
        Node* nex = curr->next;
        while(curr!=NULL){
            Node* p=  new Node(curr->val);
            curr->next = p;
            p->next = nex;
            curr = nex;
            nex = (curr) ? curr->next : NULL;
        }
        Node* p= head;
        while(p!=NULL){
            p->next->random = (p->random) ? p->random->next : NULL;
            p = p->next->next;
        }
        Node* temp = new Node(-1);
        Node* cuu = temp;
        Node* pp = head;
        Node* nexx;
        while(pp){
            cuu->next = pp->next;
            nexx = pp->next->next;
            cuu = pp->next;
            pp->next = nexx;
            pp=  nexx;
        }
        return temp->next;
    }
};