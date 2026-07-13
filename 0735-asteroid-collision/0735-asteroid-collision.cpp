class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        for(int i = 0;i<n;i++)
        {
            if(arr[i]>0 || st.empty() || st.top()<0)
            {
                st.push(arr[i]);
            }
            else
            {
                while(!st.empty() && st.top()>0 && (st.top() < (-arr[i])))
                {
                    st.pop();
                }
                if( !st.empty() && st.top() == (-arr[i]))
                {
                    st.pop();
                    continue;
                }
                if(st.empty() || st.top()<0)
                {
                    st.push(arr[i]);
                }
            }
        }
        vector<int> ans(st.size(),0);
        for(int i = st.size()-1;i>=0;i--)
        {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};