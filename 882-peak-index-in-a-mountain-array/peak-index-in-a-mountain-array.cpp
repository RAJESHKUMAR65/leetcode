class Solution {
public:

    int binary_search(vector<int>& arr){
        int s=0;
        int n=arr.size();
        int e=n-1;
        int mid=s+(e-s)/2;
       

        while(s<=e){
            if((mid-1>=0) && (mid+1)<n && arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
            }
            else if((mid+1<n )&& arr[mid]<arr[mid+1]){
                s=mid+1;
            }
            else if((mid+1<n)  &&arr[mid]>arr[mid+1]){
                e=mid;
            }
            mid=s+(e-s)/2;

        }
        return -1; 
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans=binary_search(arr);
        return ans;
        
    }
};