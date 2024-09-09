class Solution {
public:
    int solveUsingRecursion(vector<int>& nums, int curr, int prev ) {
        if (curr >= nums.size()) {
            return 0;
        }
        // include
        
        int include = 0;

        if (prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + solveUsingRecursion(nums, curr + 1, curr);
        }
        // exclude krna hei
        int exclude = 0 + solveUsingRecursion(nums, curr + 1, prev);
        return max(include, exclude);

       
    }

    int solveUsingMemo(vector<int>& nums, int curr, int prev,vector<vector<int>> &dp) {
        if (curr >= nums.size()) {
            return 0;
        }
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        // include
        int include = 0;

        if (prev == -1 || nums[curr] > nums[prev]) {
            include = 1 +  solveUsingMemo(nums, curr + 1, curr,dp);
        }
        // exclude krna hei
        int exclude = 0 +  solveUsingMemo(nums, curr + 1, prev,dp);
        dp[curr][prev+1]= max(include, exclude);
        return dp[curr][prev+1];
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1; // kyuki muje prev sey compare krna hei aur dekhna hei
                       // element ko
        // include krna chaye kei nhi
       // int ans = solveUsingRecursion(nums, curr, prev);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
       int ans=solveUsingMemo(nums,curr,prev,dp);
        return ans;
    }
};