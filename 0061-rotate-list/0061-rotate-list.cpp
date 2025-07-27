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
       ListNode* temp=head;
       if(head==NULL || head->next==NULL || k==0)
        return head;     
       int cnt=0;
       while(temp!=NULL)
       {
        cnt++;
        temp=temp->next;
       }
       if(k>=cnt)
        k=k%cnt;
      if(k==0) return head;
       temp=head;
       int i=1;
       while(i<cnt-k)
       {
       if(temp->next) temp=temp->next;
       else break;
       i++;
       }
       ListNode* newhead=temp->next;
       ListNode* curr=newhead;
       while(curr->next)
       {
        curr=curr->next;
       }
       curr->next=head;
       temp->next=NULL;
       return newhead;
    }
};