class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0;
        int neg = 1;
        vector<int> ans(nums.size(),0);
        for(int x:nums)
        {
            if(x>=0)
            {
                if(pos<nums.size())
                {
                    ans[pos] = x;
                    pos +=2;
                }
            }
            else
            {
                if(neg<nums.size())
                {
                    ans[neg] = x;
                    neg += 2;
                }
            }
        }
        return ans;
    }
};