class Solution {
public:
   int houseRobber_recSoln(vector<int>&nums,int i){
    if(i>=nums.size()){
        return 0;
    }
    int amount_rob=INT_MIN;
    int include=nums[i]+houseRobber_recSoln(nums,i+2);
    int exclude=0+houseRobber_recSoln(nums,i+1);
    amount_rob=max(include,exclude);
    return amount_rob;
   }

   int houseRobber_topDownSoln(vector<int>&nums,int i,vector<int>&dp){
    if(i>=nums.size()){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int amount_rob=INT_MIN;
    int include=nums[i]+ houseRobber_topDownSoln(nums,i+2,dp);
    int exclude=0+ houseRobber_topDownSoln(nums,i+1,dp);
    amount_rob=max(include,exclude);
    return dp[i]=amount_rob;
   
   }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
    
       int ans= houseRobber_topDownSoln(nums,0,dp);
       return ans; 
    }
};