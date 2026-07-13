int speedup = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int mod = 1e9+7;
    vector<int> nsee(vector<int>& arr)
    {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n,n);
        for(int i = n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
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
    vector<int> psee(vector<int>& arr)
    {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n,-1);
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
        int n = arr.size();
        vector<int> pse = psee(arr);
        vector<int> nse = nsee(arr);
        int sum = 0;
        for(int i = 0;i<n;i++)
        {
            long long x = 1LL*(nse[i]-i);
            long long y = 1LL*(i-pse[i]);
            sum = (sum+((x*y*arr[i]))%mod)%mod;
        }
        return sum;
    }
};