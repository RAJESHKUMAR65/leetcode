class Solution {
public:
   int solveUsingRecursion(vector<int>&nums,int i){
    if(i>=nums.size()){
        return 0;
    }
    int include=nums[i]+solveUsingRecursion(nums,i+2);
    int exclude=0+solveUsingRecursion(nums,i+1);
    int ans=max(include,exclude);
    return ans;
   }
   int memo(vector<int>&nums,int i,vector<int>&dp){
    if(i>=nums.size()){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int include=nums[i]+memo(nums,i+2,dp);
    int exclude=0+memo(nums,i+1,dp);
    int ans=max(include,exclude);
    dp[i]=ans;
    return ans;
   }
   int bottomup(vector<int>&nums){
    int next=0;
    int curr=0;
    int prev=0;
    for(int i=nums.size()-1;i>=0;i--){
        
            int include=nums[i]+next;
            int exclude=0+curr;
            int ans=max(include,exclude);
            prev=ans;
           next =curr;
           curr=prev;

        }
        return prev;
       
    
    
   }
   
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        int ans= bottomup(nums);
        return ans;
    }
};