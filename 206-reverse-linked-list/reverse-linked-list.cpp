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
   // recursive sol
    ListNode *reverse(ListNode *prev,ListNode *curr)
    {
        // base case
        if(curr==NULL)
         return prev;
        // processing
        ListNode *next=curr->next;
        curr->next=prev;
        return reverse(curr,next);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL;
        ListNode *curr=head;
        while(curr!=NULL)
        {
            ListNode *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
        
        
       // return reverse(prev,curr);
        
    }
};