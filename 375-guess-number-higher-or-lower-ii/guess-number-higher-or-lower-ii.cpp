class Solution {
public:
  int solveUsingRecursion(int s,int e){

    if(s>=e){
      return 0;
    }
    int ans=INT_MAX;
    for(int i=s;i<=e;i++){
        ans=min(ans,i+max(solveUsingRecursion(s,i-1),solveUsingRecursion(i+1,e)));
    }
    return ans;

  }
   int solveUsingMemo(int s,int e,vector<vector<int>>&dp){

    if(s>=e){
      return 0;
    }
    if(dp[s][e]!=-1){
        return dp[s][e];
    }
    int ans=INT_MAX;
    for(int i=s;i<=e;i++){
        ans=min(ans,i+max(solveUsingMemo(s,i-1,dp),solveUsingMemo(i+1,e,dp)));
    }
    dp[s][e]= ans;
    return dp[s][e];

  }
    int getMoneyAmount(int n) {
       //int ans=solveUsingRecursion(1,n); 
       vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       int ans=solveUsingMemo(1,n,dp);
       
       return ans;
    }
};