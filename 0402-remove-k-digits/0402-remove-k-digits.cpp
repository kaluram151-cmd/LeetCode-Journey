class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string ans = "";
        for(int i = 0;i<num.length();i++)
        {
            if(k==0)
            {
                for(int j = i;j<num.length();j++)
                {
                    st.push(num[j]);
                }
                break;
            }
            while(!st.empty() && k>0 &&num[i]<st.top())
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        if(ans.empty())
        {
            ans = "0";
        }
        reverse(ans.begin(),ans.end());
        while(ans.size() > 1 && ans[0] == '0')
        {
            ans.erase(ans.begin());
        }
        return ans;
    }
};