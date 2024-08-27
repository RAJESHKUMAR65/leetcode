class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closest=INT_MAX;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
               closest=min(closest,abs(nums[i]));
              
        }
        cout<<closest<<endl;
        for(int i=0;i<nums.size();i++){
                if(abs(nums[i])==closest){
                    ans=max(ans,nums[i]);
                }
              
        }
        
        
        
        return ans;
    }
};