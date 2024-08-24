class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int i=0;
        int j=0;
        long long total_sub=0;
        while(i<nums.size()  && j<nums.size()-1){
           if(nums[j]!=nums[j+1]){
             j++;
           }
           else{
              long long l=j-i+1;
              total_sub+=(l*(l+1)/2-l);
              j++;
              i=j;
              
           }
        }
        long long l=j-i+1;
        total_sub+=(l*(l+1)/2-l);
        total_sub+=nums.size();

       return total_sub;
    }
};