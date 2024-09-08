class Solution {
public:
    int solveUsingRecursion(vector<int>& arr, int start, int end,
                            map<pair<int, int>, int>& maxi) {
        if (start == end)
            return 0;
        int ans = INT_MAX;
        for (int i = start; i < end; i++) {
            ans = min(ans, maxi[{start, i}] * maxi[{i + 1, end}] +
                               // start -- i-1 nhi jyega
                               solveUsingRecursion(arr, start, i, maxi) +
                               solveUsingRecursion(arr, i + 1, end, maxi));
        }

        return ans;
    }
    int solveUsingMemo(vector<int>& arr, int start, int end,
                            map<pair<int, int>, int>& maxi,vector<vector<int>>&dp) {
        if (start == end)
            return 0;
        int ans = INT_MAX;
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        for (int i = start; i < end; i++) {
            ans = min(ans, maxi[{start, i}] * maxi[{i + 1, end}] +
                               // start -- i-1 nhi jyega
                               solveUsingMemo(arr, start, i, maxi,dp) +
                               solveUsingMemo(arr, i + 1, end, maxi,dp));
        }
         dp[start][end]=ans;
        return dp[start][end];
    }
    int mctFromLeafValues(vector<int>& arr) {
        // sare range ka maxi map mein store kra denge
        map<pair<int, int>, int> maxi;
        for (int i = 0; i < arr.size(); i++) {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < arr.size(); j++) {
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }
        int n = arr.size();
       //int ans = solveUsingRecursion(arr, 0, n - 1, maxi);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=solveUsingMemo(arr,0,n-1,maxi,dp);

        return ans;
    }
};