class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int buy = nums[0];
        int sell = nums[0];
        int n = nums.size();
        int ans = INT_MIN;
        for(int i = 0;i<n;i++)
        {
            if(buy>nums[i])
            {
                buy = nums[i];
            }
            else
            {
                ans = max(ans,nums[i]-buy);
            }
        }
        return ans;
    }
};