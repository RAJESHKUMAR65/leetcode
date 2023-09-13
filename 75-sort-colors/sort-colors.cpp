class Solution {
public:
    void sortColors(vector<int>& nums) {
      int start=0;
      int end=nums.size()-1;
      int i=0;
      while(i<=end) 
      {
          if(nums[i]==0)
          {
              swap(nums[i],nums[start]);
              start++;
              i++;
          }
          else if(nums[i]==2)
          {
              swap(nums[i],nums[end]);
              end--;
              //yaha catch hei hume nhi pata number 1 bhi hoskta hei 
 //right side sey swape krte waqt dyhan do
          }
          else
          {
              i++;
          }
      }
    }
};