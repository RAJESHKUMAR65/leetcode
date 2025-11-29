class Solution {
public:
    int solveUsingRecursion(string &s1,string &s2,int i,int j){
       if(i>=s1.length()) return 0;
       if(j>=s2.length()) return 0;
       int len=0;
       if(s1[i]==s2[j]){
          len=1+solveUsingRecursion(s1,s2,i+1,j+1);
       }else{
         len=0+max(solveUsingRecursion(s1,s2,i+1,j),solveUsingRecursion(s1,s2,i,j+1));
       }
       return len;
    }

    int solveUsingMemo(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        if(i>=s1.length()) return 0;
        if(j>=s2.length()) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int len=0;
        if(s1[i]==s2[j]){
            len=1+solveUsingMemo(s1,s2,i+1,j+1,dp);
        }else{
            len=0+max(solveUsingMemo(s1,s2,i+1,j,dp),solveUsingMemo(s1,s2,i,j+1,dp));
        }
        dp[i][j]=len;
        return dp[i][j];
    }

    int longestPalindromeSubseq(string s) {
       string s1=s;
       string s2=s;
       reverse(s2.begin(),s2.end());
       int i=0;
       int j=0;
      // int ans=solveUsingRecursion(s1,s2,i,j);
      vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
    int ans=solveUsingMemo(s1,s2,i,j,dp);
       return ans;
        
    }
};