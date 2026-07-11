class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        int n = num.size();
        int i = 0;
        stack<char> st;
        while(i<n)
        {
            if(k==0)
            {
                while(i<n)
                {
                    st.push(num[i]);
                    i++;
                }
                break;
            }
            else
            {
                while( k>0 && !st.empty() && st.top()> num[i] )
                {
                    st.pop();
                    k--;
                }
                st.push(num[i]);
                i++;
            }
        }
        while(k>0 && !st.empty())
        {
            st.pop();
            k--;
        }
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        while(ans[0]=='0')
        {
            ans.erase(ans.begin(),ans.begin()+1);
        }
        if(ans.size()==0)
        {
            return "0";
        }
        return ans;
    }
};