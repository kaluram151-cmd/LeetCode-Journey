class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIn = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            if(i>maxIn)
            {
                return false;
            }
            maxIn = max(maxIn,i+nums[i]);
        }
        return maxIn>=n-1;
    }
};