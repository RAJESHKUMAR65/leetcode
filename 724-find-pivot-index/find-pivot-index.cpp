class Solution {
public:
    int sum(vector<int> &nums,int start ,int end)
    {
        int sum=0;
        
        for(int i=start;i<=end;i++)
        {
          sum=sum+nums[i];
        }
        return sum;
    }
    int pivotIndex(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        int leftsum;
        int rightsum;
        for(int i=0;i<nums.size();i++)
        {
             if(i==0 )
             {
                leftsum=0;
                rightsum=sum(nums,i+1,right);
             }
            else if(i==nums.size()-1)
             {
                rightsum=0;
                leftsum=sum(nums,left,i-1);
             }
             else
             {
                leftsum=sum(nums,left,i-1);
                rightsum=sum(nums,i+1,right);
             
             }
                
 
            
           if(leftsum==rightsum)
           {
            return i;
           }

        }
       
        
            return -1;
    
    }
};