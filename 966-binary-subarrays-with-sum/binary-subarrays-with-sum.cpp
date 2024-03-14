class Solution {
public:
int vectors(vector<int> & nums,int g)
{
    long long head=0,tail=0,sum=0,ans=0;
    for(head=0;head<nums.size();head++)
    {
        sum+=nums[head];
        while(tail<=head and sum>g)
        {
            sum-=nums[tail];
            tail++;
        }
        ans+=head-tail+1;
    }
    return ans;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return vectors(nums,goal)-vectors(nums,goal-1);
         
    }
};