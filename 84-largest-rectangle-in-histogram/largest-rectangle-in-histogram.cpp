class Solution {
public:
    
    vector<int> nextSmallerElement(vector<int> &arr){
        int n = arr.size();
        vector<int>ans(n);
        stack<int>st;
        st.push(-1);
        for(int i = 0;i<n;i++){
            while(st.top()!= -1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> &arr){
        int n = arr.size();
        vector<int>ans(n);
        stack<int>st;
        st.push(n);
        for(int i = n-1;i>=0;i--){
            while(st.top()!= n && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> left = nextSmallerElement(heights);
        vector<int> right = prevSmallerElement(heights);
        int n = heights.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            // cout<<left[i]<<" "<<right[i]<<endl;;
            int k = right[i]-left[i]-1;
            // cout<<k*heights[i]<<endl;
            ans = max(ans,k*heights[i]); 
        }
        return ans;
        
    }
};