class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        int i = 0;
        int n = intervals.size();
        while(i<n)
        {
            int res0 = intervals[i][0];
            int res1 = intervals[i][1];
            i++;
            while(i<n && intervals[i][0]<=res1)
            {
                res1 = max(res1,intervals[i][1]);
                i++;
            }
            res.push_back({res0,res1});            
        }
        return res;
    }
};