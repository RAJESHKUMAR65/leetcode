class Solution {
public:
int rec(vector<int>&coins,int amount){
    
    if(amount<0){
        return INT_MAX;
    }
    if(amount==0){
        return 0;
    }
    int finalans=INT_MAX;
    for(int i=0;i<coins.size();i++){
         int ans=rec(coins,amount-coins[i]);
         if(ans!=INT_MAX){
            finalans=min(finalans,ans+1);
         }
    }
    return finalans;
}
int memo(vector<int>&coins,int amount,vector<int>&dp){
    
    if(amount<0){
        return INT_MAX;
    }
    if(amount==0){
        return 0;
    }
    if(dp[amount]!=-1){
        return dp[amount];
    }
    int finalans=INT_MAX;
    for(int i=0;i<coins.size();i++){
         int ans=memo(coins,amount-coins[i],dp);
         if(ans!=INT_MAX){
            finalans=min(finalans,ans+1);
         }
    }
    return dp[amount]=finalans;
}
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans=memo(coins,amount,dp);
        if(ans!=INT_MAX){
            return ans;
        }
        return -1;
    }
};