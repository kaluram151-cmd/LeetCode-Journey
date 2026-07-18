class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int n = s.length();
        int l = 0;
        int r = 0;
        vector<int> hash(3,0);
        while(r<n)
        {
            hash[s[r]-'a']++;
            while(hash[0]!=0 && hash[1]!=0 && hash[2]!=0)
            {
                count = count+(n-r);
                hash[s[l]-'a']--;
                if(l<r)
                {
                    l++;
                }
                else
                {
                    break;
                }
            }
            r++;
        }
        return count;
    }
};