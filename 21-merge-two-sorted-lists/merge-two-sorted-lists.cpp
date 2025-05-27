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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *temp1=list1;  
        ListNode *temp2=list2;
        if(temp1==NULL)return temp2;
        if(temp2==NULL)return temp1;
        ListNode *ans=new ListNode(-1);
        ListNode *mptr=ans;

        while(temp1!=NULL && temp2!=NULL){
              if(temp1->val<=temp2->val){
                  mptr->next=temp1;
                  mptr=temp1;
                  
                  temp1=temp1->next;
        
              }
              else{
                mptr->next=temp2;
                mptr=temp2;
                temp2=temp2->next;
                
                
              }
        }

        if(temp1!=NULL) mptr->next=temp1;
        if(temp2!=NULL)mptr->next=temp2;

        return ans->next;
         }
};