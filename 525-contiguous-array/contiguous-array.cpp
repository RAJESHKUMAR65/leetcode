class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();

        //{{diff agar 0 k karn bada h,0},index}
        //{{0,diff agar 1 k karn bada h},index}
        map<pair<int,int>,int>mp;

        int ans=0;
        int count0=0;
        int count1=0;

        for(int i=0;i<n;i++)
        {
            //0 count kar liye
            if(nums[i]==0)
            {
                count0++;
            }
            else
            {
                //1 count kar liye
                count1++;
            }

            //hum har index pe dekhnege ki count equal h ki nhi agar 
            //h toh ans me store kar lenge count
            if(count0==count1)
            {
                ans=max(ans,i+1);
            }
            //agar 0 ka count bada h toh equal nhi hua toh hum 
        //dekhnege ki pahle kabhi 0 ka count bada hua tha kisi index
         //pe
            else if(count0>count1)
            {
                int diff=count0-count1;
                //agar pahle se pada hua h toh hum us index ko abhi 
                //current index se subtract kar denge count k liye
                if(mp.find({diff,0})!=mp.end())
                {
                    ans=max(ans,i-mp[{diff,0}]);
                }
            }
            //agar 1 ka count bada h toh equal nhi hua toh hum 
        //dekhnege ki pahle kabhi 1 ka count bada hua tha kisi index
         //pe
            else
            {
                int diff=count1-count0;
                //agar pahle se pada hua h toh hum us index ko abhi 
                //current index se subtract kar denge count k liye
                if(mp.find({0,diff})!=mp.end())
                {
                    ans=max(ans,i-mp[{0,diff}]);
                }
            }

            //har index me agar count equal nhi h toh store kar lenge
            if(count0>count1)
            {
                int diff=count0-count1;
                if(mp.find({diff,0})==mp.end())
                {
                    mp[{diff,0}]=i;
                }
            }
            else
            {
                int diff=count1-count0;
                if(mp.find({0,diff})==mp.end())
                {
                    mp[{0,diff}]=i;
                }
            }
        }
        return ans;
    }
};