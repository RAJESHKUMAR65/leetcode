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


 class compare{
    public:
    bool operator()(Listval;

    }Node *a ,ListNode *b){
        return a->val > b->
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,compare>minHeap;
        // phele kitne first element ko insert krna hei
        // sare linklist ka first element 
        int k=lists.size();
       if(k==0){
        return NULL;
       }
       // first element of each linklist ko heap mai insert krna hei
       // 
    for(int i=0 ;i<k;i++){
        // manine phele check kiya kei linkist ka phela pointer
        //null toh nhi hei
        //fir usey insert kr diya ,cool acha kiya
        if(lists[i]!=NULL)
        {
          minHeap.push(lists[i]);
        }
    }
    ListNode* head=NULL;
    ListNode* tail=NULL;

    while(!minHeap.empty())
    {
        ListNode *top=minHeap.top();
        minHeap.pop();
        //temp tumra phela element ho bhi skta or nhi bhi ho sktahei

        if(head==NULL){
            //top mera first element hei
            head=top;
            tail=top;
            // agar next element exit krta hei toh usey
            //minHeap mai daal do
            if(tail->next!=NULL)
            {
                minHeap.push(tail->next);
            }
        }
        else{
            //first element nhi hei
            tail->next=top;
            tail=top;
            if(tail->next!=NULL){
                minHeap.push(tail->next);
            }


        }

    }
    return head;
 
    }
};