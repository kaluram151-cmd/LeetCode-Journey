class Solution {
public:
    int mod = 1e9+7;
    vector<int> nsee(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> ans(n,n);
        stack<int>st;
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
            else
            {
                
            }
            st.push(i);
        }
        
        return ans;
    }
    vector<int> psee(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> ans(n,-1);
        stack<int>st;
        for(int i = 0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
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
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = nsee(arr);
        vector<int> pse = psee(arr);
        long long ans = 0;
        for(int i = 0;i<arr.size();i++)
        {
            long long x = 1LL*(nse[i]-i);
            long long y = 1LL*(i-pse[i]);
            ans = (ans+(x*y*arr[i])%mod)%mod;
        }
        return ans;
    }
};