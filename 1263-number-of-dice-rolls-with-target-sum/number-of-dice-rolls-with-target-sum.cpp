class Solution {
public:
   const int mod=1e9+7;
// normal no of ways question using for loops
    int solveUsingRecursion(int n,int k,int target){
        if(n==0 && target==0)return 1;
        if(n==0 && target!=0)return 0;
        if(n!=0 && target==0)return 0;
        int ans=0;
        for(int i=1;i<=k;i++){
           ans+=solveUsingRecursion(n-1,k,target-i); 
        }
        return ans;
    }
    int solveUsingMemo(int n,int k,int target,vector<vector<int>>&dp){
        if(n==0 && target==0)return 1;
        if(n==0 && target!=0)return 0;
        if(n!=0 && target==0)return 0;
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        int ans=0;
        for(int i=1;i<=k;i++){
            if(target-i>=0){
           ans=(ans+solveUsingMemo(n-1,k,target-i,dp))%mod; }
        }
         dp[n][target]=ans;
         return dp[n][target];
    }
    int solveUsingTab(int n,int k,int target){
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int t=1;t<=target;t++){
                int ans=0;
                for(int j=1;j<=k;j++){
                    if(t-j>=0){
                ans=(ans+dp[i-1][t-j])%mod; }
                }
                dp[i][t]=ans;
                
            }
        }
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
     // int ans=solveUsingRecursion(n,k,target);
    // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
    // int ans=solveUsingMemo(n,k,target,dp);
    int ans=solveUsingTab(n,k,target);
      return ans;  
    }
};