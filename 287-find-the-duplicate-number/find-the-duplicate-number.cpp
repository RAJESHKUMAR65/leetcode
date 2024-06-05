class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       // method to binay wala sahi hei
       // matlab saab ko saabke sahi jaga pr paucha diya
       while(nums[nums[0]]!=nums[0])
       {
        swap(nums[nums[0]],nums[0]);
       } 


       return nums[0];
    }
};