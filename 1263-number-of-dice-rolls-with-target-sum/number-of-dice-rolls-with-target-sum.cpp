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
  int solveUsingtab(int n,int k ,int target){
    vector<vector<int>>dp(n+1,vector<int>(target+1,0));
    dp[0][0]=1;
    for(int dice=1;dice<=n;dice++){
        for(int j=1;j<=target;j++){
            long long ans=0;
           for(int i=1;i<=k;i++){
            if(j-i>=0){
                ans= (ans%mod+dp[dice-1][j-i]%mod )% mod;
            }
              
           }
          dp[dice][j]=ans;
    
        }
        
    }
    return dp[n][target];
  }
    int numRollsToTarget(int n, int k, int target) {
       vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
    //   int ans=recursion(n,k,target);
    //   return ans;
        //  
    int ans=solveUsingtab(n, k,target);
    return ans;
    }
};