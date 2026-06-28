class Solution {
public:
    void helper(int i, int k, int n, vector<int>& combine, vector<vector<int>>& ans)
    {
        if(k==0)
        {
            if(n==0)
            {
                ans.push_back(combine);
            }
            return ;
        }
        if(i>9 || n<0)
        {
            return ;
        }
        combine.push_back(i);
        helper(i+1, k-1, n-i, combine, ans);
        combine.pop_back();
        helper(i+1, k, n, combine, ans);
        return ;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combine;
        vector<vector<int>> ans;
        helper(1, k, n, combine, ans);
        return ans;
    }
};