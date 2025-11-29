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
    int solveUsingTab(string &s1,string &s2){
        vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,0));
        for(int i=s1.length()-1;i>=0;i--){
            for(int j=s2.length()-1;j>=0;j--){
                int len=0;
                if(s1[i]==s2[j]){
                    len=1+dp[i+1][j+1];
                }else{
                    len=0+max(dp[i][j+1],dp[i+1][j]);
                }
                dp[i][j]=len;
            }
        }
        return dp[0][0];
    }
    int solveUsingSo(string &s1,string &s2){
      vector<int>curr(s2.length()+1,0);
      vector<int>next(s2.length()+1,0);
      for(int i=s1.length()-1;i>=0;i--){
        for(int j=s2.length()-1;j>=0;j--){
            int len=0;
            if(s1[i]==s2[j]){
                len=1+next[j+1];
            }else{
                len=0+max(next[j],curr[j+1]);
            }
            curr[j]=len;
        }
        next=curr;
      }
      return curr[0];
    }

    int longestPalindromeSubseq(string s) {
       string s1=s;
       string s2=s;
       reverse(s2.begin(),s2.end());
       int i=0;
       int j=0;
      // int ans=solveUsingRecursion(s1,s2,i,j);
     // vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
    //int ans=solveUsingMemo(s1,s2,i,j,dp);
    int ans=solveUsingSo(s1,s2);
       return ans;
        
    }
};