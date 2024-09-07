class Solution {
public:
    int maxi(vector<int>& arr, int s, int e) {
        if (s > e) {
            return 1e5;
        }
        int maximum = INT_MIN;
        for (int i = s; i <= e; i++) {
            maximum = max(maximum, arr[i]);
        }
        
        return maximum;
    }

    int solveUsingRecursion(vector<int>& arr, int start, int end) {
        if (start == end) {
            return 0;
        }
        int ans = INT_MAX;
        for (int i = start; i < end; i++) {
            int a = maxi(arr, start, i);
            int b = maxi(arr, i + 1, end);
            
            ans = min(ans, a * b + solveUsingRecursion(arr, start, i) +
                               solveUsingRecursion(arr, i + 1, end));
        }
        
        return ans;
    }
     int solveUsingMemo(vector<int>& arr, int start, int end,vector<vector<int>> &dp) {
        if (start == end) {
            return 0;
        }
        int ans = INT_MAX;
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        for (int i = start; i < end; i++) {
            int a = maxi(arr, start, i);
            int b = maxi(arr, i + 1, end);
            
            ans = min(ans, a * b + solveUsingMemo(arr, start, i,dp) + solveUsingMemo(arr, i + 1, end,dp));

        }
        dp[start][end]=ans;
        
        return dp[start][end];
    }
    int mctFromLeafValues(vector<int>& arr) {
       // int ans = solveUsingRecursion(arr, 0, arr.size() - 1);
       int n=arr.size();
       vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       int ans=solveUsingMemo(arr,0,n-1,dp);
        return ans;
    }
};