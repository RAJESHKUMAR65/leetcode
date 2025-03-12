class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            // step 1 current element mein add karo
            sum+=nums[i];
            // maxi update karo
            maxi=max(sum,maxi);
            // agar sum less then zero hein toh sum ko zero kr do
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};