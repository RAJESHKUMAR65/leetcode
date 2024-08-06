class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0ll);
        int val = 0;
        for(int i = 0;i<n;i++){
            sum-=nums[i];
            if(sum==val) return i;
            val+=nums[i]; 
        }
        return -1;
        
    }
};