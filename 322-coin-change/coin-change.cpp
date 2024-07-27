class Solution {
public:
   int solveRec(vector<int>& coins,int amount){
      //base case
      if(amount ==0){
        return 0;
      }
      if(amount<0){
        return INT_MAX;
      }
        int mini=INT_MAX;
      for(int i=0;i<coins.size();i++){
          int ans=solveRec(coins,amount-coins[i]);
          if(ans!=INT_MAX){
             mini=min(mini,ans+1);
          }
      }
      return mini;
   }

   // topdown approach
   int memo(vector<int>&coins,int amount,vector<int>&dp){
    if(amount ==0){
        return 0;
      }
      if(amount<0){
        return INT_MAX;
      }
      if(dp[amount]!=-1){
        return dp[amount];
      }
        int mini=INT_MAX;
      for(int i=0;i<coins.size();i++){
          int ans=memo(coins,amount-coins[i],dp);
          if(ans!=INT_MAX){
             mini=min(mini,ans+1);
          }
      }
      dp[amount]=mini;
      return mini;// return dp[amount] bhi lekh skte hei
   }

   // bottom of approach

   int tabulation(vector<int>&coins,int amount){
    //step 1:dp array create kro
    vector<int>dp(amount+1,INT_MAX);// int_max isliye minimum chaye

    //step2:base case check kro

    dp[0]=0;
    //step3: code ka follow dekho top downapproachmai
    for(int target=1;target<=amount;target++){
               int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(target-coins[i]>=0){
               int ans=dp[target-coins[i]];
            if(ans!=INT_MAX){
             mini=min(mini,ans+1);
              }
            }
         
      }
      dp[target]=mini;
      
    }
    return dp[amount];
   }
    int coinChange(vector<int>& coins, int amount) {
        // int ans=solveRec(coins,amount);
        // if(ans!=INT_MAX){
        //     return ans;
        // }
        // else{
        //     return -1;
        // }

        vector<int >dp(amount+1,-1);
      //  int ans=memo(coins,amount,dp);
      int ans=tabulation(coins,amount);

        if(ans!=INT_MAX){
            return ans;
        }
        else{
            return -1;
        }
    }
};