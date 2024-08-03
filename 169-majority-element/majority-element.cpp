class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            
            if(ans==nums[i]){
                count++;
            }
            else{
                count--;
                if(count<=0){
                    ans=nums[i+1];
            
                    }
               
             }
            
        }
        return ans;
    }
};