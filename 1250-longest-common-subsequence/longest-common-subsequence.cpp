class Solution {
public:
 int solveUsingRecursion(int i,int j,string &text1,string &text2){
    if(i>=text1.size())return 0;
    if(j>=text2.size())return 0;
    int maxLength=0;
    if(text1[i]==text2[j]){
        maxLength=1+solveUsingRecursion(i+1,j+1,text1,text2);
    }else{
        maxLength=0+max(solveUsingRecursion(i+1,j,text1,text2),solveUsingRecursion(i,j+1,text1,text2));
    }
    return maxLength;
 }

int solveUsingMemo(int i,int j,string &text1,string &text2,vector<vector<int>>&dp){
    if(i>=text1.size())return 0;
    if(j>=text2.size())return 0;
    int maxLength=0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(text1[i]==text2[j]){
        maxLength=1+solveUsingMemo(i+1,j+1,text1,text2,dp);
    }else{
        maxLength=0+max(solveUsingMemo(i+1,j,text1,text2,dp),solveUsingMemo(i,j+1,text1,text2,dp));
    }
     dp[i][j]=maxLength;
     return dp[i][j];
 }
 int solveUsingtab(string &text1,string &text2){
    int n1=text1.size();
    int n2=text2.size();
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
    for(int i=n1-1;i>=0;i--){
        for(int j=n2-1;j>=0;j--){
            int maxLength=0;
            if(text1[i]==text2[j]){
               maxLength=1+dp[i+1][j+1];
            }else{
                maxLength=0+max(dp[i+1][j],dp[i][j+1]);
            }
            dp[i][j]=maxLength;
        }
    }
    return dp[0][0];
 }
    int longestCommonSubsequence(string text1, string text2) {

       // int ans=solveUsingRecursion(0,0,text1,text2);
       vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,-1));
      // int ans=solveUsingMemo(0,0,text1,text2,dp);
      int ans=solveUsingtab(text1,text2);
        return ans;
    }
};