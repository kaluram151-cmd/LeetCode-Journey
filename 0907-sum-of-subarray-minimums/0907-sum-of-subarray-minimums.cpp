class Solution {
public:
    vector<int> NGE(vector<int>& arr)
    {
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n,n);
        for(int i = n-1;i>=0;i--)
        {
            while(!st.empty() && arr[i] <= arr[st.top()])
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
    vector<int> PSEE(vector<int>& arr)
    {
        int  n = arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
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
        vector<int> nse = NGE(arr);
        vector<int> psee = PSEE(arr);
        int mod = 1e9 + 7;
        int total = 0;
        for(int i = 0;i<arr.size();i++)
        {
            int left = i-psee[i];
            int right = nse[i] - i;
            long long x = (1LL*left*right)%mod;
            long long y = (x*arr[i])%mod;
            total = (total+y)%mod;
        }
        return total;
    }
};