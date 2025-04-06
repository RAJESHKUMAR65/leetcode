class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mini=nums[0];
        int maxi=nums[nums.size()-1];
        while(mini>0 && maxi>0){
            if(mini>maxi){
                mini=mini-maxi;
            }
            else{
                maxi=maxi-mini;
            }
        }
        return maxi==0?mini:maxi;
    }
};