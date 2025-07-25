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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr)
        {
            ListNode* nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        //curr->next=prev;
        //prev=curr;
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head && !head->next)
         return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* second=reverse(slow->next);
        ListNode* first=head;
        //ListNode* second=slow->next;
        ListNode* newhead=second;
        while(second!=NULL)
        {
            if(first->val!=second->val)
            {
                reverse(newhead);
                return false;
            }
            else
            {
                first=first->next;
                second=second->next;
            }
        }
        reverse(newhead);
        return true;
    }
};