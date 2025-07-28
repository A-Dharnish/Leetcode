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
        Node* temp=head;
        while(temp!=NULL)
        {
            Node* res=new Node(temp->val);
            res->next=temp->next;
            temp->next=res;
            temp=temp->next->next;
        }
        temp=head;
        while(temp!=NULL)
        {
           if(temp->random)
            temp->next->random=temp->random->next;
        temp=temp->next->next;
        }
        Node* dummy=new Node(-1);
        Node* res=dummy;
        temp=head;
        while(temp!=NULL)
        {
            dummy->next=temp->next;
            temp->next=temp->next->next;
            dummy=dummy->next;
            temp=temp->next;
        }
        return res->next;
    }
};