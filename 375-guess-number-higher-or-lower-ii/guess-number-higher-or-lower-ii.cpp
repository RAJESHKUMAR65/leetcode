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

    int solveUsingtab(int start,int end){
        int n=end;
        vector<vector<int>>dp(n+2,vector(n+2,0));
        for(int start=n;start>=1;start--){
            for(int end=1;end<=n;end++){
                  int ans=INT_MAX;
                  if(start>=end){
                    continue;
                  }
                  else{
                     for(int i=start;i<=end;i++){
                          ans=min(ans,i+max(dp[start][i-1],dp[i+1][end]));
                        }
                      dp[start][end]=ans;
                  }
                
        }
        
        }
        // kabhi kya return krna hei doubt ho toh intial fxn call dekh lena 
        // tabulation wale fxn mein
        return dp[1][n];
        }
    
    int getMoneyAmount(int n) {
      // int ans = solveUsingRecursion(1,n);
      vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
      int ans=solveUsingtab(1,n);
       return ans; 
    }
};