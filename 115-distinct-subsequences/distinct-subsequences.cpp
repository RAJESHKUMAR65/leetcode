class Solution {
public:
    int solveUsingRecursion(string s,string t,int i,int j){
        if(j==t.size()){
          return 1;
        }
        if(i==s.size()){
         return 0;
        }
        int ans=0;
       if(s[i]==t[j]){
        ans+=  solveUsingRecursion(s,t,i+1,j+1);
       }
      ans+= solveUsingRecursion(s,t,i+1,j);
      return ans;
      
    }
    int tp(string &s,string &t,int i,int j,vector<vector<int>>&dp){
        if(j==t.size()){
          return 1;
        }
        if(i==s.size()){
         return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
       if(s[i]==t[j]){
        ans+=   tp(s,t,i+1,j+1,dp);
       }
      ans+= tp(s,t,i+1,j,dp);
      return dp[i][j]=ans;
      
    }
    int numDistinct(string s, string t) {
        int i=0;
        int j=0;
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size(),-1));
     int ans=tp(s,t,i,j,dp);
        return ans;
    }
};