class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pstive;
        vector<int> neg;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                pstive.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }
        vector<int> ans;
        for(int i=0;i<neg.size();i++)
        {
            ans.push_back(pstive[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};