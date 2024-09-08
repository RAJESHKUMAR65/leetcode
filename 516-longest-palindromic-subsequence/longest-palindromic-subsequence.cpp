class Solution {
public:
int solveUsingRecursion(string s,int i,int j){
    if(i>j){
        return 0;
    }
    if(i==j && s[i]==s[j]){
        return 1;
    }
    int ans=INT_MIN;

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
    if(i==j && s[i]==s[j]){
        return 1;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=INT_MIN;

    if(s[i]==s[j]){
         ans=2+solveUsingMemo(s,i+1,j-1,dp);
    }
    else{
          ans=0+max(solveUsingMemo(s,i+1,j,dp), solveUsingMemo(s,i,j-1,dp));
      }
      dp[i][j]=ans;

      return dp[i][j];

}
    int longestPalindromeSubseq(string s) {
       if(s.length()==1){
        return 1;
       }
        int i=0;
        int j=s.length()-1;
        //return solveUsingRecursion(s,i,j);
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),-1));
        return solveUsingMemo(s,i,j,dp);
    }
};