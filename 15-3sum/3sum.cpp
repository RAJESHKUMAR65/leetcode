class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       vector<vector<int>>result;
       for(int i=0;i<nums.size();i++){
        if(i>0 && nums[i]==nums[i-1]){
            continue;}
          int num1=nums[i];
          int j=i+1;
          int k=nums.size()-1;
          while(j<k){
           
            if(num1+nums[j]+nums[k]==0){
              while(j<k&& nums[j]==nums[j+1])j++;
              while(j<k && nums[k]==nums[k-1])k--;
               result.push_back({num1,nums[j],nums[k]});
               j++;
               k--;
              
            }
            else if(num1+nums[j]+nums[k]<0){
                j++;
            }
            else{
                k--;
            }
          }
       } 
       return result;
    }
};