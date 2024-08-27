class Solution {
public:
  
    int binary_search(vector<int>&nums,int s,int e,int target){
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
             mid=s+(e-s)/2;
        }
        return -1;
    }
    int findPairs(vector<int>& nums, int k) {
        // two pointer appraoch sey kra hein dekh lena hei
        sort(nums.begin(),nums.end());
        set<pair<int,int>>ans;
        for(int i=0;i<nums.size();i++){
            int pair=binary_search(nums, i+1, nums.size()-1, k+nums[i]);
            if(pair!=-1){
                ans.insert({nums[i],nums[pair]});
            }
        }

        return ans.size();
    }
};