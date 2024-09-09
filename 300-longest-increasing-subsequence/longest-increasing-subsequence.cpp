class Solution {
public:
    int solveUsingRecursion(vector<int>& nums, int curr, int prev) {
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

    int solveUsingMemo(vector<int>& nums, int curr, int prev,
                       vector<vector<int>>& dp) {
        if (curr >= nums.size()) {
            return 0;
        }
        if (dp[curr][prev + 1] != -1) {
            return dp[curr][prev + 1];
        }
        // include
        int include = 0;

        if (prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + solveUsingMemo(nums, curr + 1, curr, dp);
        }
        // exclude krna hei
        int exclude = 0 + solveUsingMemo(nums, curr + 1, prev, dp);
        dp[curr][prev + 1] = max(include, exclude);
        return dp[curr][prev + 1];
    }
    int solveUsingTab(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1,
                               vector<int>(nums.size() + 1, 0));
        for (int curr = nums.size() - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                int include = 0;

                if (prev == -1 || nums[curr] > nums[prev]) {
                    include = 1 + dp[curr + 1][curr + 1];
                }
                // exclude krna hei
                int exclude = 0 + dp[curr + 1][prev + 1];
                dp[curr][prev + 1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    int solveUsingSo(vector<int>& nums) {
        vector<int> currRow(nums.size() + 1, 0);
        vector<int> next(nums.size() + 1, 0);
        for (int curr = nums.size() - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                int include = 0;

                if (prev == -1 || nums[curr] > nums[prev]) {
                    include = 1 + next[curr + 1];
                }
                // exclude krna hei
                int exclude = 0 + next[prev + 1];
                currRow[prev + 1] = max(include, exclude);
                // shift
            }
            next = currRow;
        }
        return currRow[0];
    }

    int solveUsingOptimal(vector<int>&nums){
        if(nums.size()==0){
            return 1;
        }
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>ans.back()){
                //include
                ans.push_back(nums[i]);
            }
            else{
                //exclude
                // just bada element dudo usey sey replace kr do
               int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
               // toh muje us index mein jake ye value replace kr dene hein
               ans[index]=nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1; // kyuki muje prev sey compare krna hei aur dekhna hei
                       // element ko
        // include krna chaye kei nhi
        // int ans = solveUsingRecursion(nums, curr, prev);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        int ans = solveUsingOptimal(nums);
        return ans;
    }
};