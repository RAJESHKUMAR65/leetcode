class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=INT_MIN;
        int i=0;
        int j=height.size()-1;
        while(i<j){
            int length=min(height[i],height[j]);
            int breadth=j-i;
            int area=length*breadth;
            maxi=max(area,maxi);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxi;
    }
};