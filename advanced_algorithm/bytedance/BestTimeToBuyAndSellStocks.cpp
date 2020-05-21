class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int size = prices.size();
      if (size <= 1) {
        return 0;
      }
      
      int min_val = INT_MAX;
      int diff = 0;
      for (int iter = 0; iter < prices.size(); ++iter) {
        int value = prices[iter];
        min_val = min(min_val, value);  
        if (iter) {
          diff = max(diff, value - min_val);
        }
      }
      return diff;
    }
};
