class Solution {
public:
    void helper(vector<int>& nums,int idx, int target, vector<int>& combine, vector<vector<int>>& ans)
    {
        if(target==0)
        {
            ans.push_back(combine);
            return ;
        }
        if(target<0 || idx==nums.size() )
        {
            return ;
        }
        combine.push_back(nums[idx]);
        helper(nums, idx+1,target-nums[idx], combine, ans);
        combine.pop_back();
        while(idx<nums.size()-1 && nums[idx]==nums[idx+1])
        {
            idx++;
        }
        helper(nums, idx+1, target, combine, ans);
        return ;
    }
    vector<vector<int>> combinationSum2(vector<int>&  nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> combine;
        vector<vector<int>> ans;
        helper(nums, 0, target, combine, ans);
        return ans;
    }
};