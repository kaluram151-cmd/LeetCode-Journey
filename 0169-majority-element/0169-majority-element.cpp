class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++)
        {
            if(mp[nums[i]]>=nums.size()/2)
            {
                return nums[i];
            }
            if(mp.find(nums[i])!=mp.end())
            {
                mp[nums[i]]++;
            }
            else
            {
                mp[nums[i]] = 1;
            }
        }
        return -1;
    }
};