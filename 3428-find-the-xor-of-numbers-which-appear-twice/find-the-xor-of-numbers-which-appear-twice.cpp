class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int Xor=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i]){
          Xor^=nums[i];
            }
        }
        return Xor;
    }
};