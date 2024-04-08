class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        stack<int> st;
        
        for(int i=0;i<students.size();i++)
        {
            q.push(students[i]);
        }
        for(int i=sandwiches.size()-1;i>=0;i--)
        {
            st.push(sandwiches[i]);
            
        }
        int counter=0;
        while(!q.empty()&&counter<q.size())
        {
            if(q.front()==st.top())
            {
                q.pop();
                st.pop();
                counter=0;
            }
            else
            {
                int temp=q.front();
                q.push(temp);
                q.pop();
                counter++;
            }
        }
        return q.size();

    }
};