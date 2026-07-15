class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int hashlen = 256;
        int hash[hashlen];
        for(int i = 0;i<hashlen;i++)
        {
            hash[i] = -1;
        }
        int l = 0;
        int r = 0;
        int maxlen = 0;
        while(r<n)
        {
            if(hash[s[r]]!=-1)
            {
                int x = l;
                if(hash[s[r]]<=r)
                {
                 l = hash[s[r]]+1;
                }
                while(x<l)
                {
                    hash[s[x]] = -1;
                    x++;
                }
            }
            hash[s[r]] = r;
            int len = r-l+1;
            maxlen = max(maxlen,len);
            r++;
        }
        return maxlen;
    }
};