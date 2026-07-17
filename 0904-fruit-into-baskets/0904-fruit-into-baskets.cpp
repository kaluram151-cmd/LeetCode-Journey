class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int maxlen = 0;
        unordered_map<int,int> mp;
        int k = 2;
        while(r<n)
        {
            if(mp.find(nums[r])!=mp.end())
            {
                mp[nums[r]]++;
            }
            else
            {
                mp[nums[r]] = 1;
            }
            if(mp.size()>k)
            {
                while(mp.size()>k)
                {
                    mp[nums[l]]--;
                    if(mp[nums[l]]==0)
                    {
                        mp.erase(nums[l]);
                    }
                    l++;
                }
            }
            if(mp.size()<=k)
            {
                maxlen = max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};