class Solution {
public:
    int recSolve(int n){
        //base case
        if(n==1 || n==0){
            return n;
        }
        int ans=recSolve(n-1)+recSolve(n-2);

        return ans;
    }
    int topDown(int n,vector<int>&dp){
          //base case
        if(n==1 || n==0){
            return n;
        }
        //step3:condition check kro kei answer phele sey exits nhi krta hei
       if(dp[n]!=-1){
        return dp[n];
       }

        //step2:jaha jaha ans store raha waha dp mai store kro and dp return kro 
        dp[n]=topDown(n-1,dp)+topDown(n-2,dp);

        return dp[n];
    }
    int fib(int n) {
       //step 1:create dp array dekh n kaha sey ja raha hei
       vector<int>dp(n+1,-1);
       int ans=topDown(n,dp);
       return ans;
    }
};