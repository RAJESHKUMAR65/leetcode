class Solution {
public:

  int rec(vector<int>&nums,int i){
    if(i>=nums.size()){
        return 0;
    }
    int include=nums[i]+rec(nums,i+2);
    int exclude=0+rec(nums,i+1);
    return max(include,exclude);
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
    return dp[i]=max(include,exclude);
  }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        int i=0;
        int ans=memo(nums,i,dp);
        return ans;
    }
};