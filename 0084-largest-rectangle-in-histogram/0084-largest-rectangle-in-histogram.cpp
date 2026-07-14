
class Solution {
public:
    vector<int> psee(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i = 0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> nsee(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> ans(n,n);
        stack<int> st;
        for(int i = n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& arr) {
        vector<int> pse = psee(arr);
        vector<int> nse = nsee(arr);
        int n = arr.size();
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            int y = nse[i]-pse[i]-1;
            ans = max(ans,y*arr[i]);
        }
        return ans;
    }
};