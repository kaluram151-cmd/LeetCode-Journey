class Solution {
public:
    bool isValid(string& s) {
        if(s.size()%2!=0)
        {
            return false;
        }
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
                continue;
            }
            if(st.size()!=0)
            {
                if((s[i]==')' && st.top()=='(') || (s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='[') )
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
                
            }
            else
            {
                return false;
            }
        }
        if(st.size()!=0)
        {
            return false;
        }
        return true;
    }
};