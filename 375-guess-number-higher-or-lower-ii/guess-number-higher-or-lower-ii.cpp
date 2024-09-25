class Solution {
public:
   int solveUsingRecursion(int n,int start,int end){

    if(start>=end){
        return 0;
    }
    int ans=INT_MAX;
    for(int i=start;i<=end;i++){
        ans=min(ans,i+max(solveUsingRecursion(n,start,i-1),solveUsingRecursion(n,i+1,end)));
    }
    return ans;
   }
  
   int solveUsingMemo(int n,int start,int end,vector<vector<int>>&dp){

    if(start>=end){
        return 0;
    }
    if(dp[start][end]!=-1){
        return dp[start][end];
    }
    int ans=INT_MAX;
    for(int i=start;i<=end;i++){
        ans=min(ans,i+max(solveUsingMemo(n,start,i-1,dp),solveUsingMemo(n,i+1,end,dp)));
    }
   dp[start][end]=ans;
   return dp[start][end];
   }
    int getMoneyAmount(int n) {
       // int ans=solveUsingRecursion(n,1,n);
       vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       int ans=solveUsingMemo(n,0,n,dp);
        return ans;
    }
};