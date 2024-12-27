class Solution {
public:
    bool isEqualSubsetSum(vector<int>&nums,int i,int target){
       if(i>=nums.size()){
        return false;
       }
       if(target<0){
        return false;
       }
       if(target==0){
        return true;
       }
        int include=isEqualSubsetSum(nums,i+1,target-nums[i]);
        int exclude=0+isEqualSubsetSum(nums,i+1,target);
        return (include||exclude);

    }
     bool isEqualSubsetSum_memo(vector<int>&nums,int i,int target,vector<vector<int>>&dp){
        if(i>=nums.size()){
        return false;
       }
       if(target<0){
        return false;
       }
       if(target==0){
        return true;
       }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int include=isEqualSubsetSum_memo(nums,i+1,target-nums[i],dp);
        int exclude=0+isEqualSubsetSum_memo(nums,i+1,target,dp);
        return dp[i][target]=(include||exclude);

    }
    bool isEqualSubsetSum_tab(vector<int>&nums,int target){
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,0));
        for(int i=0;i<nums.size();i++){
            dp[i][0]=1;
        }
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=1;j<=target;j++){
                bool include=0;
                if(j-nums[i]>=0 ){
                   include=dp[i+1][j-nums[i]];
                   }
                   bool exclude=0+dp[i+1][j];
                   dp[i][j]=(include||exclude);
                }
                
            }
              return dp[0][target];
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
       int ans=isEqualSubsetSum_tab(nums,sums);
       return ans;
     
      
    }
};