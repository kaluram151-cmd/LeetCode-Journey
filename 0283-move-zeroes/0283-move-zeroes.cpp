class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int end = nums.size()-1;
        int idx = 0;
        vector<int> ans(nums.size(),0);
        for(int i = 0;i<=end;i++)
        {
            if(nums[i]!=0)
            {
                ans[idx++] = nums[i];
            }
        }
        for(int i = 0;i<=end;i++)
        {
            nums[i] = ans[i];
        }
        return ;
    }
};