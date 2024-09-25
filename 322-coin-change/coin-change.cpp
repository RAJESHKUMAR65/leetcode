class Solution {
public:
  int solveUsingRecursion(vector<int >&coins,int amount){
      if(amount==0){
        return 0;
      }
      if(amount<0){
        return INT_MAX;
      }
      
    int ans=INT_MAX;
    for(int i=0;i<coins.size();i++){
       int curr_amount=solveUsingRecursion(coins,amount-coins[i]);
          if(curr_amount!=INT_MAX){
            ans=min(ans,1+curr_amount);
        
         }
    }
    return ans;
  
  }
int solveUsingMemo(vector<int >&coins,int amount,vector<int>&dp){
      if(amount==0){
        return 0;
      }
      if(amount<0){
        return INT_MAX;
      }
      if(dp[amount]!=-1){
        return dp[amount];
      }
    int ans=INT_MAX;
    for(int i=0;i<coins.size();i++){
       int curr_amount=solveUsingMemo(coins,amount-coins[i],dp);
          if(curr_amount!=INT_MAX){
            ans=min(ans,1+curr_amount);
        
         }
        
    }
    dp[amount]=ans;
    
    return dp[amount];
  
  }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans=solveUsingMemo(coins,amount,dp);
        if(ans==INT_MAX){
            return -1;
        }
        else{
            return ans;;
        }
    }
};