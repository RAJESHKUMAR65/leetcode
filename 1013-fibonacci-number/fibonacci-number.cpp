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
    //bottom up approach
    int bottomUp(int n){
        //step1:create dp array
        vector<int > dp(n+1,-1);
        //step2:check the base case
        dp[0]=0; if(n==0) return dp[0];
        dp[1]=1;
        //step3: phele n sey 2 tak calculate kr rahe the aab 2 sey n kei taraf jao
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    // space optimisation
    int spaceOptimisation(int n){
        int prev1=0;
        int prev2=1;
        if(n==0 || n==1){
            return n;
        }
        int curr;
        for(int i=2;i<=n;i++){
            curr=prev1+prev2;
            prev1=prev2;
            prev2=curr;
        }
        return curr;
    }
    int fib(int n) {
       //step 1:create dp array dekh n kaha sey ja raha hei
       vector<int>dp(n+1,-1);
       int ans=topDown(n,dp);
       return spaceOptimisation( n);
    }
};