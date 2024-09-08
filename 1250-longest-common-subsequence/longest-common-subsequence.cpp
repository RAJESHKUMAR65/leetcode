class Solution {
public:

    int solveUsingRecursion(string text1,string text2,int i,int j){
        if(i>=text1.length() || j>=text2.length()){
            return 0;

        }
        // agar character same hein
        int ans=0;
        if(text1[i]==text2[j]){
           ans=1+solveUsingRecursion(text1,text2,i+1,j+1);
        }
        else{
           ans= 0+max(solveUsingRecursion(text1,text2,i+1,j),solveUsingRecursion(text1,text2,i,j+1));
        }

        return ans;
    }
    int solveUsingMemo(string &text1,string &text2,int i,int j,vector<vector<int>> &dp){

        if(i>=text1.length() || j>=text2.length()){
            return 0;

        }
        // agar character same hein
       
         if(dp[i][j]!=-1){
            return dp[i][j];
         }
            int ans=0;
        if(text1[i]==text2[j]){
           ans=1+solveUsingMemo(text1,text2,i+1,j+1,dp);
        }
        else{
           ans= 0+max(solveUsingMemo(text1,text2,i+1,j,dp),solveUsingMemo(text1,text2,i,j+1,dp));
        }
        dp[i][j]=ans;

        return dp[i][j];
    }
     
  int solveUsingTab(string &text1,string &text2){
    vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),0));
    for(int i=text1.size()-1;i>=0;i--){
        for(int j=text2.size()-1;j>=0;j--){
                int ans=0;
                if(text1[i]==text2[j]){
                ans=1+dp[i+1][j+1];
                }
                else{
                ans= 0+max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j]=ans;

               
        }
    }
     return dp[0][0];
  }
    int longestCommonSubsequence(string text1, string text2) {
        int i=0;
        int j=0;
       // return solveUsingRecursion(text1,text2,i,j);
        vector<vector<int>> dp(text1.length(),vector<int>(text2.length(),-1));
        return solveUsingMemo(text1,text2,i,j,dp);
    }
};