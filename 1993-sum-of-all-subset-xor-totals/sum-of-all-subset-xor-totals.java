class Solution {
    public int subsetXORSum(int[] nums) {
      int sum = 0;
        for(int num : nums){
            sum |= num;
        }
        return (1<<nums.length-1)*sum;
      
    }
}