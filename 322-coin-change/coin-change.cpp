class Solution {
public:
   int solveUsingRecursion(vector<int>&coins,int amount,vector<int> &dp){
    if(amount ==0){
        return 0;
    }
    if(amount<0){
        return INT_MAX;

    }
    if(dp[amount]!=-1){
        return dp[amount];
    }
     
    int final=INT_MAX;
    for(int i=0;i<coins.size();i++){
        int ans=solveUsingRecursion(coins,amount-coins[i],dp);
        if(ans!=INT_MAX){
            final=min(final,ans+1);
        }
    }
    dp[amount]=final;
    return final;
   }
   int solveUsingtab(vector<int>&coins,int amount){
    vector<int >dp(amount+1,INT_MAX);
    dp[0]=0;
    for(int i=0;i<=amount;i++){
            int final=INT_MAX;
    for(int j =0;j<coins.size();j++){
        if(i-coins[j]>=0){
               int ans=dp[i-coins[j]];
           if(ans!=INT_MAX){
            final=min(final,ans+1);
              dp[i]=final;
    }
        }
     }
  
    }
    return dp[amount];
   }
     
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int>dp(amount+1,-1);
        int ans=solveUsingtab(coins,amount);
        if(ans!=INT_MAX){
          return ans;
        }else{
            return -1;
        }
       
    }
};