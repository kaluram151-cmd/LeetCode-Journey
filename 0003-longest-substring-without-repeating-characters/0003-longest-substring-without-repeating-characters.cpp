class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        for(int i = 0;i<s.length();i++)
        {
            unordered_map<int,int> mp;
            for(int j = i;j<s.length();j++)
            {
                if(mp[s[j]]==1)
                {
                    break;
                }
                int length = j+1-i;
                maxlen = max(maxlen,length);
                mp[s[j]] = 1;
            }
        }
        return maxlen;
    }
};