class Solution {
public:
    int solveUsingRecursion(string & word1,string &word2,int i,int j){

        //
        if(i==word1.length()){
            return word2.length()-j;
        }
        if(j==word2.length()){
            return word1.length()-i;
        }
        int ans=0;
        if(word1[i]==word2[j]){
            ans=0+solveUsingRecursion(word1,word2,i+1,j+1);
        }else{
            int insert=1+solveUsingRecursion(word1,word2,i,j+1);
            int deleted=1+solveUsingRecursion(word1,word2,i+1,j);
            int replaced=1+solveUsingRecursion(word1,word2,i+1,j+1);
            ans=min({insert,deleted,replaced});
        }
        return ans;
    }
    int solveUsingMemo(string & word1,string &word2,int i,int j,vector<vector<int>>&dp){
        if(i==word1.length()){
             return word2.length()-j;}
        if(j==word2.length()){
             return word1.length()-i;}
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(word1[i]==word2[j]){
          ans=solveUsingMemo(word1,word2,i+1,j+1,dp);
        }else{
            int insert=1+solveUsingMemo(word1,word2,i,j+1,dp);
            int deleted=1+solveUsingMemo(word1,word2,i+1,j,dp);
            int replaced=1+solveUsingMemo(word1,word2,i+1,j+1,dp);
             ans=min({insert,deleted,replaced});
        }
        dp[i][j]=ans;
        return ans;
    }
    int solveUsingTab(string & word1 ,string & word2){
        vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,0));
    
            for(int j=0;j<word2.length();j++){
                dp[word1.length()][j]=word2.length()-j;
            }
            for(int i=0;i<word1.length();i++){
                dp[i][word2.length()]=word1.length()-i;
            }

            for(int i=word1.length()-1;i>=0;i--){
                for(int j=word2.length()-1;j>=0;j--){
                    int ans=0;
                    if(word1[i]==word2[j]){
                        ans=0+dp[i+1][j+1];
                    }else{
                        int inserted=1+dp[i][j+1];
                        int deleted=1+dp[i+1][j];
                        int replaced=1+dp[i+1][j+1];
                        ans=min({inserted,deleted,replaced});
                    }
                  dp[i][j]=ans;  
                }
            }
            return dp[0][0];
        
    }
    int minDistance(string word1, string word2) {

        if(word1.length()==0)return word2.length();
        if(word2.length()==0)return word1.length();
        int i=0;
        int j=0;
        vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        //int ans=solveUsingRecursion(word1,word2,i,j);
        int ans=solveUsingTab(word1,word2);
        return ans;
    }
};