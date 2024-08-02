class Solution {
public:
    int firstOcurrence(vector<int>&nums,int target){
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        int ans=-1;
        while(s<=e){
            if(nums[mid]==target){
                ans=mid;
                e=mid-1;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }

            mid=s+(e-s)/2;
        }
        return ans;
    }
     int lastOcurrence(vector<int>&nums,int target){
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        int ans=-1;
        while(s<=e){
            if(nums[mid]==target){
                ans=mid;
                s=mid+1;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=firstOcurrence(nums,target);
        int last=lastOcurrence(nums,target);
        vector<int>ans;
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};