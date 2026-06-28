class Solution {
public:
    void helper(vector<int>& nums, int j , vector<int>& ans, vector<vector<int>>& subset)
    {
        if(j==nums.size())
        {
            subset.push_back({ans});
            return ;
        }
        ans.push_back(nums[j]);
        helper(nums,j+1,ans,subset);

        ans.pop_back();
        while((j<nums.size()-1) && (nums[j]==nums[j+1]))
        {
            j++;
        }
        helper(nums,j+1,ans,subset);
        return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> subset;
        vector<int> ans;
        helper(nums,0,ans,subset);
        return subset;
    }
};