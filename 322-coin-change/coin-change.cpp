class Solution {
public:
 int solveUsingRecursion(vector<int>&coins,int target){
    if(target==0){
        return 0;
    }
    if(target<0){
       return INT_MAX;
    }
    int finalans=INT_MAX;
    for(int i=0;i<coins.size();i++){
     int ans= solveUsingRecursion(coins,target-coins[i]);
       if(ans!=INT_MAX){
          finalans=min(finalans,ans+1);
       }
    }
    return finalans;
 }
 int  solveUsingMemo(vector<int>&coins,int target,vector<int>&dp){
    if(target==0){
        return 0;
    }
    if(target<0){
       return INT_MAX;
    }
    if(dp[target]!=-1){
        return dp[target];
    }
    int finalans=INT_MAX;
    for(int i=0;i<coins.size();i++){
     int ans=  solveUsingMemo(coins,target-coins[i],dp);
       if(ans!=INT_MAX){
          finalans=min(finalans,ans+1);
       }
    }
    return dp[target]=finalans;
 }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans=solveUsingMemo(coins,amount,dp);
        if(ans!=INT_MAX){
            return ans;
        }
        else{
            return -1;
        }
    }
};