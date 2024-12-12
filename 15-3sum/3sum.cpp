class Solution {
public:
    vector<vector<int>>result;
    void twosum(vector<int>&nums,int target,int i,int j){
        while(i<j){
            if(nums[i]+nums[j]>target){
                j--;
            }
            else if(nums[i]+nums[j]<target){
                i++;
            }
            else{
                while(i<j && nums[i]==nums[i+1]){
                    i++;
                }
                while(i<j && nums[j]==nums[j-1]){
                    j--;
                }
                result.push_back({-target,nums[i],nums[j]});
                i++;j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {

        //
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            int target=-nums[i];
            twosum(nums,target,i+1,nums.size()-1);

        }
        return result;
        
    }
};