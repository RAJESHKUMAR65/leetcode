class Solution {
public:
    bool checksubarray(vector<int>&nums,int i,int sum,vector<vector<int>>&dp){
        if(sum==0){
            return true;
        }
        if(sum<0){
            return false;
        }
        if(i>=nums.size()){
            return false;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int include=checksubarray(nums,i+1,sum-nums[i],dp);
        int exclude=checksubarray(nums,i+1,sum,dp);
        return dp[i][sum]=(include || exclude);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        ;
       for(int i=0;i<nums.size();i++){
        sum+=nums[i];
       } 
       if(sum&1) return false;
       sum=sum/2;
       int i=0;
       vector<vector<int>>dp(nums.size()+1,vector<int>(sum+1,-1));
       bool ans=checksubarray(nums,i,sum,dp);
       return ans;
    }
};