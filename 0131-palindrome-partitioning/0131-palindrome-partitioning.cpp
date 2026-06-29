class Solution {
public:
    bool isPalindrome(string s)
    {
        string s2 = s;
        reverse(s.begin(),s.end());
        return s2==s;
    }
    void helper(string s, vector<string>& combine, vector<vector<string>>& ans)
    {
        if(s.size()==0)
        {
            ans.push_back(combine);
            return ;
        }
        for(int i = 0;i<s.size();i++)
        {
            string s2 = s.substr(0,i+1);
            if(isPalindrome(s2))
            {
                combine.push_back(s2);
                helper(s.substr(i+1),combine,ans);
                combine.pop_back();
            }
        }
        return ;
    }
    vector<vector<string>> partition(string s) {
        vector<string> combine;
        vector<vector<string>> ans;
        helper(s, combine, ans);
        return ans;
    }
};