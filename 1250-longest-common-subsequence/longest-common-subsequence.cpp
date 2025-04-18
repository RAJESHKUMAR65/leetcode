class Solution {
public:
 int solveUsingRecursion(string &text1,string text2,int i,int j){
    if(i==text1.size()){
        return 0;
    }
    if(j==text2.size()){
        return 0;
    }
    int ans=0;
    if(text1[i]==text2[j]){
       ans=1+solveUsingRecursion(text1,text2,i+1,j+1);
    }
    else{
         ans=0+max(solveUsingRecursion(text1,text2,i+1,j),solveUsingRecursion(text1,text2,i,j+1));
    }
    return ans;
 }

 int solveUsingMemo(string &text1,string text2,int i,int j,vector<vector<int>>&dp){
    if(i==text1.size()){
        return 0;
    }
    if(j==text2.size()){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=0;
    if(text1[i]==text2[j]){
       ans=1+solveUsingMemo(text1,text2,i+1,j+1,dp);
    }
    else{
         ans=0+max(solveUsingMemo(text1,text2,i+1,j,dp),solveUsingMemo(text1,text2,i,j+1,dp));
    }
    return dp[i][j]=ans;
 }
 

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size(),-1));
        int ans=solveUsingMemo(text1,text2,0,0,dp);
        return ans;
    }
};