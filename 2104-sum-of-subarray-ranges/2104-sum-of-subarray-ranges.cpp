class Solution {
public:
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
    long long minsum(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse = psee(arr);
        vector<int> nse = nsee(arr);
        long long sum = 0;
        for(int i = 0;i<n;i++)
        {
            long long x = 1LL*(nse[i]-i);
            long long y = 1LL*(i-pse[i]);
            sum = (sum+((x*y*arr[i])));
        }
        return sum;
    }
    vector<int> nmee(vector<int>& arr)
    {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n,n);
        for(int i = n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]<=arr[i])
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
    vector<int> pmee(vector<int>& arr)
    {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i = 0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()] < arr[i])
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
    long long maxsum(vector<int>& arr) {
        int n = arr.size();
        vector<int> pme = pmee(arr);
        vector<int> nme = nmee(arr);
        long long sum = 0;
        for(int i = 0;i<n;i++)
        {
            long long x = 1LL*(nme[i]-i);
            long long y = 1LL*(i-pme[i]);
            sum = (sum+((x*y*arr[i])));
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long  maximum = maxsum(nums);
        long long minmum = minsum(nums);
        return maximum-minmum;
    }
};