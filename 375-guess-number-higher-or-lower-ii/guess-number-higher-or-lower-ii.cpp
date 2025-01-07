class Solution {
public:
   int solveUsingRecursion(int n,int s,int e){
    if(s>=e){
         return 0;
    }

    int ans=INT_MAX;
    for(int i=s;i<=e;i++){
        ans=min(ans,i+max(solveUsingRecursion(n,s,i-1),solveUsingRecursion(n,i+1,e)));
    }
    return ans;
   }
   int solveUsingMemo(int n,int s,int e,vector<vector<int>>&dp){
        if(s>=e){
         return 0;
     }

    int ans=INT_MAX;
    if(dp[s][e]!=-1){
        return dp[s][e];
    }
    for(int i=s;i<=e;i++){
        ans=min(ans,i+max(solveUsingMemo(n,s,i-1,dp),solveUsingMemo(n,i+1,e,dp)));
    }
    return dp[s][e]= ans;
   }
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        int ans=solveUsingMemo(n,1,n,dp);
        return ans;
    }
};