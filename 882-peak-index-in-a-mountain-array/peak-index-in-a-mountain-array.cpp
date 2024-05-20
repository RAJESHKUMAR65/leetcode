class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
    int s=0;
    int e=arr.size()-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<e)
    {
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
        {
            ans=mid;
            break;
        }
        else if(arr[mid]>arr[mid+1])
        {
            e=mid;
        }
        else 
         {
            s=mid+1;
         }
        mid=s+(e-s)/2;
    }

   
       return ans; 
    }
    
};