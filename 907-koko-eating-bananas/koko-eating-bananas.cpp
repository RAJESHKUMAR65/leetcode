class Solution {
public:

    bool check(vector<int>& piles, int h,int mid){
        long long sum = 0;
        for(auto i:piles){
            sum+= (i+mid-1)/mid;
        }
        return sum<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long s = 0;
        long long e = 1e9;
        while(s+1<e){
            long long mid  = e -(e-s)/2;
            if(check(piles,h,mid)){
                e = mid;
            }
            else{
                s = mid;
            }
        }
        return e;  
  }
};