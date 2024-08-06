class Solution {
public:
   static bool mycomp(int &a,int &b){
     return a>b;
   }
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                nums[i]=-1;
            }
            else{
                k++;
            }
        }
        sort(nums.begin(),nums.end(),mycomp);
        return k;


    }
};