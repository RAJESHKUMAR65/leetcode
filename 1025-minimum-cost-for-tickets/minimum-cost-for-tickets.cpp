class Solution {
public:
int solveUsingRecursion(vector<int>&days,vector<int>&costs,int i){
    if(i>=days.size()){
        return 0;
    }
    // 1 day pass kreda
     int cost1=costs[0]+solveUsingRecursion(days,costs,i+1);
     // 7 days pass kreda
     int pass_endday=days[i]+7-1;
     int j=i;
     while(j<days.size()&&pass_endday>=days[j]){
        j++;
     }
     int cost7=costs[1]+solveUsingRecursion(days,costs,j);

     // 30 days pass leliya
     pass_endday=days[i]+30-1;
     j=i;
     while(j<days.size()&&pass_endday>=days[j]){
        j++;
     }
     int cost30=costs[2]+solveUsingRecursion(days,costs,j);
     int ans=min(cost1,min(cost7,cost30));
     return ans;
}

//memo
int solveUsingMemo(vector<int>&days,vector<int>&costs,int i,vector<int>&dp){
     if(i>=days.size()){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    // 1 day pass kreda
     int cost1=costs[0]+solveUsingMemo(days,costs,i+1,dp);
     // 7 days pass kreda
     int pass_endday=days[i]+7-1;
     int j=i;
     while(j<days.size()&&pass_endday>=days[j]){
        j++;
     }
     int cost7=costs[1]+solveUsingMemo(days,costs,j,dp);

     // 30 days pass leliya
     pass_endday=days[i]+30-1;
     j=i;
     while(j<days.size()&&pass_endday>=days[j]){
        j++;
     }
     int cost30=costs[2]+solveUsingMemo(days,costs,j,dp);
     int ans=min(cost1,min(cost7,cost30));
     return dp[i]= ans;
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1,-1);
    int ans=solveUsingMemo(days,costs,0,dp);
    return ans;
    }
};