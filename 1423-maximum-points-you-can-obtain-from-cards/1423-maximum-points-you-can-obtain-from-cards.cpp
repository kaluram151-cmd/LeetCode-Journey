class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      int l = 0;
      int r = cardPoints.size()-1;
      int lsum = 0;
      int rsum = 0;
      for( l = 0;l<k;l++)
      {
            lsum += cardPoints[l];
      }
      int sum = lsum+rsum;
      int ans = sum;
      l = l-1;
      while(l!=-1)
      {
            lsum -= cardPoints[l];
            rsum += cardPoints[r];
            sum = lsum+rsum;
            ans = max(ans,sum);
            l--;
            r--;
      }  
      return ans;
    }
};