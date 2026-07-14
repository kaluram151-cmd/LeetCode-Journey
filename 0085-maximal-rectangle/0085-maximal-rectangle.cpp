class Solution {
public:
    int maxArea(vector<int>& arr)
    {
        int n = arr.size();
        int maxarea = 0;
        stack<int> st;
        for(int i = 0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                int element = st.top();
                st.pop();
                int pse = st.empty() ? -1:st.top();
                maxarea = max(maxarea, (i-pse-1)*arr[element]);
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int element = st.top();
            st.pop();
            int pse = st.empty() ? -1:st.top();
            maxarea = max(maxarea, (n-pse-1)*arr[element]);
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
        vector<int> arr(n,0);
        int maxarea = 0;
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix[i].size();j++)
            {
               if(matrix[i][j]=='0')
               {
                    arr[j] = 0;
               }
               else
               {
                    arr[j]++;
               }
            }
            maxarea = max(maxarea,maxArea(arr));
        }
        return maxarea;
    }
};