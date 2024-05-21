class Solution {
public:
     int pivot(vector<int>& nums)
     {
        int n=nums.size();
        int s=0;
        int e=n-1;
        int mid=s+(e-s)/2;
        while(s<=e)
        {
            if(s==e)
            {
                return s;
            }

            if(mid-1>=0 && nums[mid]<nums[mid-1] )
            {
               return mid-1;
            }
            else if(mid+1<n && nums[mid]>nums[mid+1]  )
            {
                return mid;
            }
            else if(nums[s]>nums[mid])
            {
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return -1;
     }
     int binarysearch(vector<int>& nums, int target,int s,int e)
     {
         
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]==target)
            {
                return mid;
            }

           else if(nums[mid]<target)
            {
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }

        return -1;
     }
    int search(vector<int>& nums, int target) {
        int pivotindex=pivot(nums);
        int n=nums.size();
       
        
         
         if(target>=nums[0] && target<=nums[pivotindex])
         {
            return binarysearch(nums,target,0,pivotindex);
         }
        else
         {
            return binarysearch(nums,target,pivotindex+1,n-1);
         }

            return -1;
        
    
       

    }
};