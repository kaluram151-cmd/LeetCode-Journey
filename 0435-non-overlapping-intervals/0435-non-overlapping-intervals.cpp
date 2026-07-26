static bool comp(vector<int>& a,vector<int>& b)
{
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int n = intervals.size();
        int res0 = intervals[0][0];
        int res1 = intervals[0][1];
        int ans = 0;
        for(int i = 1;i<n;i++)
        {
            if(intervals[i][0]>=res1)
            {
                res0 = intervals[i][0];
                res1 = intervals[i][1];
            }
            else
            {
                ans++;
            }
        }
        return ans;
    }
};