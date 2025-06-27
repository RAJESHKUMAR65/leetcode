class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        int current_max=nums[0];
        int current_min=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<0){
                swap(current_max,current_min);
            }
            current_max=max(nums[i],current_max*nums[i]);
            current_min=min(nums[i],current_min*nums[i]);
            maxi=max(maxi,current_max);
        }
        return maxi;
    }
};