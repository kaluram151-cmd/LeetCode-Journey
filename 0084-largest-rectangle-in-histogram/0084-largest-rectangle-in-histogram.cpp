class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        int maxArea = 0;
        for(int i = 0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                int element = st.top();
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, (i-pse-1)*arr[element]);
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int element = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (n-pse-1)*arr[element]);
        }
        return maxArea;
    }
};