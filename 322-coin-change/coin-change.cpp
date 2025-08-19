class Solution {
public:
// recursive solution
   int recursionSol_coinchange(vector<int>&coins,int amount){
      if(amount==0){
        return 0;
      }
      if(amount <0){
        return INT_MAX;
      }
      int final_ans=INT_MAX;
    for(int i=0;i<coins.size();i++){
      int ans= recursionSol_coinchange(coins,amount-coins[i]);
       if(ans!=INT_MAX){
        final_ans=min(ans+1,final_ans);
       }
    }
    return final_ans;
   }

   int sol_topDown_coinchange(vector<int>&coins,int amount,vector<int>&dp){
    if(amount==0){
        return 0;
      }
      if(amount <0){
        return INT_MAX;
      }
      if(dp[amount]!=-1){
        return dp[amount];
      }
      int final_ans=INT_MAX;
    for(int i=0;i<coins.size();i++){
      int ans=  sol_topDown_coinchange(coins,amount-coins[i],dp);
       if(ans!=INT_MAX){
        final_ans=min(ans+1,final_ans);
       }
    }
    return dp[amount]=final_ans;
   }
   int sol_bottomDown_coinchange(vector<int>&coins,int amount){
    vector<int>dp(amount+1,INT_MAX);
    dp[0]=0;
    for(int target=1;target<=amount;target++){
        for(int i=0;i<coins.size();i++){
            if(target-coins[i]>=0 && target-coins[i]!=INT_MAX){
                 int ans=dp[target-coins[i]];
                 if(ans!=INT_MAX){
                 dp[target]=min(ans+1,dp[target]);}
            }
           
        }
    }
    return dp[amount];
   }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);

        
        int ans=sol_bottomDown_coinchange(coins,amount);
        if(ans!=INT_MAX) return ans;
        else return -1;
    }
};