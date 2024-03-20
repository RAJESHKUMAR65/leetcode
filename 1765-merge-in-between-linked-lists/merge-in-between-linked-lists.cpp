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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *prev=list1;
        ListNode *fast=list1;
        ListNode *see=list2;
        while(a-1!=0)
        {
            prev=prev->next; 
            a--;
        }
        while(b!=0)
        {
            fast=fast->next;
            b--;
        }
        while(see->next!=NULL)
        {
            see=see->next;

        }
        prev->next=NULL;
        prev->next=list2;
        ListNode *last=fast->next;
        see->next=last;
        fast->next=NULL;
        return list1;
    }
};