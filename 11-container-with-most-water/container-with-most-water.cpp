class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int Maxarea=INT_MIN;
        while(i<j){
            int currheight=min(height[i],height[j]);
            int width=j-i;
            int area=currheight*width;
            Maxarea=max(area,Maxarea);
            if(height[i]<height[j]){
                i++;
            }else{
                 j--;
            }
        }
        return Maxarea;
    }
};