class Solution {
public:
    void prevSmallerElement(vector<int> &heights,vector<int> &prev){
        stack<int> st;
        st.push(-1);
         
        for(int i=0;i<heights.size();i++){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            prev.push_back(st.top());
            st.push(i);

        }
         
    }
     void nextSmallerElement(vector<int> &heights,vector<int> &next){
        stack<int> st;
        st.push(heights.size());
        
        for(int i=heights.size()-1;i>=0;i--){
            while(st.top()!=heights.size()&& heights[st.top()]>=heights[i]){
                st.pop();
            }
            next.push_back(st.top());
            st.push(i);

        }
        
    }
    int largestRectangleArea(vector<int>& heights) {
        int area=0;
        vector<int> prev;
        prevSmallerElement(heights,prev);
        vector<int> next;
        
        nextSmallerElement(heights,next);
        reverse(next.begin(),next.end());
        // for(int i=0;i<prev.size();i++){
        //     cout<<prev[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<next.size();i++){
        //     cout<<next[i]<<" ";
        // }
        // cout<<endl;
        // cout<<endl;
        // cout<<prev.size()<<" "<<next.size()<<endl;

     

    for(int i=0;i<heights.size();i++){
        int length=heights[i];
        int width=next[i]-prev[i]-1;
        // cout<<width<<" ";
        // cout<<endl;
        // cout<<endl;
        int curr_area=length*width;
        // cout<<curr_area<<" "<<i<<endl;
        area=max(area,curr_area);
    }

        return area;
    }
};