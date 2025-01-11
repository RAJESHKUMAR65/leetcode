class Solution {
public:
   int solveUsingRecursion(vector<int>&nums,int curr,int prev){
    if(curr==nums.size()){
        return 0;
    }
     int include=0;
     if(prev==-1 || nums[prev]<nums[curr]){
        include=1+solveUsingRecursion(nums,curr+1,curr);
     }
     int exclude=0+solveUsingRecursion(nums,curr+1,prev);
     int ans=max(include,exclude);
     return ans;
   }

   int solveUsingMemo(vector<int>&nums,int curr,int prev,vector<vector<int>>&dp){
     if(curr==nums.size()){
        return 0;
    }
    if(prev!=-1&& dp[curr][prev+1]!=-1){
        return dp[curr][prev+1];
    }
     int include=0;
     if(prev==-1 || nums[prev]<nums[curr]){
        include=1+ solveUsingMemo(nums,curr+1,curr,dp);
     }
     int exclude=0+solveUsingMemo(nums,curr+1,prev,dp);
     int ans=max(include,exclude);
     return dp[curr][prev+1]=ans;
   }
    int lengthOfLIS(vector<int>& nums) {
        int curr=0;
        int prev=-1;
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        int ans =solveUsingMemo(nums,curr,prev,dp);
        return ans;
    }
};