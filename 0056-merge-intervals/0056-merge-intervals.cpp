class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        for(auto& val:intervals)
        {
            if(res.empty() || res.back()[1]<val[0])
            {
                res.push_back({val[0],val[1]});
            }
            else
            {
                res.back()[1] = max(res.back()[1],val[1]);
            }
        }
        return res;
    }
};