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
   int solveUsingTab(int n,int start,int end){
    vector<vector<int>>dp(n+2,vector<int>(n+2,0));

    for(int start=n;start>=1;start--){
        for(int end=1;end<=n;end++){
        if(start>=end){
           continue;
        }
        else{ 
            int ans=INT_MAX;
            for(int i=start;i<=end;i++){
            ans=min(ans,i+max(dp[start][i-1],dp[i+1][end]));}
            dp[start][end]=ans;
            }
               
        }
      
    }
    return dp[1][n];

   }
    int getMoneyAmount(int n) {
       // int ans=solveUsingRecursion(n,1,n);
       vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       int ans=solveUsingTab(n,0,n);
        return ans;
    }
};