class Solution {
public:
// recursion solution
   int solveUsingRecursion(string &word1,string &word2,int i,int j){
    //base case
    if(i==word1.length()) return word2.length()-j;
    if(j==word2.length()) return word1.length()-i;
    //agar first character match krgye
    int ans=0;
    if(word1[i]==word2[j]){
        ans=0+solveUsingRecursion(word1,word2,i+1,j+1);
    }
    else{
     int insert=1+solveUsingRecursion(word1,word2,i,j+1);
     int deleted=1+solveUsingRecursion(word1,word2,i+1,j);
     int replace=1+solveUsingRecursion(word1,word2,i+1,j+1);
     ans=min(insert,min(deleted,replace));
    }
    return ans;
   }

   // memo
   int solveUsingMemo(string&word1,string &word2,int i,int j,vector<vector<int>>&dp){
    if(i==word1.length()) return word2.length()-j;
    if(j==word2.length()) return word1.length()-i;
    //agar first character match krgye
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=0;
    if(word1[i]==word2[j]){
        ans=0+solveUsingMemo(word1,word2,i+1,j+1,dp);
    }
    else{
     int insert=1+solveUsingMemo(word1,word2,i,j+1,dp);
     int deleted=1+solveUsingMemo(word1,word2,i+1,j,dp);
     int replace=1+solveUsingMemo(word1,word2,i+1,j+1,dp);
     ans=min(insert,min(deleted,replace));
    }
    return dp[i][j]=ans;
   }
   
    int minDistance(string word1, string word2) {
       // word1 kein length 0 hein toh
       // insert krne padenge word1 mein
       if(word1.length()==0){
        return word2.length();
       }
       // word2 is empty means word mein delete krna hoga
       if(word2.length()==0){
        return word1.length();
       }
      int i=0;
      int j=0;
     //  int ans=solveUsingRecursion(word1,word2,i,j);
       //return ans;
       vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
       int ans=solveUsingMemo(word1,word2,i,j,dp);
       return ans;

    }
};