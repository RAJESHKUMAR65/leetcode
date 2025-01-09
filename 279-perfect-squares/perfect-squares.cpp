class Solution {
public:
   int solveUsingRecursion(int n){
       if(n==0){
        return 0;
       }
       if(n<0){
        return INT_MAX;
       }
       int ans=INT_MAX;
       for(int i=1;i*i<=n+1;i++){
         int recans=solveUsingRecursion(n-i*i);
          if(recans!=INT_MAX){
            ans=min(ans,1+recans);
          }
       }
       return ans;
   }
   int solveUsingMemo(int n,vector<int>&dp){
       if(n==0){
        return 0;
       }
       if(n<0){
        return INT_MAX;
       }
       if(dp[n]!=-1){
        return dp[n];
       }
       int ans=INT_MAX;
       for(int i=1;i*i<=n+1;i++){
         int recans=solveUsingMemo(n-i*i,dp);
          if(recans!=INT_MAX){
            ans=min(ans,1+recans);
          }
       }
       return dp[n]=ans;
   }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        int ans=solveUsingMemo(n,dp);
        return ans;
    }
};