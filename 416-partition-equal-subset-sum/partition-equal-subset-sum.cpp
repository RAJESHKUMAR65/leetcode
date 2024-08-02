class Solution {
public:
    bool solveUsingRecursion(vector<int> &nums,int index,int sum){

        if(index>=nums.size()){
            return false;
        }
        if(sum==0){
            return true;
        }
        if(sum<0){
            return false;
        }

        bool include=solveUsingRecursion(nums,index+1,sum-nums[index]);
        bool exclude=solveUsingRecursion(nums,index+1,sum);
        bool ans=(include || exclude);
        return ans;
    }
     bool solveUsingMemo(vector<int> &nums,int index,int target,vector<vector<int>>&dp){

        if(index>=nums.size()){
            return false;
        }
        if(target==0){
            return true;
        }
        if(target<0){
            return false;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }

        bool include=solveUsingMemo(nums,index+1,target-nums[index],dp);
        bool exclude=solveUsingMemo(nums,index+1,target,dp);
        dp[index][target]=(include || exclude);
        return dp[index][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int index=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        // yaha hei galati krunga
        //jab sum odd hoga toh 2 equal subpart mai nhi divide kr paunga
        if(sum &1){
            return false;
        }
        
        int target=sum/2;
        // int ans =solveUsingRecursion(nums,index,target);

        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
       int ans=solveUsingMemo(nums,index,target,dp);
        return ans;
         

    }
   
};