class Solution {
public:
    bool solveUsingRecursion(vector<int>& nums, int index, int sum) {

        if (index >= nums.size()) {
            return false;
        }
        if (sum == 0) {
            return true;
        }
        if (sum < 0) {
            return false;
        }

        bool include = solveUsingRecursion(nums, index + 1, sum - nums[index]);
        bool exclude = solveUsingRecursion(nums, index + 1, sum);
        bool ans = (include || exclude);
        return ans;
    }
    bool solveUsingMemo(vector<int>& nums, int index, int target,
                        vector<vector<int>>& dp) {
        // target sum kuch bhi lekho

        if (index >= nums.size()) {
            return false;
        }
        if (target == 0) {
            return true;
        }
        if (target < 0) {
            return false;
        }
        if (dp[index][target] != -1) {
            return dp[index][target];
        }

        bool include =
            solveUsingMemo(nums, index + 1, target - nums[index], dp);
        bool exclude = solveUsingMemo(nums, index + 1, target, dp);
        dp[index][target] = (include || exclude);
        return dp[index][target];
    }

    bool usingTabulation(vector<int>& nums, int target) {
        int n = nums.size();
        // step1 dp array create kro
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        // step2 base case dekho
        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = 1;
        }

        // index mera top down mai 0 sey n-1 ja raha hei
        // toh yaha n-1 sey 0 jyega
        for (int index = n - 1; index>= 0; index--) {
            //
            for (int t = 1; t <= target; t++) {
                bool include=0;
                if(t-nums[index]>=0){
                   include =dp[index + 1][t - nums[index]];
                }
               
                bool exclude = dp[index + 1][t];
                dp[index][t] = (include || exclude);
                
            }
        }
        return dp[0][target];
    }
    bool usingspace(vector<int>& nums, int target) {
        int n = nums.size();
        // step1 dp array create kro
        //vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        // step2 base case dekho
        vector<int> curr(target+1,0);
        vector<int> next(target+1,0);

       //upper  column0 mai 1 dal rahe thi
       curr[0]=1;
       next[0]=1;
        // index mera top down mai 0 sey n-1 ja raha hei
        // toh yaha n-1 sey 0 jyega
        for (int index = n - 1; index>= 0; index--) {
            //
            for (int t = 1; t <= target; t++) {
                bool include=0;
                if(t-nums[index]>=0){
                   include =next[t - nums[index]];
                }
               
                bool exclude = next[t];
                curr[t] = (include || exclude);
                
            }
            // shift yaad rakna yaha hum neeche sey upper ja rahe toh hume next
            // current krna padega 
            next=curr;
        }
        return next[target];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        // yaha hei galati krunga
        // jab sum odd hoga toh 2 equal subpart mai nhi divide kr paunga
        if (sum & 1) {
            return false;
        }

        int target = sum / 2;
        // int ans =solveUsingRecursion(nums,index,target);

        // vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        // int ans = solveUsingMemo(nums, index, target, dp);
        // return ans;
        // int ans=usingTabulation(nums,target);
        // return ans;
        int ans=usingspace(nums,target);
        return ans;
    }
};