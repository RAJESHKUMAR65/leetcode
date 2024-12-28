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
    int solveUsingTab(int n,int k,int target){
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;
        for(int index=1;index<=n;index++){
            for(int t=1;t<=target;t++){
                    int ans=0;
                    for(int i=1;i<=k;i++){
                        if(index-1>=0 && t-i>=0){
                            ans= (ans+dp[index-1][t-i])%mod;}
                    
                    }
                     dp[index][t]=ans%mod;
            }
        }
        return dp[n][target];
    }
    int solveUsingso(int n,int k,int target){
        
        vector<int>prev(target+1,0);
        vector<int>curr(target+1,0);
        prev[0]=1;
        for(int index=1;index<=n;index++){
            for(int t=1;t<=target;t++){
                    int ans=0;
                    for(int i=1;i<=k;i++){
                        if(index-1>=0 && t-i>=0){
                            ans= (ans+prev[t-i])%mod;}
                    
                    }
                     curr[t]=ans%mod;
            }
            prev=curr;
        }
        return curr[target];
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        int ans=solveUsingso(n,k,target);
        return ans;
    }
};