class Solution {
public:
bool solveUsingRecursion(int i,vector<int>&nums,int target){
   
    if(i>=nums.size()){
        return false;
    }
    if(target==0)return true;
    if(target<0)return false;
    int include=solveUsingRecursion(i+1,nums,target-nums[i]);
    int exclude=solveUsingRecursion(i+1,nums,target);
    return (include||exclude);
    
}
bool solveUsingMemo(int i,vector<int>&nums,int target,vector<vector<int>>&dp){
   
    if(i>=nums.size()){
        return false;
    }
    if(target==0)return true;
    if(target<0)return false;
    if(dp[i][target]!=-1){
        return dp[i][target];
    }
    int include=solveUsingMemo(i+1,nums,target-nums[i],dp);
    int exclude=solveUsingMemo(i+1,nums,target,dp);
    dp[i][target]= include||exclude;
    return dp[i][target];
    
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
           sum+=nums[i];
        }
        if(sum&1){
            return false;
        }
        // bool ans=solveUsingRecursion(0,nums,sum/2);
        // return ans;

        // memo
        int target=sum/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,-1));
      bool ans=solveUsingMemo(0,nums,target,dp);
      return ans;
    }
};