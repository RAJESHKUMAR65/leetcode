class Solution {
public:
    int climbStairs(int n) {
    //    if(n==0)
    //    {
    //     return 1;
    //    } 
    //    if(n==1)
    //    {
    //     return 1;
    //    }
    //    return (climbStairs(n-1)+climbStairs(n-2));
    vector<int> dp;
    dp.push_back(1);
    dp.push_back(1);
    for(int i=2;i<=n;i++)
    {
        dp.push_back(dp[i-1]+dp[i-2]);
    }
    return dp[n];
    }
};