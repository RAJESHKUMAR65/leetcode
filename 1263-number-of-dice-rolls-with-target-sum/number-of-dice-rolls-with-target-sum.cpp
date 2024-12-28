class Solution {
public:
  int mod=1e9+7;
    int solveUsingRecursion(int n,int k,int target) {
         if(target<0){
            return 0;
         }
         if(n==0 && target!=0){
            return 0;
         }
         if(n==0 && target==0){
            return 1;
         }
         int ans=0;
         for(int i=1;i<=k;i++){
           ans+= solveUsingRecursion(n-1,k,target-i);
         }
         return ans;
        
    }
    int solveUsingMemo(int n,int k,int target,vector<vector<int>>&dp) {
         if(target<0){
            return 0;
         }
         if(n==0 && target!=0){
            return 0;
         }
         if(n==0 && target==0){
            return 1;
         }
         if(dp[n][target]!=-1){
            return dp[n][target];
         }
         int ans=0;
         for(int i=1;i<=k;i++){
           ans= (ans+solveUsingMemo(n-1,k,target-i,dp))%mod;
         }
         return dp[n][target]=ans%mod;
        
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        int ans=solveUsingMemo(n,k,target,dp);
        return ans;
    }
};