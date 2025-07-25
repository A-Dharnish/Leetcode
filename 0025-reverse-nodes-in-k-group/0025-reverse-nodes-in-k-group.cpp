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
    ListNode* rev(ListNode* head)
    {   
        if(head->next==NULL)
         return head;
        ListNode* prev=NULL;
        ListNode* curr= head;
        while(curr)
        {
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
            //nextNode=curr->next;
        }
        return prev;
    }
    ListNode* getKthNode(ListNode* temp,int k)
    {
        while(temp && k>1)
        {
            temp=temp->next;
            k--;
        }
        k--;
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode* temp=head;
      ListNode* prev=NULL;
      while(temp!=NULL)
      {
      ListNode* kn=getKthNode(temp,k);
      if(kn==NULL)
      {
        if(prev)
          prev->next=temp;
          break;
      }
      else
      {
        ListNode* nextNode=kn->next;
        kn->next=NULL;
        ListNode* ans=rev(temp);
        if(temp==head)
          head=ans;
        else
        {    
            prev->next=ans;
        }
        prev=temp;
        temp=nextNode;
      }
      }
    
      return head;
    }
};