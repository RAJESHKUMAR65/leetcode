/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode *,bool> table;
        ListNode * temp=head;
        while(temp!=NULL)
        {
            if(table[temp]==false)
            {
                table[temp]=true;
            }
            else
            {
                // already present hei cycle hei
                return true;
            }
            temp=temp->next;

        }
        // loop end matlab cycle nhi hei
        return false;
        
    }
};