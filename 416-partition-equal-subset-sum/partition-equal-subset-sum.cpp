class Solution {
public:
    bool isEqualSubsetSum(vector<int>&nums,int i,int target){
        if(target<0){
            return false;
        }
        if(i>=nums.size()&&target==0){
            return true;
        }
        if(target !=0 && i>=nums.size()){
            return false;
        }
        int include=isEqualSubsetSum(nums,i+1,target-nums[i]);
        int exclude=0+isEqualSubsetSum(nums,i+1,target);
        return (include||exclude);

    }
     bool isEqualSubsetSum_memo(vector<int>&nums,int i,int target,vector<vector<int>>&dp){
        if(target<0){
            return false;
        }
        if(i>=nums.size()&&target==0){
            return true;
        }
        if(target !=0 && i>=nums.size()){
            return false;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int include=isEqualSubsetSum_memo(nums,i+1,target-nums[i],dp);
        int exclude=0+isEqualSubsetSum_memo(nums,i+1,target,dp);
        return dp[i][target]=(include||exclude);

    }
    bool canPartition(vector<int>& nums) {
        int Total_sums=0;
        for(int i=0;i<nums.size();i++){
          Total_sums+=nums[i];
        }
        if(Total_sums&1){
            return false;
        }
       int sums=Total_sums/2;
       vector<vector<int>>dp(nums.size(),vector<int>(sums+1,-1));
       int ans=isEqualSubsetSum_memo(nums,0,sums,dp);
       return ans;
     
      
    }
};