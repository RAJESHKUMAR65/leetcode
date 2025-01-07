class Solution {
public:
   int solveUsingRecursion(string &s,int i,int j){
     if(i>j){
        return 0;
     }
     int ans=0;
     if(s[i]==s[j]){
       ans=2+solveUsingRecursion(s,i+1,j-1);
     }
     else{
        ans=0+max(solveUsingRecursion(s,i+1,j),solveUsingRecursion(s,i,j-1));
     }
     return ans;
   }
   int solveUsingMemo(string &s,int i,int j,vector<vector<int>>&dp){
     if(i>j){
        return 0;
     }
     if(i==j){
        return 1;
     }
     int ans=0;
     if(dp[i][j]!=-1){
        return dp[i][j];
     }
     if(s[i]==s[j]){
       ans=2+solveUsingMemo(s,i+1,j-1,dp);
     }
     else{
        ans=0+max(solveUsingMemo(s,i+1,j,dp),solveUsingMemo(s,i,j-1,dp));
     }
     return dp[i][j]=ans;

   }
    int longestPalindromeSubseq(string s) {
        int i=0;
        int j=s.length()-1;
        
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=solveUsingMemo(s,i,j,dp);
        return ans;
    }
};