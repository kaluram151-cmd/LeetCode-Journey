class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int freq = 1;
        int n = nums.size();
        return nums[n/2];
    }
};