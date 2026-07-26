class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        int n = intervals.size();
        res.push_back({intervals[0][0],intervals[0][1]});
        for(int i = 1;i<n;i++)
        {
            if(res.back()[1]<intervals[i][0])
            {
                res.push_back({intervals[i][0],intervals[i][1]});
            }
            else
            {
                res.back()[1] = max(res.back()[1],intervals[i][1]);
            }
        }
        return res;
    }
};