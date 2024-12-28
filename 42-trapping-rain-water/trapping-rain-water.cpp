class Solution {
public:
  vector<int> getLeftMax(vector<int>&height){
    vector<int>leftMax(height.size());
    leftMax[0]=height[0];
    for(int i=1;i<height.size();i++){
        leftMax[i]=max(leftMax[i-1],height[i]);
    }
    return leftMax;
  }

  vector<int> getRightMax(vector<int>&height){
    int n=height.size();
    vector<int>rightMax(height.size());
    rightMax[n-1]=height[n-1];
    for(int i=n-2;i>=0;i--){
        rightMax[i]=max(rightMax[i+1],height[i]);
    }
    return rightMax;
  }
    int trap(vector<int>& height) {
        vector<int>left_max=getLeftMax(height);
        vector<int>right_max=getRightMax(height);
        int sum=0;
        for(int i=0;i<height.size();i++){
          // int width=1; doesnt effect
          int h=min(left_max[i],right_max[i])-height[i];
          sum+=h;
        }
        return sum;

    }
};