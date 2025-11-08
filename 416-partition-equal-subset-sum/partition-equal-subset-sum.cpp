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
bool solveUsingTab(vector<int>&nums,int target){
    vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,0));
    int n=nums.size();
    for(int i=0;i<nums.size();i++){
        dp[i][0]=1;
    }
    for(int index=n-1;index>=0;index--){
        for(int t=1;t<=target;t++){
            int include=0;
            if(t-nums[index]>=0){
             include=dp[index+1][t-nums[index]];
            }
            
            int exclude=dp[index+1][t];
            dp[index][t]= include||exclude;
            
        }
    }
     return dp[0][target];
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
      bool ans=solveUsingTab(nums,target);
      return ans;
    }
};