class Solution {
public:
    vector<int> pref(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> prefix(n,0);
        prefix[0] = arr[0];
        for(int i = 1;i<n;i++)
        {
            prefix[i] = max(prefix[i-1],arr[i]);
        }
        return prefix;
    }
    vector<int> suff(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> suffix(n,0);
        suffix[n-1] = arr[n-1];
        for(int i = n-2;i>=0;i--)
        {
            suffix[i] = max(suffix[i+1],arr[i]);
        }
        return suffix;
    }
    int trap(vector<int>& arr) {
        vector<int> prefix = pref(arr);
        vector<int> suffix = suff(arr);
        int n = arr.size();
        int total = 0;
        for(int i = 0;i<n;i++)
        {
            if(arr[i]<suffix[i] && arr[i]<prefix[i])
            {
                total += (min(prefix[i],suffix[i])-arr[i]);
            }
        }
        return total;
    }
};