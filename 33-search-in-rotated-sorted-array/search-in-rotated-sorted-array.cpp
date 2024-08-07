class Solution {
public:
    int PivotIndex(vector<int> & nums){
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        while(s<e){
            if((mid+1<nums.size()) && nums[mid]>nums[mid+1]){
                return mid;
            }
            if((mid-1>=0) && nums[mid]<nums[mid-1]){
                return mid-1;
            }
            if(nums[s]>=nums[mid]){
                e=mid-1;
            }
            else //if(nums[mid]>nums[s])
            {
                s=mid;
            }
            mid=s+(e-s)/2;
        }
        return s;
    }
    int binarySearch(vector<int>&nums,int s,int e,int target){
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot =PivotIndex(nums);
         
         
        int n=nums.size()-1;
        if(target>=nums[0] && target<=nums[pivot]){
           int ans=binarySearch(nums,0,pivot,target);
           return ans;
         }
         if((pivot+1<=n)&&target>=nums[pivot+1] && target <=nums[n]){
           int ans=binarySearch(nums,pivot+1,n,target);
           return ans;
         }
        return -1;
    }
};