class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        stack<int> st;
         for(int i=0;i<nums.size();i++){
             if(st.empty()){
                st.push(nums[i]);
             }
             else{
                if(st.top()==nums[i]){
                    st.pop();
                }
                else{
                    st.push(nums[i]);
                }
             }
         }
         while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
         }
         return ans;
    }
};