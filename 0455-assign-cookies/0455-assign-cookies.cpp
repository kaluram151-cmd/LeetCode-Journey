class Solution {
public:
    int findContentChildren(vector<int>& child, vector<int>& cookies) {
        int l = 0;
        int r = 0;
        sort(child.begin(),child.end());
        sort(cookies.begin(),cookies.end());
        int n = cookies.size();
        int m = child.size();
        while(l<n && r<m)
        {
            if(child[r]<=cookies[l])
            {
                l++;
                r++;
            }
            else
            {
                l++;
            }
        }
        return r;
    }
};