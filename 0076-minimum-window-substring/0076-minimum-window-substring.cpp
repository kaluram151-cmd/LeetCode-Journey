class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256,0);
        for(int i = 0;i<t.length();i++)
        {
            hash[t[i]]++;
        }
        int l = 0;
        int r = 0;
        int m = t.length();
        int sIndex = -1;
        int count = 0;
        int n = s.length();
        int minlen = INT_MAX;
        while(r<n)
        {
            if(hash[s[r]]>0)
            {
                count = count+1;
            }
            hash[s[r]]--;
            while(count==m)
            {
                if(r-l+1<minlen)
                {
                    minlen = r-l+1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0)
                {
                    count = count-1;
                }
                l++;
            }
            r++;
        }
        return sIndex==-1?"":s.substr(sIndex,minlen);
    }
};