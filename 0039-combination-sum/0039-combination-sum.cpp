class Solution {
public:
    void helper(vector<int>& nums,int idx,int target, vector<int>& combin , vector<vector<int>>& ans)
    {
        if(target==0)
        {
            ans.push_back(combin);
            //s.insert(combin);
            return ;
        }
        if( target<0 || idx==nums.size())
        {
            return ;
        }
        combin.push_back(nums[idx]);
        helper(nums,idx,target-nums[idx],combin,ans);
        combin.pop_back();
        helper(nums,idx+1,target,combin,ans);
        return ;

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
       vector<int> combin;
       vector<vector<int>> ans;
       helper(nums, 0, target, combin, ans);
       return ans;
    }
};