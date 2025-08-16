class Solution {
public:
    
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int sum=100000;
        for(int i=0;i<=n-3;i++){
            int num1=nums[i];
            int s=i+1;
            int e=n-1;
            while(s<e){
             int curr_sum=num1+nums[s]+nums[e];
             if(abs(target-curr_sum)<abs(target-sum)){
                sum=curr_sum;
             }
             if(curr_sum>target){
                e--;
             }
             else{
                s++;
             }
                
            }
            
        }
        return sum;
    }
};