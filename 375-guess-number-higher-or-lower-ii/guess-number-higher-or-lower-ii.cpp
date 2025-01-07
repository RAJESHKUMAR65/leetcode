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

    int ans=INT_MAX;
    if(dp[s][e]!=-1){
        return dp[s][e];
    }
    for(int i=s;i<=e;i++){
        ans=min(ans,i+max(solveUsingMemo(s,i-1,dp),solveUsingMemo(i+1,e,dp)));
    }
    return dp[s][e]= ans;
   }
   int solveUsingTab(int n){
    vector<vector<int>>dp(n+3,vector<int>(n+4,0));
    for(int s=n;s>=1;s--){
        for(int e=1;e<=n;e++){
            int ans=INT_MAX;
            if(s>=e){
                continue;
            }
            else{
                  for(int i=s;i<=e;i++){
            
                     ans=min(ans,i+max(dp[s][i-1],dp[i+1][e]));
                }

            }
          
             
              
              dp[s][e]= ans;
        }

        }
        return dp[1][n];
    }
   
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        int ans=solveUsingTab(n);
        return ans;
    }
};