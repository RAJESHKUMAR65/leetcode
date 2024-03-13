class Solution {
public:
    int pivotInteger(int n) {
        
        int original=(n)*(n+1)/2;
        int pivot=sqrt(original);
        int sum=(pivot)*(pivot+1)/2;
        if(sum==(original-sum+pivot))
        {
            return pivot;
        }
        else
        {
            return -1;
        }
    }
};