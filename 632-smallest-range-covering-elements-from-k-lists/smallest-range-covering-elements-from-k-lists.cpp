class info{
    public:
    int data;
    int row;
    int col;
    info(int val,int r,int c){
        data=val;
        row=r;
        col=c;
    }
};
class compare{
    public:
    bool operator()(info *a , info* b)
    {
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;

        priority_queue<info*,vector<info*>,compare>minHeap;
        int k =nums.size();
        //sare sorted array kei first element aagye min heap
        // sath mai minimum aur maximum element bhi nikal diya
        // first k element sey

        for(int i=0;i<k;i++ )
        {
            int element=nums[i][0];
        
            mini=min(mini,element);
            maxi=max(maxi,element);
            info *temp=new info(element,i,0);
            minHeap.push(temp);

        }
        int ansStart=mini;
        int ansEnd=maxi;

        // aab rest element ko handle krna hei
        while(!minHeap.empty())
        { 
          info* temp=minHeap.top();
          int topElement=temp->data;
          int topRow=temp->row;
          int topCol=temp->col;
          minHeap.pop();
          // muje mini mil gya toh mini ko update kro
          mini=topElement;
          // range change huwe hei ans ko update kro
          if(maxi-mini<ansEnd-ansStart)
          {// ye wale range choti hei 
            ansStart=mini;
            ansEnd=maxi;

         }
         //check kro aage element exit krte hei 
         if(topCol+1<nums[topRow].size()){
            info *temp=new info(nums[topRow][topCol+1],topRow,topCol+1);
            //dyan rakhne wale baat maxi ko update krna 
            // new element jo ayega woh ya toh maxi sey chhota hoga ya baara
           // agar bara toh maxi ko update kr dena
           maxi=max(maxi,nums[topRow][topCol+1]);
           minHeap.push(temp);
        }
         else{
            // agar element aage exit nhi krte hei toh break krdo
            break;
         }


        }
        vector<int> ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;

    }
};