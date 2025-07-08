class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      map<int,int>mp;
      for(int i=0;i<nums.size();i++){
         int remaining=target-nums[i];
         if(mp.find(remaining)!=mp.end()){
            return {mp[remaining],i};
         }
         else{
            mp[nums[i]]=i;
         }
      }
      return {-1,-1};
    }
};