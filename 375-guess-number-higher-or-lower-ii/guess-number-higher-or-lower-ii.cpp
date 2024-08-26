class Solution {
public:
    
    int solveUsingRecursion(int start,int end){
        if(start>=end){
            // start == end means single elment hei us
            // case mein penality nhi lage kei 
            // start grater end hojyega matlab kei invalid range hei
            return 0;
        }

        int ans=INT_MAX;
        for(int i=start;i<=end;i++){
            // haar ek i mein jaha kr 
            // max of uske left or right kei answer kei nikal  diya
            // sare answer kei minimum nikal diya kyuki minimum pucha hein
            // tracky question hei
            ans=min(ans,i+max(solveUsingRecursion(start,i-1),solveUsingRecursion(i+1,end)));
        }
        return ans;
    }
    int solveUsingMem(int start,int end,vector<vector<int>>&dp){
        if(start>=end){
            // start == end means single elment hei us
            // case mein penality nhi lage kei 
            // start grater end hojyega matlab kei invalid range hei
            return 0;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }

        int ans=INT_MAX;
        for(int i=start;i<=end;i++){
            // haar ek i mein jaha kr 
            // max of uske left or right kei answer kei nikal  diya
            // sare answer kei minimum nikal diya kyuki minimum pucha hein
            // tracky question hei
            ans=min(ans,i+max(solveUsingMem(start,i-1,dp),solveUsingMem(i+1,end,dp)));
        }
        return dp[start][end]=ans;
    }
    int getMoneyAmount(int n) {
      // int ans = solveUsingRecursion(1,n);
      vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
      int ans=solveUsingMem(1,n,dp);
       return ans; 
    }
};