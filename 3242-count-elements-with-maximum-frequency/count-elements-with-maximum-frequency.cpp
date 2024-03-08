class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
       int arr[101];
       for(int i=0;i<100;i++)
       {
           arr[i]=0;
       }
       for(int i=0;i<nums.size();i++)
       {
          
           arr[nums[i]]++;
       } 
       int maxfreq=0;
       int freq=0;
       for(int i=0;i<101;i++)
       {
           maxfreq=max(maxfreq,arr[i]);
       }
       for(int i=0;i<101;i++)
       {
           if(arr[i]==maxfreq)
           freq++;
       }
       return freq*maxfreq;

    }
};