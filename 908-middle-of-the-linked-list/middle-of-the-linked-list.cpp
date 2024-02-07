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
    ListNode* middleNode(ListNode* head) {
      ListNode* slow=head;
      ListNode* fast=head;
      while(fast!=NULL)
      {
          fast=fast->next;
          // ek step chalne kei baad kei fast null toh nhi gya null->next nhi exist krta hei
          if(fast!=NULL)
          {
              fast=fast->next;
              // aab fast 2 step chal chuka hei aab slow ko ek step chalwo
              slow=slow->next;

          }
      } 
      return slow; 
        
    }
};