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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        vector<int>llarr;
        ListNode* temp=head;
        while(temp!=NULL){
            llarr.push_back(temp->val);
            temp=temp->next;}
      
       stack<int>st;
       st.push(0);
       int n=llarr.size();
       for(int i=n-1;i>=0;i--){
          while(st.size()!=1&&st.top()<=llarr[i]){
            st.pop();
          }
          ans.push_back(st.top());
          st.push(llarr[i]);
       }
       reverse(ans.begin(),ans.end());
       return ans;
        
    }
};