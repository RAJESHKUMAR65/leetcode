class Solution {
public:

   int bs(vector<int>&nums){
    int s=0;
    int e=nums.size()-1;
    int ans=-1;
    while(s<=e){
        
       int mid=s+(e-s)/2;
       if(nums[mid]==mid){
        s=mid+1;
       }
       else if(nums[mid]==mid+1){
         ans=mid;
         e=mid-1;
       }

   }
    return ans;
   }
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=bs(nums); 
        if(ans==-1){
            return n;
        }else{
            return ans;
        }


    }
};