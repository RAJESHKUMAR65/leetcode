class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
       vector<int>result;
       int sum=0;
       for(auto &num:nums){
        if(!(num&1))sum+=num;
       }
       for(int i=0;i<queries.size();i++){
         int index=queries[i][1];
         int val=queries[i][0];
         if(nums[index]&1){
            nums[index]+=val;
            if(!(nums[index]&1)){
                sum+=nums[index];
            }
            

         }else{
               sum-=nums[index];
               nums[index]+=val;
               if(nums[index]%2==0)sum+=nums[index];
               
         }
         result.push_back(sum);
       }
       return result;
    }
};