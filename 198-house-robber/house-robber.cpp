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
   
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        int ans= memo(nums,0,dp);
        return ans;
    }
};