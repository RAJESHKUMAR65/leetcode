class Solution {
public:
 const int mod=1e9+7;
  int recursion(int n,int k ,int target){
     
     if(target<0){
        return 0;
     }
     if(n==0 && target==0){
        return 1;
     }
     if(n==0 && target!=0){
        return 0;
     }
     if(n!=0 && target==0){
        return 0;
     }
     int ans=0;
     for(int i=1;i<=k;i++){
         ans= ans+recursion(n-1,k,target-i);
    }
    return ans;
  }
  long long solveUsingMemo(int n,int k,int target,vector<vector<int>>&dp){
     if(target<0){
        return 0;
     }
     if(n==0 && target==0){
        return 1;
     }
     if(n==0 && target!=0){
        return 0;
     }
     if(n!=0 && target==0){
        return 0;
     }
     if(dp[n][target]!=-1){
        return dp[n][target];
     }
     long long ans=0;
     for(int i=1;i<=k;i++){
         ans= (ans+solveUsingMemo(n-1,k,target-i,dp)) % mod;
    }
      dp[n][target]=ans;
    return (dp[n][target]%mod);
  
  }
    int numRollsToTarget(int n, int k, int target) {
       vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
    //   int ans=recursion(n,k,target);
    //   return ans;
         long long ans=solveUsingMemo(n,k,target,dp);
         return ans%mod;
    }
};