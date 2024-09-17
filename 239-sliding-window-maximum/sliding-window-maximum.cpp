class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     deque<int> dq;
     vector<int> ans;
     /// k element ko process krna hei
     for(int i=0;i<k;i++){
        // agar queue mei current element sey chhota element hei toh remove krna
        while(!dq.empty() && (nums[i]>=nums[dq.back()])){
            // back sey kyu pop kr rahe hu mere dq mein element decreasing order mein hei
            dq.pop_back();
        }
        // aab maine sare chhote element dqueue sey pop kr diya hei aab mein insert kr skta hu
        dq.push_back(i);
     } 

     // phele k window ka ans dal do 
     ans.push_back(nums[dq.front()]);

     // remainin n-k window ko process kro

     for(int i=k;i<nums.size();i++){
        // check kro kei queue mein window sey bahaar kei elment hei pop kr do
        if(!dq.empty() && i-dq.front()>=k){
            dq.pop_front();
        }
        // phir sey next window kei check kro kei koi bhi elment
         // agar queue mei current element sey chhota element hei toh remove krna
        while(!dq.empty() && (nums[i]>=nums[dq.back()])){
            // back sey kyu pop kr rahe hu mere dq mein element decreasing order mein hei
            dq.pop_back();
        }
        // aab maine sare chhote element dqueue sey pop kr diya hei aab mein insert kr skta hu
        dq.push_back(i);

        ans.push_back(nums[dq.front()]);

     }  
     return ans;
    }
};